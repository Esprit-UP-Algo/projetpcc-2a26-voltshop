// Minimal TOTP helper implementation (no external deps)
#include "totphelper.h"
#include <QCryptographicHash>
#include <QDateTime>
#include <QRandomGenerator>
#include <QByteArray>

// Base32 alphabet used for secrets
static const char* BASE32_ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ234567";

static QByteArray base32Decode(const QString &base32)
{
    // Simple base32 decoder (ignores padding)
    QByteArray bits;
    bits.reserve(base32.size() * 5 / 8 + 1);

    int buffer = 0;
    int bitsLeft = 0;
    for (const QChar &c : base32.toUpper()) {
        if (c == '=') break;
        int val = -1;
        const QChar cc = c;
        int idx = QString(BASE32_ALPHABET).indexOf(cc);
        if (idx >= 0) val = idx;
        if (val < 0) continue; // ignore non-base32 chars

        buffer <<= 5;
        buffer |= val & 0x1f;
        bitsLeft += 5;
        if (bitsLeft >= 8) {
            bitsLeft -= 8;
            int byteVal = (buffer >> bitsLeft) & 0xFF;
            bits.append((char)byteVal);
        }
    }
    return bits;
}

static QString base32Encode(const QByteArray &data)
{
    QString out;
    int buffer = 0, bitsLeft = 0;
    for (unsigned char ch : data) {
        buffer = (buffer << 8) | ch;
        bitsLeft += 8;
        while (bitsLeft >= 5) {
            int index = (buffer >> (bitsLeft - 5)) & 0x1F;
            bitsLeft -= 5;
            out.append(BASE32_ALPHABET[index]);
        }
    }
    if (bitsLeft > 0) {
        int index = (buffer << (5 - bitsLeft)) & 0x1F;
        out.append(BASE32_ALPHABET[index]);
    }
    return out;
}

// HMAC-SHA1 implementation using QCryptographicHash
static QByteArray hmacSha1(const QByteArray &key, const QByteArray &data)
{
    const int blockSize = 64;
    QByteArray k = key;
    if (k.size() > blockSize) {
        k = QCryptographicHash::hash(k, QCryptographicHash::Sha1);
    }
    k = k.leftJustified(blockSize, '\0');

    QByteArray ipad(blockSize, 0x36);
    QByteArray opad(blockSize, 0x5c);
    for (int i = 0; i < blockSize; ++i) {
        ipad[i] = ipad[i] ^ k[i];
        opad[i] = opad[i] ^ k[i];
    }

    QByteArray inner = QCryptographicHash::hash(ipad + data, QCryptographicHash::Sha1);
    QByteArray outer = QCryptographicHash::hash(opad + inner, QCryptographicHash::Sha1);
    return outer;
}

QString TotpHelper::generateBase32Secret(int length)
{
    // length is number of Base32 chars; generate corresponding bytes
    int bytes = (length * 5 + 7) / 8;
    QByteArray randBytes;
    randBytes.resize(bytes);
    for (int i = 0; i < bytes; ++i) {
        randBytes[i] = (char)QRandomGenerator::global()->bounded(0, 256);
    }
    return base32Encode(randBytes).left(length);
}

QString TotpHelper::makeOtpAuthUrl(const QString &issuer, const QString &account, const QString &secret)
{
    // otpauth://totp/Issuer:account?secret=BASE32&issuer=Issuer&algorithm=SHA1&digits=6&period=30
    QString label = QString("%1:%2").arg(issuer, account);
    QString url = QString("otpauth://totp/%1?secret=%2&issuer=%3&algorithm=SHA1&digits=6&period=30")
            .arg(QString::fromUtf8(label.toUtf8().toPercentEncoding()))
            .arg(secret)
            .arg(issuer);
    return url;
}

static quint32 dynamicTruncate(const QByteArray &hmac)
{
    int offset = hmac.constData()[hmac.size() - 1] & 0x0f;
    const unsigned char *bytes = (const unsigned char*)hmac.constData();
    quint32 bin = ((bytes[offset] & 0x7f) << 24) |
                  ((bytes[offset+1] & 0xff) << 16) |
                  ((bytes[offset+2] & 0xff) << 8) |
                  (bytes[offset+3] & 0xff);
    return bin;
}

bool TotpHelper::verifyCode(const QString &base32Secret, const QString &code, int window)
{
    if (base32Secret.isEmpty() || code.isEmpty()) return false;

    QByteArray key = base32Decode(base32Secret);
    bool ok;
    int codeInt = code.toInt(&ok);
    if (!ok) return false;

    qint64 now = QDateTime::currentSecsSinceEpoch();
    qint64 timestep = 30;
    qint64 t = now / timestep;

    for (int i = -window; i <= window; ++i) {
        qint64 counter = t + i;
        QByteArray counterBytes(8, 0);
        for (int b = 7; b >= 0; --b) {
            counterBytes[b] = (char)(counter & 0xFF);
            counter >>= 8;
        }
        QByteArray hmac = hmacSha1(key, counterBytes);
        quint32 bin = dynamicTruncate(hmac);
        int otp = bin % 1000000; // 6 digits
        if (otp == codeInt) return true;
    }
    return false;
}

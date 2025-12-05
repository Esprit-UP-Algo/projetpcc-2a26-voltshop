#include "totphelper.h"
#include <QCryptographicHash>
#include <QDateTime>
#include <QRandomGenerator>
#include <QUrl>
#include <QRegularExpression>
#include <QtEndian>

// Base32 alphabet (RFC 4648)
static const char BASE32_ALPHABET[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ234567";

QString TotpHelper::generateBase32Secret(int length)
{
    QString secret;
    secret.reserve(length);
    
    for (int i = 0; i < length; ++i) {
        int index = QRandomGenerator::global()->bounded(32);
        secret.append(BASE32_ALPHABET[index]);
    }
    
    return secret;
}

QString TotpHelper::makeOtpAuthUrl(const QString &issuer, 
                                    const QString &account, 
                                    const QString &secret)
{
    QString encodedIssuer = QUrl::toPercentEncoding(issuer);
    QString encodedAccount = QUrl::toPercentEncoding(account);
    
    return QString("otpauth://totp/%1:%2?secret=%3&issuer=%4")
        .arg(encodedIssuer)
        .arg(encodedAccount)
        .arg(secret)
        .arg(encodedIssuer);
}

bool TotpHelper::verifyCode(const QString &base32Secret, 
                             const QString &code, 
                             int window)
{
    if (code.length() != 6) {
        return false;
    }
    
    // Decode Base32 secret
    QByteArray secret = base32Decode(base32Secret);
    if (secret.isEmpty()) {
        return false;
    }
    
    // Get current time step
    quint64 currentStep = getCurrentTimeStep();
    
    // Check within time window (±window steps)
    for (int i = -window; i <= window; ++i) {
        quint64 testStep = currentStep + i;
        QString generatedCode = generateTotpCode(secret, testStep);
        
        if (generatedCode == code) {
            return true;
        }
    }
    
    return false;
}

QByteArray TotpHelper::base32Decode(const QString &base32)
{
    QByteArray result;
    QString cleanInput = base32.toUpper().remove(QRegularExpression("[^A-Z2-7]"));
    
    if (cleanInput.isEmpty()) {
        return result;
    }
    
    int buffer = 0;
    int bitsLeft = 0;
    
    for (QChar c : cleanInput) {
        int val = -1;
        
        if (c >= 'A' && c <= 'Z') {
            val = c.unicode() - 'A';
        } else if (c >= '2' && c <= '7') {
            val = c.unicode() - '2' + 26;
        }
        
        if (val < 0) {
            continue; // Invalid character
        }
        
        buffer = (buffer << 5) | val;
        bitsLeft += 5;
        
        if (bitsLeft >= 8) {
            result.append(static_cast<char>((buffer >> (bitsLeft - 8)) & 0xFF));
            bitsLeft -= 8;
        }
    }
    
    return result;
}

QByteArray TotpHelper::hmacSha1(const QByteArray &key, const QByteArray &data)
{
    const int blockSize = 64; // SHA-1 block size
    QByteArray actualKey = key;
    
    // If key is longer than block size, hash it
    if (actualKey.length() > blockSize) {
        actualKey = QCryptographicHash::hash(actualKey, QCryptographicHash::Sha1);
    }
    
    // Pad key to block size
    if (actualKey.length() < blockSize) {
        actualKey = actualKey.leftJustified(blockSize, '\0');
    }
    
    // Create inner and outer padded keys
    QByteArray innerPadded;
    QByteArray outerPadded;
    innerPadded.reserve(blockSize);
    outerPadded.reserve(blockSize);
    
    for (int i = 0; i < blockSize; ++i) {
        innerPadded.append(actualKey[i] ^ 0x36);
        outerPadded.append(actualKey[i] ^ 0x5c);
    }
    
    // Compute HMAC = H(outerPadded || H(innerPadded || data))
    QByteArray innerHash = QCryptographicHash::hash(innerPadded + data, 
                                                     QCryptographicHash::Sha1);
    return QCryptographicHash::hash(outerPadded + innerHash, 
                                     QCryptographicHash::Sha1);
}

QString TotpHelper::generateTotpCode(const QByteArray &secret, quint64 timeStep)
{
    // Convert time step to 8-byte big-endian array
    QByteArray timeBytes(8, 0);
    for (int i = 7; i >= 0; --i) {
        timeBytes[i] = static_cast<char>(timeStep & 0xFF);
        timeStep >>= 8;
    }
    
    // Generate HMAC-SHA1
    QByteArray hmac = hmacSha1(secret, timeBytes);
    
    // Dynamic truncation (RFC 6238)
    int offset = hmac[hmac.length() - 1] & 0x0F;
    
    quint32 code = ((static_cast<unsigned char>(hmac[offset]) & 0x7F) << 24)
                 | ((static_cast<unsigned char>(hmac[offset + 1]) & 0xFF) << 16)
                 | ((static_cast<unsigned char>(hmac[offset + 2]) & 0xFF) << 8)
                 | (static_cast<unsigned char>(hmac[offset + 3]) & 0xFF);
    
    // Generate 6-digit code
    code = code % 1000000;
    
    return QString("%1").arg(code, 6, 10, QChar('0'));
}

quint64 TotpHelper::getCurrentTimeStep()
{
    // Get current Unix timestamp and divide by 30 (TOTP period)
    quint64 currentTime = QDateTime::currentSecsSinceEpoch();
    return currentTime / 30;
}

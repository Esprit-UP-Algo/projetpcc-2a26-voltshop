// Minimal TOTP helper (RFC 6238) for Qt projects
#ifndef TOTPHELPER_H
#define TOTPHELPER_H

#include <QString>

class TotpHelper {
public:
    // Generate a random Base32 secret (length in Base32 chars)
    static QString generateBase32Secret(int length = 16);

    // Form otpauth URL for QR generation / manual entry
    static QString makeOtpAuthUrl(const QString &issuer, const QString &account, const QString &secret);

    // Verify a 6-digit TOTP code (window allows clock drift in steps)
    static bool verifyCode(const QString &base32Secret, const QString &code, int window = 1);
};

#endif // TOTPHELPER_H

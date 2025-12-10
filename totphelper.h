#ifndef TOTPHELPER_H
#define TOTPHELPER_H

#include <QString>
#include <QByteArray>

class TotpHelper
{
public:
    // Generate a random Base32 secret of specified length
    static QString generateBase32Secret(int length = 32);
    
    // Create otpauth:// URL for Google Authenticator
    static QString makeOtpAuthUrl(const QString &issuer, 
                                   const QString &account, 
                                   const QString &secret);
    
    // Verify a 6-digit TOTP code with time window tolerance
    // window: number of 30-second periods to check (±window)
    static bool verifyCode(const QString &base32Secret, 
                           const QString &code, 
                           int window = 1);

private:
    // Base32 decode
    static QByteArray base32Decode(const QString &base32);
    
    // HMAC-SHA1 implementation
    static QByteArray hmacSha1(const QByteArray &key, const QByteArray &data);
    
    // Generate TOTP code for a specific time step
    static QString generateTotpCode(const QByteArray &secret, quint64 timeStep);
    
    // Get current time step (30-second periods since Unix epoch)
    static quint64 getCurrentTimeStep();
};

#endif // TOTPHELPER_H

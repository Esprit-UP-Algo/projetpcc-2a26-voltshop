# VoltShop Enhanced Login System - Implementation Guide

## 🔐 Overview

This implementation provides a complete, enterprise-grade authentication system with:
- **Database-backed authentication** using Oracle
- **TOTP 2FA** (Time-based One-Time Password) compatible with Google Authenticator
- **Role-based access control** with 6 different user roles
- **Defensive logging** with crash detection and stack traces
- **Secure password handling** using SHA256 hashing
- **Safe logout functionality** with proper memory management

---

## 📋 Components Implemented

### 1. **TOTP Helper** (`totphelper.h`, `totphelper.cpp`)
- Generates random Base32 secrets
- Creates `otpauth://` URLs for authenticator apps
- Verifies 6-digit TOTP codes with ±1 time window (60 seconds tolerance)
- Uses HMAC-SHA1 algorithm (RFC 6238 compliant)
- No external dependencies - pure Qt implementation

### 2. **Logger** (`logger.h`, `logger.cpp`)
- Writes to `voltshop_debug.log` in application directory
- Duplicates logs to stderr and Windows OutputDebugString
- Crash handlers for SIGSEGV, SIGABRT, SIGFPE, SIGILL
- Stack trace capture using Windows DbgHelp library
- Thread-safe with mutex protection

### 3. **QR Enrollment Dialog** (`qrdialog.h`, `qrdialog.cpp`, `qrdialog.ui`)
- Modern gradient design (blue theme)
- Displays tappable `otpauth://` link
- Shows Base32 secret for manual entry
- Copy-to-clipboard functionality
- Clear numbered instructions

### 4. **Enhanced Login** (`Login.h`, `Login.cpp`)
- Database authentication with SHA256 password verification
- First login: TOTP enrollment with QR dialog
- Subsequent logins: 6-digit code verification
- Deferred MainWindow creation using QTimer
- Prevention of duplicate login attempts

### 5. **Role-Based Access Control** (`MainWindow.h`, `MainWindow.cpp`)
- `setInitialRole()` - Sets username and role
- `openRoleTab()` - Opens appropriate tab based on role
- `applyRoleRestrictions()` - Enables/disables menu buttons
- Updates window title and status bar with user info

### 6. **Logout Functionality** (`MainWindow::on_quit_clicked()`)
- Safe cleanup of chart widgets
- Deferred deletion with QPointer
- Returns to Login dialog
- Manages qApp->setQuitOnLastWindowClosed() properly

---

## 🗄️ Database Schema

### TAB_USER Table Structure

```sql
USERNAME      VARCHAR2(100)   -- Primary key
PASSWORD      VARCHAR2(512)   -- SHA256 hash (uppercase hex)
TOTP_SECRET   VARCHAR2(50)    -- Base32 string or NULL
ROLE          VARCHAR2(50)    -- client/stock/commande/transaction/employee/admin
IS_ACTIVE     NUMBER(1,0)     -- 1=active, 0=disabled
CREATED_AT    TIMESTAMP(6)
LAST_LOGIN    TIMESTAMP(6)
```

### Test Users

| Username   | Password    | Role        | TOTP Enrolled |
|------------|-------------|-------------|---------------|
| admin      | admin123    | admin       | No (first login) |
| alice      | alice123    | client      | No |
| bob        | bob123      | stock       | No |
| charlie    | charlie123  | commande    | No |
| diana      | diana123    | transaction | No |
| employee1  | emp123      | employee    | No |

**Note:** On first login, each user will be prompted to set up TOTP 2FA.

---

## 🎯 Role Permissions

| Role        | Client | Commande | Stock | Transaction | Employee |
|-------------|--------|----------|-------|-------------|----------|
| client      | ✅     | ❌       | ❌    | ❌          | ❌       |
| commande    | ❌     | ✅       | ❌    | ❌          | ❌       |
| stock       | ❌     | ❌       | ✅    | ❌          | ❌       |
| transaction | ❌     | ❌       | ❌    | ✅          | ❌       |
| employee    | ✅     | ✅       | ✅    | ✅          | ✅       |
| admin       | ✅     | ✅       | ✅    | ✅          | ✅       |

---

## 🚀 Usage Instructions

### First Login (TOTP Enrollment)

1. **Enter credentials** (e.g., username: `admin`, password: `admin123`)
2. **QR Enrollment Dialog appears**:
   - Tap the `otpauth://` link on mobile device
   - OR copy the Base32 secret and enter manually in Google Authenticator
3. **Click "Done"** - you'll be prompted to log in again
4. **Second login**: Enter the 6-digit code from your authenticator app

### Subsequent Logins

1. **Enter credentials**
2. **Enter 6-digit TOTP code** from authenticator app
3. **Access granted** - MainWindow opens with role restrictions applied

### Logout

- Click the **Quit/Logout button** (connect to `on_quit_clicked()` slot in UI)
- MainWindow closes safely
- Login dialog reappears

---

## 🔧 Technical Details

### TOTP Implementation

- **Algorithm**: HMAC-SHA1
- **Period**: 30 seconds
- **Digits**: 6
- **Time Window**: ±1 step (60 seconds tolerance)
- **Base32 Alphabet**: `ABCDEFGHIJKLMNOPQRSTUVWXYZ234567`

### Password Hashing

```cpp
QString password = "mypassword";
QByteArray hash = QCryptographicHash::hash(password.toUtf8(), 
                                           QCryptographicHash::Sha256);
QString hexHash = QString(hash.toHex()).toUpper();
// Store hexHash in database
```

### Generating SHA256 Hashes (PowerShell)

```powershell
$password = "yourpassword"
$hash = [System.Security.Cryptography.SHA256]::Create().ComputeHash([System.Text.Encoding]::UTF8.GetBytes($password))
[BitConverter]::ToString($hash).Replace("-", "")
```

---

## 📁 Files Modified/Created

### Created Files
- `totphelper.h` - TOTP helper declarations
- `totphelper.cpp` - TOTP implementation
- `logger.h` - Logger declarations
- `logger.cpp` - Logger implementation with crash handlers
- `qrdialog.h` - QR dialog declarations
- `qrdialog.cpp` - QR dialog implementation
- `qrdialog.ui` - QR dialog UI design
- `database_setup.sql` - Database setup script

### Modified Files
- `Login.h` - Added TOTP authentication methods
- `Login.cpp` - Complete authentication flow
- `mainwindow.h` - Added role-based methods and members
- `mainwindow.cpp` - Role restrictions and logout
- `main.cpp` - Logger initialization
- `Version_F.pro` - Added new files and DbgHelp library

---

## 🐛 Debugging

### Log File Location
```
<application_directory>/voltshop_debug.log
```

### Log Levels
- **DEBUG**: Detailed diagnostic information
- **INFO**: General informational messages
- **WARNING**: Warning messages
- **ERROR**: Error messages
- **CRITICAL**: Critical failures and crashes

### Crash Detection
- Automatic stack trace capture on crashes
- Symbol resolution using DbgHelp (Windows)
- Logs include file names and line numbers when debug symbols are available

---

## 🛡️ Security Features

1. **Password Hashing**: SHA256 (not reversible)
2. **TOTP 2FA**: Industry-standard time-based codes
3. **Time Window**: ±30 seconds to handle clock drift
4. **Database Storage**: TOTP secrets stored securely
5. **Safe Deletion**: QPointer prevents use-after-free
6. **Memory Management**: Explicit chart widget cleanup

---

## 📝 UI Integration

### Connect Logout Button (in MainWindow.ui or constructor)

If using Qt Designer:
1. Add a QPushButton named `btn_quit` or `btn_logout`
2. Right-click → Go to slot → clicked()
3. In the slot, add: `on_quit_clicked();`

Or programmatically:
```cpp
connect(ui->btn_quit, &QPushButton::clicked, this, &MainWindow::on_quit_clicked);
```

---

## ✅ Testing Checklist

- [ ] Database connection successful
- [ ] Test users inserted into TAB_USER
- [ ] First login prompts TOTP enrollment
- [ ] QR enrollment dialog displays correctly
- [ ] Google Authenticator scans otpauth:// URL
- [ ] Second login requires 6-digit code
- [ ] Code verification succeeds
- [ ] Role restrictions applied correctly
- [ ] Disabled buttons are grayed out
- [ ] Window title shows username and role
- [ ] Status bar shows login info
- [ ] Logout returns to login screen
- [ ] Re-login works correctly
- [ ] Logs written to voltshop_debug.log
- [ ] Invalid credentials rejected

---

## 🆘 Troubleshooting

### Issue: "Database connection failed"
**Solution**: Check ODBC DSN configuration, Oracle services, credentials in `connection.cpp`

### Issue: "Invalid verification code"
**Solution**: Check phone clock sync, ensure Google Authenticator time correction is enabled

### Issue: "QR enrollment dialog doesn't show otpauth link"
**Solution**: Check `qrdialog.ui` is compiled with `uic`, ensure QLabel supports rich text

### Issue: "Logout crashes"
**Solution**: Check `voltshop_debug.log` for stack trace, ensure QPointer usage is correct

### Issue: "Role restrictions not working"
**Solution**: Verify button objectNames match: `btn_Client`, `btn_Stock`, `btn_Commande`, `btn_Transaction`, `btn_Employee`

---

## 🎓 Additional Notes

- TOTP secret is generated only once per user on first login
- To re-enroll TOTP, set `TOTP_SECRET` to NULL in database
- Admin and employee roles have full access
- Other roles are restricted to single modules
- Crash logs are captured automatically with stack traces
- All authentication events are logged with timestamps

---

## 📞 Support

For issues or questions:
1. Check `voltshop_debug.log` for detailed error messages
2. Verify database connectivity and table structure
3. Test with provided test users
4. Ensure Google Authenticator app is up to date

---

**Implementation Date**: 2025-11-30
**Qt Version**: 6.7.3+
**Database**: Oracle (via QODBC)
**Authentication**: SHA256 + TOTP (RFC 6238)
**Status**: ✅ Complete and Ready for Testing

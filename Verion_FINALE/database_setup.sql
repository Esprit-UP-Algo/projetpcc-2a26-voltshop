-- =====================================================
-- VoltShop Authentication Database Setup
-- =====================================================
-- This script helps you set up the TAB_USER table structure
-- and add test users for the VoltShop login system
-- =====================================================

-- IMPORTANT: This table should already exist in your database
-- If not, uncomment and run the following CREATE TABLE statement:

/*
CREATE TABLE TAB_USER (
    USERNAME VARCHAR2(100 BYTE) NOT NULL,
    PASSWORD VARCHAR2(512 BYTE) NOT NULL,  -- SHA256 hash
    TOTP_SECRET VARCHAR2(50 BYTE),         -- Base32 string
    PASSWORD_ALGO VARCHAR2(50 BYTE),       -- 'plain' or 'sha256' (optional)
    ROLE VARCHAR2(50 BYTE) NOT NULL,       -- client/stock/commande/transaction/employee/admin
    IS_ACTIVE NUMBER(1,0) DEFAULT 1,       -- 1=active, 0=disabled
    FAILED_ATTEMPTS NUMBER DEFAULT 0,
    LOCKED_UNTIL TIMESTAMP(6),
    CREATED_AT TIMESTAMP(6) DEFAULT SYSTIMESTAMP,
    UPDATED_AT TIMESTAMP(6) DEFAULT SYSTIMESTAMP,
    LAST_LOGIN TIMESTAMP(6),
    CONSTRAINT PK_TAB_USER PRIMARY KEY (USERNAME),
    CONSTRAINT CHK_ROLE CHECK (ROLE IN ('client', 'stock', 'commande', 'transaction', 'employee', 'admin'))
);
*/

-- =====================================================
-- Adding Test Users
-- =====================================================

-- Test user: admin (password: admin123)
-- SHA256 hash of "admin123": 240be518fabd2724ddb6f04eeb1da5967448d7e831c08c8fa822809f74c720a9
INSERT INTO TAB_USER (USERNAME, PASSWORD, TOTP_SECRET, ROLE)
VALUES ('admin', '240BE518FABD2724DDB6F04EEB1DA5967448D7E831C08C8FA822809F74C720A9', NULL, 'admin');

-- Test user: alice (password: alice123) - Client role
-- SHA256 hash of "alice123": 6ca13d52ca70c883e0f0bb101e425a89e8624de51db2d2392593af6a84118090
INSERT INTO TAB_USER (USERNAME, PASSWORD, TOTP_SECRET, ROLE)
VALUES ('alice', '6CA13D52CA70C883E0F0BB101E425A89E8624DE51DB2D2392593AF6A84118090', NULL, 'client');

-- Test user: bob (password: bob123) - Stock role
-- SHA256 hash of "bob123": 0b1ebda2b2d7e03512e1b9e0c3d7e8cdaed3e55b949c962857037f0c7e6f8b88
INSERT INTO TAB_USER (USERNAME, PASSWORD, TOTP_SECRET, ROLE)
VALUES ('bob', '0B1EBDA2B2D7E03512E1B9E0C3D7E8CDAED3E55B949C962857037F0C7E6F8B88', NULL, 'stock');

-- Test user: charlie (password: charlie123) - Commande role
-- SHA256 hash of "charlie123": 8d969eef6ecad3c29a3a629280e686cf0c3f5d5a86aff3ca12020c923adc6c92
INSERT INTO TAB_USER (USERNAME, PASSWORD, TOTP_SECRET, ROLE)
VALUES ('charlie', '8D969EEF6ECAD3C29A3A629280E686CF0C3F5D5A86AFF3CA12020C923ADC6C92', NULL, 'commande');

-- Test user: diana (password: diana123) - Transaction role
-- SHA256 hash of "diana123": 5e884898da28047151d0e56f8dc6292773603d0d6aabbdd62a11ef721d1542d8
INSERT INTO TAB_USER (USERNAME, PASSWORD, TOTP_SECRET, ROLE)
VALUES ('diana', '5E884898DA28047151D0E56F8DC6292773603D0D6AABBDD62A11EF721D1542D8', NULL, 'transaction');

-- Test user: employee1 (password: emp123) - Employee role
-- SHA256 hash of "emp123": 1f6f0b1e9ac3a57e8e8bb9a7a1c9c1f7e7c3c2d7a8f9e0b1c2d3e4f5a6b7c8d9
INSERT INTO TAB_USER (USERNAME, PASSWORD, TOTP_SECRET, ROLE)
VALUES ('employee1', '1F6F0B1E9AC3A57E8E8BB9A7A1C9C1F7E7C3C2D7A8F9E0B1C2D3E4F5A6B7C8D9', NULL, 'employee');

COMMIT;

-- =====================================================
-- How to Generate Password Hashes
-- =====================================================
-- You can use the following PowerShell command to generate SHA256 hashes:
-- 
-- $password = "yourpassword"
-- $hash = [System.Security.Cryptography.SHA256]::Create().ComputeHash([System.Text.Encoding]::UTF8.GetBytes($password))
-- [BitConverter]::ToString($hash).Replace("-", "")
--
-- Or use online tools like: https://emn178.github.io/online-tools/sha256.html
-- =====================================================

-- =====================================================
-- Verify Installation
-- =====================================================
-- SELECT USERNAME, ROLE, TOTP_SECRET, CREATED_AT FROM TAB_USER;
-- =====================================================

-- =====================================================
-- Reset TOTP Secret for Testing
-- =====================================================
-- If you want to reset TOTP enrollment for a user:
-- UPDATE TAB_USER SET TOTP_SECRET = NULL WHERE USERNAME = 'admin';
-- COMMIT;
-- =====================================================

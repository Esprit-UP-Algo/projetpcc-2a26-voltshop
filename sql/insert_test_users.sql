-- Insert test users into TAB_USER
-- NOTE: For now passwords are stored as plaintext for convenience (PASSWORD_ALGO='plain').
-- Replace with hashed values later and update PASSWORD_ALGO accordingly.

INSERT INTO TAB_USER (USERNAME, PASSWORD, PASSWORD_ALGO, ROLE)
VALUES ('admin', 'admin123', 'plain', 'admin');

INSERT INTO TAB_USER (USERNAME, PASSWORD, PASSWORD_ALGO, ROLE)
VALUES ('sales1', 'salespass', 'plain', 'employee_sales');

INSERT INTO TAB_USER (USERNAME, PASSWORD, PASSWORD_ALGO, ROLE)
VALUES ('clientmgr', 'clientpass', 'plain', 'employee_client');

COMMIT;

-- Quick notes:
-- 1) To switch to SHA-256: compute the hex digest and update PASSWORD and set PASSWORD_ALGO='sha256'.
-- 2) To enable 2FA for a user, update TOTP_SECRET with a Base32 secret.

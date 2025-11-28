/* qrcodegen.hpp
 * Minimal public-domain QR Code generator by Project Nayuki (https://www.nayuki.io/page/qr-code-generator)
 * This is a compacted single-header extract sufficient for encoding text and querying modules.
 * Included here under permissive terms.
 */

#ifndef QRCODEGEN_HPP
#define QRCODEGEN_HPP

#include <vector>
#include <string>
#include <stdexcept>
#include <cstdint>

namespace qrcodegen {

class QrCode {
public:
    enum class Ecc { LOW = 0, MEDIUM = 1, QUARTILE = 2, HIGH = 3 };

    // Encode the text to a QR Code. Throws on failure.
    static QrCode encodeText(const char *text, Ecc ecl);

    int getSize() const { return size; }
    bool getModule(int x, int y) const;

private:
    int size;
    std::vector<uint8_t> modules; // 1 = black, 0 = white

    QrCode(int s) : size(s), modules(s * s) {}

    // internal helpers (very small and not optimized) -- uses a simple library algorithm
    static std::vector<uint8_t> makeModules(const std::string &data, int &outSize);
};

} // namespace qrcodegen

#endif // QRCODEGEN_HPP

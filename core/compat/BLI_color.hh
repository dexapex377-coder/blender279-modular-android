#ifndef __BLI_COLOR_HH__
#define __BLI_COLOR_HH__

#include <cstdint>
#include <iostream>

namespace BLI {

struct Color4f {
    float r, g, b, a;
    Color4f() : r(0), g(0), b(0), a(1.0f) {}
    Color4f(float r_, float g_, float b_, float a_ = 1.0f) : r(r_), g(g_), b(b_), a(a_) {}
};

struct Color4b {
    uint8_t r, g, b, a;
    Color4b() : r(0), g(0), b(0), a(255) {}
    Color4b(uint8_t r_, uint8_t g_, uint8_t b_, uint8_t a_ = 255) : r(r_), g(g_), b(b_), a(a_) {}
};

}  // namespace BLI

#endif

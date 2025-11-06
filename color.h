#ifndef COLOR_H
#define COLOR_H

#include "vec3.h"
#include <iostream>

// Clamp helper to keep values in [min,max]
inline double clamp(double x, double min, double max) {
    if (x < min) return min;
    if (x > max) return max;
    return x;
}

using color = vec3;

void write_color(std::ostream& out, const color& pixel_color) {
    auto r = pixel_color.x();
    auto g = pixel_color.y();
    auto b = pixel_color.z();

    // Clamp to [0,1) to avoid overflow.
    r = clamp(r, 0.0, 0.999);
    g = clamp(g, 0.0, 0.999);
    b = clamp(b, 0.0, 0.999);

    // Translate the [0,1) range to [0,255]
    int rbyte = static_cast<int>(255.999 * r);
    int gbyte = static_cast<int>(255.999 * g);
    int bbyte = static_cast<int>(255.999 * b);

    // Write the color
    out << rbyte << ' ' << gbyte << ' ' << bbyte << '\n';
}

#endif

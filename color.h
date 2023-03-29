#ifndef COLOR_H
#define COLOR_H

#include "vec3.h"

#include <iostream>

void write_color(std::ostream &out, color pixel_color, int samples_per_pixel) {
    auto r = pixel_color.x();
    auto g = pixel_color.y();
    auto b = pixel_color.z();

    // Divide the color by the number of samples and gamma-correct for gamma=2.0.
    auto scale = 1.0 / samples_per_pixel;
    r = sqrt(scale * r);
    g = sqrt(scale * g);
    b = sqrt(scale * b);

    // Write the translated [0,255] value of each color component.
    out << static_cast<int>(256 * clamp(r, 0.0, 0.999)) << ' '
        << static_cast<int>(256 * clamp(g, 0.0, 0.999)) << ' '
        << static_cast<int>(256 * clamp(b, 0.0, 0.999)) << '\n';
}

void write_color(shared_ptr<uint8_t[]> pixel_data, int x, int y, int w, int h, color pixel_color,
    int samples_per_pixel) {
    auto r = pixel_color.x();
    auto g = pixel_color.y();
    auto b = pixel_color.z();

    // Divide the color by the number of samples and gamma-correct for gamma=2.0.
    auto scale = 1.0 / samples_per_pixel;
    r = sqrt(scale * r);
    g = sqrt(scale * g);
    b = sqrt(scale * b);

    int pos = 3 * (y * w + x);

    // Write the translated [0,255] value of each color component.
    pixel_data[pos] = static_cast<uint8_t>(256 * clamp(r, 0.0, 0.999));
    pixel_data[pos + 1] = static_cast<uint8_t>(256 * clamp(g, 0.0, 0.999));
    pixel_data[pos + 2] = static_cast<uint8_t>(256 * clamp(b, 0.0, 0.999));
}

#endif
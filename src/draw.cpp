#include <cassert>
#include <algorithm>
#include "draw.h"
#include "const.h"

void Draw::drawPixel(int x, int y, const Color &color, int alphaU, int alphaD)
{
    if (octant & 1) // Step 2. Must be in the reversed order.
        std::swap(x, y);
    if (octant >= 2) // Step 1
        x = IMG_WIDTH - x;
    canvas.drawPixel(x, y, color, alphaU, alphaD);
}

void Draw::draw(int x0, int y0, int x1, int y1, const Color &color)
{
    if (y1 < y0)
        std::swap(x0, x1), std::swap(y0, y1);
    assert(y1 >= y0);

    octant = 0; // Step 1
    if (x1 < x0)
        octant += 2, x0 = IMG_WIDTH - x0, x1 = IMG_WIDTH - x1;
    assert(x1 >= x0);

    if (y1 - y0 > x1 - x0) // Step 2
        octant += 1, std::swap(x0, y0), std::swap(x1, y1);
    assert(y1 - y0 <= x1 - x0);

    assert(octant >= 0 && octant < 4);
    drawImpl(x0, y0, x1, y1, color);
}

#include "drawwidth.h"

void DrawWidth::drawImpl(int x0, int y0, int x1, int y1, const Color &color)
{
    int x(x0), y(y0), dx(x1 - x0), dy(y1 - y0), e(-dx);
    for (; x <= x1; x++)
    {
        for (int i = 0; i < WIDTH; i++)
            drawPixel(x, y + i, color);
        e += 2 * dy;
        if (e >= 0)
            y++, e -= 2 * dx;
    }
}


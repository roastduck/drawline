#include "drawplain.h"

void DrawPlain::drawImpl(int x0, int y0, int x1, int y1, const Color &color)
{
    int x(x0), y(y0), dx(x1 - x0), dy(y1 - y0), e(-dx);
    for (; x <= x1; x++)
    {
        drawPixel(x, y, color);
        e += 2 * dy;
        if (e >= 0)
            y++, e -= 2 * dx;
    }
}


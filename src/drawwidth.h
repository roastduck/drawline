#ifndef DRAW_WIDTH_H_
#define DRAW_WIDTH_H_

#include "draw.h"

/** Draw lines with a width */
class DrawWidth : public Draw
{
private:
    const int WIDTH;

protected:
    void drawImpl(int x0, int y0, int x1, int y1, const Color &color) override;

public:
    DrawWidth(Canvas &canvas, int _width)
        : Draw(canvas), WIDTH(_width) {}
};

#endif // DRAW_WIDTH_H_


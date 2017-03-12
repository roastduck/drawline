#ifndef DRAW_H_
#define DRAW_H_

#include "canvas.h"

/** Base class for both plain and AA algorithm */
class Draw
{
private:
    /** Octant in [0, 4)
     * \2|1/
     * 3\|/0
     * ----- */
    int octant;

    Canvas &canvas;

protected:
    /** Draw a pixel accroding to current octant
     *  alpha = alphaU / alphaD */
    void drawPixel(int x, int y, const Color &color, int alphaU = 1, int alphaD = 1);

    /** Implementation.
     *  Suppose 0 <= slope <= 1 */
    virtual void drawImpl(int x0, int y0, int x1, int y1, const Color &color) = 0;

public:
    Draw(Canvas &_canvas) : canvas(_canvas) {}
    
    /** Draw a line: (x0, y0) -> (x1, y1) */
    void draw(int x0, int y0, int x1, int y1, const Color &color);
};

#endif // DRAW_H_

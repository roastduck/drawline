#include "draw.h"

class DrawPlain : public Draw
{
protected: 
    /** Plain draw-line algorithm */
    void drawImpl(int x0, int y0, int x1, int y1, const Color &color) override;

public:
    DrawPlain(Canvas &canvas)
        : Draw(canvas) {}
};


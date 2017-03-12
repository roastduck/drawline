#ifndef DRAWAA_H_
#define DRAWAA_H_

#include <array>
#include "draw.h"

/** Anti-alisasing algorithm */
class DrawAA : public Draw
{
private:
    static const int LEN = 7; /// Slide length of the fine division

    typedef std::array<std::array<int, LEN>, LEN> WeightMat;

    static const constexpr WeightMat WEIGHT {{ /// weights of each grid
        {{ 1, 2, 3, 4, 3, 2, 1 }},
        {{ 2, 4, 6, 8, 6, 4, 2 }},
        {{ 3, 6, 9,12, 9, 6, 3 }},
        {{ 4, 8,12,16,12, 8, 4 }},
        {{ 3, 6, 9,12, 9, 6, 3 }},
        {{ 2, 4, 6, 8, 6, 4, 2 }},
        {{ 1, 2, 3, 4, 3, 2, 1 }}
    }}; // See C++11 aggregate initialization for these double braces
    static const int TOT_WEIGHT = 256;

    static WeightMat genSum();
    static WeightMat SUM; /// Sum WEIGHT from upper direction

protected: 
    void drawImpl(int x0, int y0, int x1, int y1, const Color &color) override;

public:
    DrawAA(Canvas &canvas)
        : Draw(canvas) {}
};

#endif // DRAWAA_H_


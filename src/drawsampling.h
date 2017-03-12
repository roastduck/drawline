#ifndef DRAW_SAMPLING_H_
#define DRAW_SAMPLING_H_

#include <array>
#include "draw.h"

/** Uniform sampling algorithm */
class DrawSampling : public Draw
{
protected:
    static const int LEN = 7; /// Slide length of the fine division

    typedef std::array<std::array<int, LEN>, LEN> WeightMat;

    WeightMat genSum() const;
    WeightMat WEIGHT, SUM;
    int TOT_WEIGHT;

    void drawImpl(int x0, int y0, int x1, int y1, const Color &color) override;

public:
    DrawSampling(Canvas &canvas) :
        Draw(canvas),
        WEIGHT({{ /// weights of each grid
            {{ 1, 1, 1, 1, 1, 1, 1 }},
            {{ 1, 1, 1, 1, 1, 1, 1 }},
            {{ 1, 1, 1, 1, 1, 1, 1 }},
            {{ 1, 1, 1, 1, 1, 1, 1 }},
            {{ 1, 1, 1, 1, 1, 1, 1 }},
            {{ 1, 1, 1, 1, 1, 1, 1 }},
            {{ 1, 1, 1, 1, 1, 1, 1 }},
        }}), // See C++11 aggregate initialization for these double braces
        SUM(genSum()),
        TOT_WEIGHT(LEN * LEN)
    {}
};

#endif // DRAW_SAMPLING_H_


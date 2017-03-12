#ifndef DRAW_KERNEL_H_
#define DRAW_KERNEL_H_

#include <iostream>
#include "drawsampling.h"

/** Kernel algorithm, i.e. weighted sampling algorithm */
class DrawKernel : public DrawSampling
{
public:
    DrawKernel(Canvas &canvas) : DrawSampling(canvas)
    {
        WEIGHT = {{ /// weights of each grid
            {{ 1, 2, 3, 4, 3, 2, 1 }},
            {{ 2, 4, 6, 8, 6, 4, 2 }},
            {{ 3, 6, 9,12, 9, 6, 3 }},
            {{ 4, 8,12,16,12, 8, 4 }},
            {{ 3, 6, 9,12, 9, 6, 3 }},
            {{ 2, 4, 6, 8, 6, 4, 2 }},
            {{ 1, 2, 3, 4, 3, 2, 1 }}
        }};
        TOT_WEIGHT = 256;
        SUM = genSum();
    }
};

#endif // DRAW_KERNEL_H_

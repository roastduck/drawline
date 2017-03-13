#include <cstdlib>
#include "drawsampling.h"

DrawSampling::WeightMat DrawSampling::genSum() const
{
    DrawSampling::WeightMat ret(WEIGHT);
    for (int i = 1; i < LEN; i++)
        for (int j = 0; j < LEN; j++)
            ret[i][j] += ret[i - 1][j];
    return ret;
}

void DrawSampling::drawImpl(int x0, int y0, int x1, int y1, const Color &color)
{
    int realX(x0), realY(y0), gridX(0), gridY(0); // Scaled x = realX * LEN + gridX, y the same
    int minY(y0); // Mininum realY while realX has not been changed
    int acc0(0), acc1(0), acc2(0); // Accumulated weight for realY = minY + 0, 1 or 2
    int dx(x1 - x0), dy(y1 - y0), e(-dx);
    int height = LEN * dx / sqrt(dx * dx + dy * dy);
    for (int i = 0; i < dx * LEN; i++)
    {
        int *accLower, *accUpper;
        if (realY == minY)
            accLower = &acc0, accUpper = &acc1;
        else
        {
            assert(realY == minY + 1);
            accLower = &acc1, accUpper = &acc2;
        }
        if (gridY + height <= LEN)
            *accLower += SUM[gridY + height - 1][gridX] - (gridY ? SUM[gridY - 1][gridX] : 0);
        else
        {
            *accLower += SUM[LEN - 1 - gridY][gridX];
            *accUpper += SUM[gridY + height - LEN][gridX];
        }

        e += 2 * dy;
        if (e >= 0)
        {
            if (++gridY == LEN)
                gridY = 0, realY++;
            e -= 2 * dx;
        }
        if (++gridX == LEN)
        {
            assert(acc0);
            drawPixel(realX, minY, color, acc0, TOT_WEIGHT);
            if (acc1)
                drawPixel(realX, minY + 1, color, acc1, TOT_WEIGHT);
            if (acc2)
                drawPixel(realX, minY + 2, color, acc2, TOT_WEIGHT);
            gridX = 0, realX++, minY = realY;
            acc0 = acc1 = acc2 = 0;
        }
    }
}


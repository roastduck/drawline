#include <cmath>
#include <algorithm>
#include <opencv2/opencv.hpp>
#include "const.h"
#include "canvas.h"
#include "drawaa.h"
#include "drawplain.h"

int main()
{
    const constexpr int X0 = IMG_WIDTH >> 1;
    const constexpr int Y0 = IMG_HEIGHT >> 1;
    const int LEN = std::min(X0, Y0) * 0.9;

    Canvas canvasPlain(IMG_HEIGHT, IMG_WIDTH, Color(255, 255, 255));
    DrawPlain drawPlain(canvasPlain);
    Canvas canvasAA(IMG_HEIGHT, IMG_WIDTH, Color(255, 255, 255));
    DrawAA drawAA(canvasAA);

    for (int i = 0; i < LINE_CNT; i++)
    {
        double dgr(pi / LINE_CNT * i);
        int dx(LEN * cos(dgr)), dy(LEN * sin(dgr));
        Color colorHSV(255 * i / LINE_CNT, 255, 255);
        cv::Mat3b matHSV(colorHSV), matBGR;
        cv::cvtColor(matHSV, matBGR, cv::COLOR_HSV2BGR_FULL);
        drawPlain.draw(X0 - dx, Y0 - dy, X0 + dx, Y0 + dy, matBGR(0, 0));
        drawAA.draw(X0 - dx, Y0 - dy, X0 + dx, Y0 + dy, matBGR(0, 0));
    }

    canvasPlain.save("plain.png");
    canvasAA.save("aa.png");
    return 0;
}


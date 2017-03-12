#include <cmath>
#include <algorithm>
#include <opencv2/opencv.hpp>
#include "const.h"
#include "canvas.h"
#include "draw.h"
#include "drawwidth.h"
#include "drawkernel.h"
#include "drawsampling.h"

int main()
{
    const constexpr int X0 = IMG_WIDTH >> 1;
    const constexpr int Y0 = IMG_HEIGHT >> 1;
    const int LEN = std::min(X0, Y0) * 0.9;

    Canvas canvasPlain(IMG_HEIGHT, IMG_WIDTH, Color(255, 255, 255));
    Draw drawPlain(canvasPlain);
    Canvas canvasWidth(IMG_HEIGHT * 7, IMG_WIDTH * 7, Color(255, 255, 255));
    DrawWidth drawWidth(canvasWidth, 7);
    Canvas canvasSampleing(IMG_HEIGHT, IMG_WIDTH, Color(255, 255, 255));
    DrawSampling drawSampling(canvasSampleing);
    Canvas canvasKernel(IMG_HEIGHT, IMG_WIDTH, Color(255, 255, 255));
    DrawKernel drawKernel(canvasKernel);

    for (int i = 0; i < LINE_CNT; i++)
    {
        double dgr(pi / LINE_CNT * i);
        int dx(LEN * cos(dgr)), dy(LEN * sin(dgr));
        Color colorHSV(255 * i / LINE_CNT, 255, 255);
        cv::Mat3b matHSV(colorHSV), matBGR;
        cv::cvtColor(matHSV, matBGR, cv::COLOR_HSV2BGR_FULL);
        drawPlain.draw(X0 - dx, Y0 - dy, X0 + dx, Y0 + dy, matBGR(0, 0));
        drawWidth.draw((X0 - dx) * 7, (Y0 - dy) * 7, (X0 + dx) * 7, (Y0 + dy) * 7, matBGR(0, 0));
        drawSampling.draw(X0 - dx, Y0 - dy, X0 + dx, Y0 + dy, matBGR(0, 0));
        drawKernel.draw(X0 - dx, Y0 - dy, X0 + dx, Y0 + dy, matBGR(0, 0));
    }

    std::clog << "Plain: Drew " << LINE_CNT << " lines in " << drawPlain.totTime << "secs" << std::endl;
    std::clog << "Anti-Alias (SSAA): Drew " << LINE_CNT << " lines in " << drawWidth.totTime << "secs" << std::endl;
    std::clog << "Anti-Alias (Sampling): Drew " << LINE_CNT << " lines in " << drawSampling.totTime << "secs" << std::endl;
    std::clog << "Anti-Alias (Kernel): Drew " << LINE_CNT << " lines in " << drawKernel.totTime << "secs" << std::endl;
    canvasPlain.save("plain.png");
    canvasWidth.saveResized("ssaa.png", IMG_HEIGHT, IMG_WIDTH);
    canvasSampleing.save("sampling.png");
    canvasKernel.save("kernel.png");
    return 0;
}


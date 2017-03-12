#ifndef CANVAS_H_
#define CANVAS_H_

#include <opencv2/opencv.hpp>

typedef cv::Vec3b Color;

/** Interface to OpenCV */
class Canvas
{
private:
    int height, width;
    cv::Mat3b data; /// In HSV color space

public:
    /** Initialize an empty image */
    Canvas(int _height, int _width, const Color &background)
        : height(_height), width(_width), data(height, width, background) {}

    /** Draw a pixel with given transparency
     *  alpha = alphaU / alphaD */
    void drawPixel(int x, int y, const Color &color, int alphaU, int alphaD)
    {
        data(height - y, x) = ((alphaD - alphaU) * cv::Vec3i(data(height - y, x)) + alphaU * cv::Vec3i(color)) / alphaD; // row, col
    }

    /** Save to file */
    void save(const char *filename) const
    {
        cv::Mat output;
        cv::imwrite(filename, data);
    }
};

#endif // CANVAS_H_


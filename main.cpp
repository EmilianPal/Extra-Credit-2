#include <iostream>
#include "ImageProcessing.h"
#include "Brightness.h"
#include "Gamma.h"
#include "ImageConvolution.h"
#include "Draw.h"

int identityFunc(int x)
{
    return x;
}

int meanBlurFunc(int x)
{
    return x/9;
}

int GaussianFunc(int x)
{
    return x/16;
}

int HSobelFunc(int x)
{
    return (x/4 + 255)/2;
}

int VSobelFunc(int x)
{
    return (x/4 + 255)/2;
}

int main() {
    int identical[3][3], meanBlur[3][3], Gaussian[3][3], HSobel[3][3], VSobel[3][3];
    identical[0][0] = 0; identical[0][1] = 0; identical[0][1] = 0;
    identical[1][0] = 0; identical[1][1] = 0; identical[1][2] = 0;
    identical[2][0] = 0; identical[2][1] = 0; identical[2][2] = 0;
    meanBlur[0][0] = 1; meanBlur[0][1] = 1; meanBlur[0][2] = 1;
    meanBlur[1][0] = 1; meanBlur[1][1] = 1; meanBlur[1][2] = 1;
    meanBlur[2][0] = 1; meanBlur[2][1] = 1; meanBlur[2][2] = 1;
    Gaussian[0][0] = 1; Gaussian[0][1] = 2; Gaussian[0][2] = 1;
    Gaussian[1][0] = 2; Gaussian[1][1] = 4; Gaussian[1][2] = 2;
    Gaussian[2][0] = 1; Gaussian[2][1] = 2; Gaussian[2][2] = 1;
    HSobel[0][0] = 1; HSobel[0][1] = 2; HSobel[0][2] = 1;
    HSobel[1][0] = 0; HSobel[1][1] = 0; HSobel[1][2] = 0;
    HSobel[2][0] = -1; HSobel[2][1] = -2; HSobel[2][2] = -1;
    VSobel[0][0] = -1; VSobel[0][1] = 0; VSobel[0][2] = 1;
    VSobel[1][0] = -2; VSobel[1][1] = 0; VSobel[1][2] = 2;
    VSobel[2][0] = -1; VSobel[2][1] = 0; VSobel[2][2] = 1;
    Image image1, image2, image3, image4;
    image1.load("barbara.ascii.pgm");
    image2.load("apollonian_gasket.ascii.pgm");
    image2.save("Test.ascii.pgm");
    image3.load("balloons.ascii.pgm");
    image2.save("Test2.ascii.pgm");
    ImageConvolution sobel1, sobel2;
    sobel1 = ImageConvolution(VSobel, VSobelFunc);
    sobel1.process(image3, image4);
    image4.save("Test2.ascii.pgm");
    sobel2 = ImageConvolution(HSobel, HSobelFunc);
    sobel2.process(image3, image2);
    image2.save("Test.ascii.pgm");
    image1 = image2 - image4;
    image1 = image1 * 255;
    image1.save("Test1.ascii.pgm");
    /*Draw draw;
    Point center, p1, p2, p3, p4, p5, p6;
    p1 = Point(10, 5);
    p2 = Point(100, 69);
    center =Point(50, 50);
    draw.drawCircle(image3, center, 30, 255);
    image3.save("Test2.ascii.pgm");
    draw.drawLine(image3, p1, p2, 0, 100);
    p5 = Point(5, 10);
    p6 = Point(69, 100);
    draw.drawLine(image3, p5, p6, 255, 50);
    image3.save("Test2.ascii.pgm");
    p3 = Point(50, 100);
    p4= Point(90, 400);
    draw.drawRectangle(image3, p3, p4, 127);
    image3.save("Test2.ascii.pgm");*/
    return 0;
}

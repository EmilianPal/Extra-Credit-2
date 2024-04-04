//
// Created by Emi on 03.04.2024.
//

#ifndef EXTRA_CREDIT_2_DRAW_H
#define EXTRA_CREDIT_2_DRAW_H
#include "Image.h"

class Draw {
    //This function will draw geometrical figures on the image
public:
    void drawCircle(Image& img, Point center, int radius, unsigned char color);
    //This function will draw a circle on the image of a given colour using a point as the center, an int as the radius and colour as the colour value of the circle
    void drawLine(Image &img, Point p1, Point p2, unsigned char color, int marginOfError);
    //This function will draw a line from the point p1 to the point p2 of a given colour, again, given by a value and a
    //margin of error, which will determine its thickness, but this value is NOT representative of a pixel, but is instead a number used in the calculus of the line
    void drawRectangle(Image &img, Rectangle r, unsigned char color);
    //This function will draw a rectangle r of a given colour given by a value
    void drawRectangle(Image &img, Point tl, Point br, unsigned char color);
    //This function will draw a rectangle from point p1 to p2 of a given colour given by a value
};


#endif //EXTRA_CREDIT_2_DRAW_H

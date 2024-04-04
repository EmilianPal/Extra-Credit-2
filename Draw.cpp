//
// Created by Emi on 03.04.2024.
//

#include "Draw.h"

void Draw::drawCircle(Image &img, Point center, int radius, unsigned char color) {
    if(img.getROI(img, center.get_x() - radius, center.get_y() - radius, 2 * radius, 2 * radius))
    {
        int xCoord, yCoord;
        for(int i = center.get_y() - radius; i <= center.get_y() + radius; ++i)
        {
            for(int j = center.get_x() - radius; j <= center.get_x() + radius; ++j)
            {
                xCoord = j - center.get_x();
                yCoord = i - center.get_y();
                if(xCoord * xCoord + yCoord * yCoord <= radius * radius)
                {
                    img.set_at(j, i , color);
                }
            }
        }
    }
}

void Draw::drawLine(Image &img, Point p1, Point p2, unsigned char color, int marginOfError) {
    float a, b, c;
    a = float(p2.get_y() - p1.get_y());
    b = float(p1.get_x() - p2.get_x());
    c = a * (float)p1.get_x() + b * (float)p1.get_y();
    //These formulas are used to compute the equation of the line
    for(int i = 0; i < img.get_height(); ++i)
    {
        for(int j = 0; j < img.get_width(); ++j)
            if((int)(a * j + b * i) >= (int)(c-marginOfError) && (int)(a * j + b * i) <= int(c+marginOfError)) img.set_at(j, i , color);
    }
}

void Draw::drawRectangle(Image &img, Rectangle r, unsigned char color) {
    if(img.getROI(img, r))
    {
        for(int i = r.get_y(); i <= r.get_y() + r.get_height(); ++i)
            for(int j = r.get_x(); j <= r.get_x() + r.get_width() ; ++j)
            {
                img.set_at(j, i , color);
            }
    }
}

void Draw::drawRectangle(Image &img, Point tl, Point br, unsigned char color) {
    if(img.getROI(img, tl.get_x(), tl.get_y(), br.get_x() - tl.get_x(), br.get_y() - tl.get_y()))
    {
        for(int i = tl.get_y(); i <= br.get_y(); ++i)
            for(int j = tl.get_x(); j <= br.get_x() ; ++j)
            {
                img.set_at(j, i , color);
            }
    }
}

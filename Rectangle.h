//
// Created by Emi on 30.03.2024.
//

#ifndef EXTRA_CREDIT_2_RECTANGLE_H
#define EXTRA_CREDIT_2_RECTANGLE_H
#include "Point.h"
#include "Size.h"


class Rectangle {
    //This class represents a rectangle
private:
    int x, y;
    //The x and y coordinates of the top left corner
    unsigned int width, height;
    //The width and height of the rectangle
public:
    Rectangle();
    //This is the default constructor, it will set all values to 0
    Rectangle(int x, int y, unsigned int width, unsigned int height);
    //This is the parameterised constructor, setting x, y, width and height to their given values
    ~Rectangle();
    //This is the default destructor
    int get_x();
    //This function will get the x value of the rectangle
    int get_y();
    //This function will get the y value of the rectangle
    unsigned int get_width();
    //This function will get the width of the rectangle
    unsigned int get_height();
    //This function will get the height of the rectangle
    void set_x(int new_x);
    //This function will set the x value of the rectangle to new_x
    void set_y(int new_y);
    //This function will set the y value of the rectangle to new_y
    void set_width(unsigned int new_width);
    //This function will set the width of the rectangle to new_width
    void set_height(unsigned int new_height);
    //This function will set the height of the rectangle to new_height
    Rectangle operator+(Point other) const;
    //This function will add the coordinates of a point to those of the top left corner of the rectangle, moving it
    Rectangle operator-(Point other) const;
    //This function will subtract the coordinates of a point from those of the top left corner of the rectangle, moving it
    Rectangle operator&(const Rectangle &other) const;
    //This function will return the intersection of two rectangles
    Rectangle operator|(const Rectangle &other) const;
    //This function will return a bounding box of the two rectangles
};


#endif //EXTRA_CREDIT_2_RECTANGLE_H

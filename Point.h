//
// Created by Emi on 30.03.2024.
//

#ifndef EXTRA_CREDIT_2_POINT_H
#define EXTRA_CREDIT_2_POINT_H


class Point {
private:
    //This class represents a point
    int x, y;
    //These are the coordinates
public:
    Point();
    //This is the default constructor, setting x and  y to 0
    Point(int x, int y);
    //This is the parameterised constructor, setting x and y to their given values
    ~Point();
    //This is the destructor, which is the default one
    int get_x();
    //This function will get the value of x
    int get_y();
    //This function will get the value of y
    void set_x(int new_x);
    //This function will set the value of x to new_x
    void set_y(int new_y);
    //This function will set the value of y to new_y
};


#endif //EXTRA_CREDIT_2_POINT_H

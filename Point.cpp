//
// Created by Emi on 30.03.2024.
//

#include "Point.h"

Point::Point() {
    x = 0;
    y = 0;
}

Point::Point(int x, int y) {
    this->x = x;
    this->y = y;
}

int Point::get_x() {
    return x;
}

int Point::get_y() {
    return y;
}

void Point::set_x(int new_x) {
    x = new_x;
}

void Point::set_y(int new_y) {
    y = new_y;
}

Point::~Point() = default;


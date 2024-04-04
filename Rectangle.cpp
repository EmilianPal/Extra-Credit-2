//
// Created by Emi on 30.03.2024.
//

#include "Rectangle.h"

Rectangle::Rectangle() {
    x = 0;
    y = 0;
    width = 0;
    height = 0;
}

Rectangle::Rectangle(int x, int y, unsigned int width, unsigned int height) {
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
}

int Rectangle::get_x() {
    return x;
}

int Rectangle::get_y() {
    return y;
}

unsigned int Rectangle::get_width() {
    return width;
}

unsigned int Rectangle::get_height() {
    return height;
}

void Rectangle::set_x(int new_x) {
    x = new_x;
}

void Rectangle::set_y(int new_y) {
    y = new_y;
}

void Rectangle::set_width(unsigned int new_width) {
    width = new_width;
}

void Rectangle::set_height(unsigned int new_height) {
    height = new_height;
}

Rectangle Rectangle::operator+(Point other) const {
    return Rectangle{x + other.get_x(), y + other.get_y(), width, height};
}

Rectangle Rectangle::operator-(Point other) const {
    return Rectangle{x - other.get_x(), y - other.get_y(), width, height};
}

Rectangle Rectangle::operator&(const Rectangle &other) const {
    Rectangle result;
    //place the verification here
    if((x < other.x - width ) || (x > other.x + other.width))
        return result;
    if((y < other.y - other.height)|| ( y > other.y + height))
        return result;
    int new_x, new_y, bottomRightX, bottomRightY;
    unsigned int new_width, new_height;
    if(x  > other.x) new_x = x;
    else new_x = other.x;
    if(y < other.y) new_y = y;
    else new_y = other.y;
    if(x + width < other.x + other.width) bottomRightX = x + width;
    else bottomRightX = other.x + other.width;
    if(y - height > other.y - other.height) bottomRightY = y - height;
    else bottomRightY = other.y - other.height;
    new_width = bottomRightX - new_x;
    new_height = new_y - bottomRightY;
    result.x = new_x;
    result.y = new_y;
    result.width = new_width;
    result.height = new_height;
    return result;
}

Rectangle Rectangle::operator|(const Rectangle &other) const{
    Rectangle result;
    int new_x, new_y, bottomRightX, bottomRightY;
    unsigned int new_width, new_height;
    if(x  < other.x) new_x = x;
    else new_x = other.x;
    if(y > other.y) new_y = y;
    else new_y = other.y;
    if(x + width > other.x + other.width) bottomRightX = x + width;
    else bottomRightX = other.x + other.width;
    if(y - height < other.y - other.height) bottomRightY = y - height;
    else bottomRightY = other.y - other.height;
    new_width = bottomRightX - new_x;
    new_height = new_y - bottomRightY;
    result.x = new_x;
    result.y = new_y;
    result.width = new_width;
    result.height = new_height;
    return result;
}

Rectangle::~Rectangle() = default;

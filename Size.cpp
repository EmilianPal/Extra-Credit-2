//
// Created by Emi on 30.03.2024.
//

#include "Size.h"

Size::Size() {
    width = 0;
    height = 0;
}

Size::Size(unsigned int width, unsigned int height) {
    this->width = width;
    this->height = height;
}

unsigned int Size::get_width() {
    return width;
}

unsigned int Size::get_height() {
    return height;
}

void Size::set_width(unsigned int new_width) {
    width = new_width;
}

void Size::set_height(unsigned int new_height) {
    height = new_height;
}

bool Size::operator<(const Size &other) const {
    return width * height < other.width * other.height;
}

bool Size::operator<=(const Size &other) const {
    return width * height <= other.width * other.height;
}

bool Size::operator==(const Size &other) const {
    return width * height == other.width * other.height;
}

bool Size::operator>(const Size &other) const {
    return width * height > other.width * other.height;
}

bool Size::operator>=(const Size &other) const {
    return width * height >= other.width * other.height;
}

Size::~Size() = default;



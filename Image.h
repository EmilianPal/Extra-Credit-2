//
// Created by Emi on 31.03.2024.
//

#ifndef EXTRA_CREDIT_2_IMAGE_H
#define EXTRA_CREDIT_2_IMAGE_H
#include <iostream>
#include "Rectangle.h"
#include <cstring>
#include <fstream>

class Image
{
    //This class will contain all the data about a .ascii.pgm image
public:
    Image();
    //This is the default constructor, and it will set the width and height to 0 and the data matrix will be empty
    Image(unsigned int w, unsigned int h);
    //This is the parameterised constructor, and it will create an empty data matrix of the size w and h
    Image(const Image &other);
    //This constructor is used to copy the content of one constructor to another
    Image& operator=(const Image &other);
    //This is the allocation function of the image class, and it is used to give the value of one image to another
    ~Image();
    //This is the destructor of the class
    bool load(std::string imagePath);
    //This function will get the data of an .ascii.pgm image from the computer and store it inside an Image variable
    bool save(std::string imagePath) const;
    //This function will take the contents of an Image variable and then place them inside an .ascii.pgm file on the computer
    Image operator+(const Image &i);
    //This is the overloading of the + operation, which will add up the values of all the pixels of the images
    Image operator-(const Image &i);
    //This is the overloading of the - operation, which will subtract the values of all the pixels of the images from the other
    Image operator*(double s);
    //This is the overloading of the * operation, which will multiply the value of each pixel by s
    bool getROI(Image &roiImg, Rectangle roiRect);
    //This function will verify if a rectangle given by the Rectangle object can be placed inside the image
    bool getROI(Image &roiImg, unsigned int x, unsigned int y, unsigned int width, unsigned int height);
    //This function will verify if a rectangle given by the coordinates of the top left corner and its width and height can be placed inside the image
    bool isEmpty() const;
    //This function will verify if the image is empty
    Size size() const;
    //This function will return the size of the image as a size object
    unsigned int get_width() const;
    //This function will get the width of the image
    unsigned int get_height() const;
    //This function will return the height of the image
    void set_width(unsigned int w);
    //This function will set the width of the image
    void set_height(unsigned int h);
    //This function will set the height of the image
    unsigned char& at(unsigned int x, unsigned int y) const;
    //This function will return the pixel with the given coordinates
    unsigned char& at(Point pt) const;
    //This function will return the pixel at the given point
    void set_at(unsigned int x, unsigned int y, unsigned char newValue);
    //This function will set the value of the pixel at the given coordinates
    void set_at(Point pt, unsigned char newValue);
    //This function will set the value of the pixel at the given point
    unsigned char* row(int y);
    //This function will return the values of all pixels on a given row of the matrix
    void release();
    //This function will release all the memory stored in the Image
    friend std::ostream& operator<<(std::ostream& os, const Image& dt);
    //This will overload the stream insertion operation to print the content of the image
    friend std::istream& operator>>(std::istream& is, Image& dt);
    //This will overload the stream extraction operation to read the content of the image
    static Image zeros(unsigned int width, unsigned int height);
    //This will generate an Image containing only black pixels
    static Image ones(unsigned int width, unsigned int height);
    //This will generate an Image containing only white pixels
private:
    unsigned char** m_data{};
    //This is the matrix which stores all the data of the pixels
    //It is an unsigned char so that it amy ony store values from 0 to 255 to be more memory efficient
    unsigned int m_width;
    //This is the width of the image
    unsigned int m_height;
    //This si the height of the image
};


#endif //EXTRA_CREDIT_2_IMAGE_H

//
// Created by Emi on 03.04.2024.
//

#ifndef EXTRA_CREDIT_2_BRIGHTNESS_H
#define EXTRA_CREDIT_2_BRIGHTNESS_H
#include "ImageProcessing.h"

class Brightness : public ImageProcessing{
    //This class is used to modify the brightness and the contrast of an image using the following equation for each pixel:
    //alpha * x + beta, with x being the value of the pixel
public:
    Brightness();
    //This is the default constructor, it initialises alpha as 1 and beta as 0, which means that the image will not be changed at all
    Brightness(float x, float y);
    //This is the parametrised constructor. x will be the value of alpha and y the value of beta.
    //Both of them are floats to allow us to be able to perform changes which do not impact the image too drastically.
    void process(const Image& src, Image& dst);
    //This is the process function, and it will process the image according to the equation
private:
    double alpha;
    float beta;
};


#endif //EXTRA_CREDIT_2_BRIGHTNESS_H

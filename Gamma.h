//
// Created by Emi on 03.04.2024.
//

#ifndef EXTRA_CREDIT_2_GAMMA_H
#define EXTRA_CREDIT_2_GAMMA_H
#include "ImageProcessing.h"
#include <cmath>
class Gamma : private ImageProcessing{
    //This class will alter the overall brightness of an image using a gamma variable, the number being the power to which a pixel's value is raised
public:
    Gamma();
    //This is the default constructor, and it initialises gamma as 1
    Gamma(float x);
    //This is the parametrised constructor, and it will set gamma as the value of x
    void process(const Image& src, Image& dst);
    //This is the process function, and it will process the image according to the equation
private:
    double gamma;
};


#endif //EXTRA_CREDIT_2_GAMMA_H

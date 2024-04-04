//
// Created by Emi on 03.04.2024.
//

#ifndef EXTRA_CREDIT_2_IMAGEPROCESSING_H
#define EXTRA_CREDIT_2_IMAGEPROCESSING_H
#include "Image.h"

class ImageProcessing {
    //This will be the base class of the Image processing subclasses
public:
    virtual void process(const Image& src, Image& dst)=0;
    //This is a pure virtual method which all the subclasses will alter to suit their needs
};

#endif //EXTRA_CREDIT_2_IMAGEPROCESSING_H

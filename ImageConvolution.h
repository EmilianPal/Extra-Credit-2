//
// Created by Emi on 03.04.2024.
//

#ifndef EXTRA_CREDIT_2_IMAGECONVOLUTION_H
#define EXTRA_CREDIT_2_IMAGECONVOLUTION_H
#include "ImageProcessing.h"

class ImageConvolution : private ImageProcessing{
    //This class will Convolute the image based on the values of the kernel and the scaling function
public:
    ImageConvolution();
    //This is the default constructor of the function, and it will initialise a kernel with the identical matrix and the function will output the inserted value
    //So almost nothing changes save for the pixels on the edge of the image getting cropped out
    ImageConvolution(int kernel[][3], int (*func_ptr)(int x));
    //This is the parameterised constructor, and it will receive a kernel and a scaling function which it will use to perform the convolution with
    void process(const Image& src, Image& dst);
    //This is the process function, and it will process the image according to the given values
private:
    int kernel[3][3];
    int (*func_ptr)(int);
};


#endif //EXTRA_CREDIT_2_IMAGECONVOLUTION_H

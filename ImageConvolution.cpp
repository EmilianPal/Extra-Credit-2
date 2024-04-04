//
// Created by Emi on 03.04.2024.
//

#include "ImageConvolution.h"

int equal(int x)
{
    return x;
}

ImageConvolution::ImageConvolution() {
    kernel[0][0] = 0;
    kernel[0][1] = 0;
    kernel[0][2] = 0;
    kernel[1][0] = 0;
    kernel[1][1] = 1;
    kernel[1][2] = 0;
    kernel[2][0] = 0;
    kernel[2][1] = 0;
    kernel[2][2] = 0;
    this->func_ptr = equal;
}

ImageConvolution::ImageConvolution(int kernel[][3], int (*func_ptr)(int)) {
    for(int i = 0; i < 3; ++i)
        for(int j = 0; j < 3; ++j)
            this->kernel[i][j] = kernel[i][j];
    this->func_ptr = func_ptr;
}

void ImageConvolution::process(const Image &src, Image &dst) {
    int temp;
    //dst.release();
    dst = dst.zeros(src.get_width() -2, src.get_height() - 2);
    for (unsigned int i = 1; i < src.get_height() - 1; ++i) {
        for (unsigned int j = 1; j < src.get_width() - 1; ++j) {
            temp = 0;
            for (unsigned int k = i - 1; k <= i + 1; ++k)
                for (unsigned int l = j - 1; l <= j + 1; ++l) {
                    temp += kernel[k - i + 1][l - j + 1] * src.at(l, k);
                }
            dst.set_at(j - 1, i - 1,  (unsigned char)func_ptr(temp));
        }
    }
}
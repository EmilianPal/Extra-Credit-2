//
// Created by Emi on 03.04.2024.
//

#include "Brightness.h"

Brightness::Brightness() {
    alpha = 1;
    beta = 0;
}

Brightness::Brightness(float x, float y) {
    alpha = x;
    beta = y;
}

void Brightness::process(const Image &src, Image &dst) {
    dst.release();
    dst = src;
    for(int i = 0; i < dst.get_height(); ++i)
        for(int j = 0; j < dst.get_width(); ++j) {
            if(alpha * src.at(j, i) + beta > 255) dst.set_at(j, i, 255);
            else dst.set_at(j, i, (unsigned char) (alpha * src.at(j, i) + beta));
        }
}
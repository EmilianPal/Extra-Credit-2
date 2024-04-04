//
// Created by Emi on 03.04.2024.
//

#include "Gamma.h"

Gamma::Gamma() {
    gamma = 1;
}

Gamma::Gamma(float x) {
    gamma = x;
}

void Gamma::process(const Image &src, Image &dst) {
    dst.release();
    dst = src;
    for(int i = 0; i < dst.get_height(); ++i)
        for(int j = 0; j < dst.get_width(); ++j) {
            if((unsigned char) (pow(src.at(j, i), gamma) > 255)) dst.set_at(j, i, 255);
            else dst.set_at(j, i, (unsigned char) (pow(src.at(j, i), gamma)));
        }
}

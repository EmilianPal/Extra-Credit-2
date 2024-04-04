//
// Created by Emi on 31.03.2024.
//

#include "Image.h"

Image::Image() {
    m_data = nullptr;
    m_width = 0;
    m_height = 0;
}

Image::Image(unsigned int w, unsigned int h) {
    m_width = w;
    m_height = h;
    m_data = new unsigned char*[m_height];
    for(int i = 0; i < m_height; ++i) {
        m_data[i] = new unsigned char[m_width];
        for(int j = 0; j < m_width; ++j)
            m_data[i][j] = 0;
    }
}

Image::Image(const Image &other) {
    m_width = other.m_width;
    m_height = other.m_height;
    m_data = new unsigned char * [m_height];
    for(int i = 0; i < m_height; ++i) {
        m_data[i] = new unsigned char[m_width];
        for(int j = 0; j < m_width; ++j)
            m_data[i][j] = other.m_data[i][j];
    }
}

Image &Image::operator=(const Image &other) {
    if(this == &other)
        return *this;
    this->release();
    m_width = other.m_width;
    m_height = other.m_height;
    m_data = new unsigned char *[m_height];
    for(int i = 0; i < m_height; ++i) {
        m_data[i] = new unsigned char[m_width];
        for(int j = 0; j < m_width; ++j)
            m_data[i][j] = other.m_data[i][j];
    }
    return *this;
}

void Image::release() {
    if(!isEmpty()) {
        for (int i = 0; i < m_height; ++i)
            delete[] m_data[i];
        delete[] m_data;
        m_width = 0;
        m_height = 0;
    }
}

Image::~Image() {
    release();
}

unsigned int Image::get_width() const {
    return m_width;
}

unsigned int Image::get_height() const {
    return m_height;
}

void Image::set_height(unsigned int h) {
    if(h < m_height)
        throw std::invalid_argument("The height you want to change the image to is lower than its current height!");
    m_height = h;
}

void Image::set_width(unsigned int w) {
    if(w < m_width)
        throw std::invalid_argument("The width you want to change the image to is lower than its current width!");
    m_width = w;
}

Size Image::size() const {
    Size size = Size(m_width, m_height);
    return size;
}

bool Image::isEmpty() const {
    if(m_data == nullptr && m_width == 0 && m_height == 0)
        return true;
    return false;
}

std::istream &operator>>(std::istream &is, Image &dt) {
    char key[3];
    char comment[101];
    int maxValue, value;
    dt.m_width = 0;
    dt.m_height = 0;
    is >> key;
    if (strcmp(key, "P2") != 0)
        throw std::invalid_argument("The opening line is not valid!");
    is.ignore();
    is.getline(comment, 101);
    if(comment[0] != '#')
    {
        int i;
        for(i = 0; i < strlen(comment) && comment[i] != ' '; ++i)
            dt.m_width = dt.m_width * 10 + (comment[i] - '0');
        i++;
        for(;i < strlen(comment); ++i)
            dt.m_height = dt.m_height * 10 + (comment[i] - '0');
    }
    else {
        is >> dt.m_width >> dt.m_height;
    }
    is >> maxValue;
    dt.m_data = new unsigned char*[dt.m_height];
    for(int i = 0; i < dt.m_height; ++i)
        dt.m_data[i] = new unsigned char[dt.m_width];
    for(int i = 0; i < dt.m_width; ++i)
        for(int j = 0; j < dt.m_height; ++j)
        {

            is >> value;
            if(value > maxValue)
            {
                throw std::invalid_argument("The value is greater than the supposed max_value");
            }
            dt.m_data[i][j] = value;
        }
    return is;
}

std::ostream &operator<<(std::ostream &os, const Image &dt) {
    os << "P2\n" << dt.m_width <<" " << dt.m_height << '\n';
    os << 255 << "\n";
    for(int i = 0; i < dt.m_height; ++i) {
        for (int j = 0; j < dt.m_width; ++j)
            os << int(dt.m_data[i][j]) << " ";
        os << "\n";
    }
    return os;
}

bool Image::load(std::string imagePath){
    std::ifstream fin(imagePath);
    char key[3];
    char comment[101];
    int maxValue, value;
    m_width = 0;
    m_height = 0;
    fin >> key;
    if (strcmp(key, "P2") != 0)
        throw std::invalid_argument("The opening line is not valid!");
    fin.ignore();
    fin.getline(comment, 101);
    if(comment[0] != '#')
    {
        int i;
        for(i = 0; i < strlen(comment) && comment[i] != ' '; ++i)
            m_width = m_width * 10 + (comment[i] - '0');
        i++;
        for(;i < strlen(comment); ++i)
            m_height = m_height * 10 + (comment[i] - '0');
    }
    else {
        fin >> m_width >> m_height;
    }
    fin >> maxValue;
    m_data = new unsigned char*[m_height];
    for(int i = 0; i < m_height; ++i)
        m_data[i] = new unsigned char[m_width];
    for(int i = 0; i < m_height; ++i) {
        for (int j = 0; j < m_width; ++j) {

            fin >> value;
            if (value > maxValue) {
                return false;
            }
            m_data[i][j] = value;
        }
    }
    return true;
}
// find a case to output false
bool Image::save(std::string imagePath) const {
    //return false if file does not exist
    std::ofstream fout(imagePath);
    fout << "P2\n" << m_width << " " << m_height << '\n';
    fout << 255 << "\n";
    for(int i = 0; i < m_height; ++i) {
        for (int j = 0; j < m_width; ++j) {
            fout << int(m_data[i][j]) << " ";
        }
        fout << "\n";
    }
    return true;
}

Image Image::zeros(unsigned int width, unsigned int height) {
    Image Zero;
    Zero.m_width = width;
    Zero.m_height = height;
    Zero.m_data = new unsigned char*[Zero.m_height];
    for(int i = 0; i < Zero.m_height; ++i) {
        Zero.m_data[i] = new unsigned char[Zero.m_width];
        for(int j = 0; j < Zero.m_width; ++j)
            Zero.m_data[i][j] = 0;
    }
    return Zero;
}

Image Image::ones(unsigned int width, unsigned int height) {
    Image One;
    One.m_width = width;
    One.m_height = height;
    One.m_data = new unsigned char*[One.m_height];
    for(int i = 0; i < One.m_height; ++i) {
        One.m_data[i] = new unsigned char[One.m_width];
        for(int j = 0; j < One.m_width; ++j)
            One.m_data[i][j] = 255;
    }
    return One;
}

unsigned char &Image::at(unsigned int x, unsigned int y) const{
    return m_data[y][x];
}

void Image::set_at(unsigned int x, unsigned int y, unsigned char newValue) {
    m_data[y][x] = newValue;
}

unsigned char &Image::at(Point pt) const{
    return m_data[pt.get_y()][pt.get_x()];
}

void Image::set_at(Point pt, unsigned char newValue) {
    m_data[pt.get_y()][pt.get_x()] = newValue;
}

unsigned char *Image::row(int y) {
    return m_data[y];
}

Image Image::operator+(const Image &i) {
    if(m_width != i.m_width && m_height != i.m_height)
        throw std::exception();
    for(int j = 0; j < m_height; ++j) {
        for(int k = 0; k < m_width; ++k)
        {
            if(int(m_data[j][k]) + int(i.m_data[j][k]) > 255) m_data[j][k] = 255;
            else m_data[j][k] = m_data[j][k] + i.m_data[j][k];
        }
    }
    return *this;
}

Image Image::operator-(const Image &i) {
    if(m_width != i.m_width && m_height != i.m_height)
        throw std::exception();
    for(int j = 0; j < m_height; ++j) {
        for(int k = 0; k < m_width; ++k)
        {
            if(m_data[j][k] < i.m_data[j][k]) m_data[j][k] = 0;
            else m_data[j][k] = m_data[j][k] - i.m_data[j][k];
        }
    }
    return *this;
}

Image Image::operator*(double s) {
    for(int i = 0; i < m_height; ++i) {
        for(int j = 0; j < m_width; ++j)
        {
            m_data[i][j] = (unsigned char)(m_data[i][j] * s);
        }
    }
    return *this;
}

bool Image::getROI(Image &roiImg, Rectangle roiRect) {
    if(roiRect.get_x() + roiRect.get_width() > roiImg.m_width)
        return false;
    if(roiRect.get_y() + roiRect.get_height() > roiImg.get_height())
        return false;
    return true;
}

bool Image::getROI(Image &roiImg, unsigned int x, unsigned int y, unsigned int width, unsigned int height) {
    if(x + width > roiImg.m_width)
        return false;
    if(y + height > roiImg.get_height())
        return false;
    return true;
}


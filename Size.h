//
// Created by Emi on 30.03.2024.
//

#ifndef EXTRA_CREDIT_2_SIZE_H
#define EXTRA_CREDIT_2_SIZE_H


class Size {
    //This class represents the size of an object
private:
    unsigned int width, height;
public:
    Size();
    //This is the default constructor, setting all values to 0
    Size(unsigned int width, unsigned int height);
    //This is the parameterised constructor, setting width and height to their given values
    ~Size();
    //This is the default destructor
    unsigned int get_width();
    //This function will get the width of the rectangle
    unsigned int get_height();
    //This function will get the height of the rectangle
    void set_width(unsigned int new_width);
    //This function will set the width of the rectangle to new_width
    void set_height(unsigned int new_height);
    //This function will set the height of the rectangle to new_height
    bool operator==(const Size &other) const;
    //This will overload the equality operation to check if two sizes have the same area
    bool operator<=(const Size &other) const;
    //This will overload the <= operation to check if the object has a grater or equal area than the other
    bool operator<(const Size &other) const;
    //This will overload the < operation to check if the object has a grater area than the other
    bool operator>=(const Size &other) const;
    //This will overload the >= operation to check if the object has a lesser or equal area than the other
    bool operator>(const Size &other) const;
    //This will overload the > operation to check if the object has a lesser area than the other

};


#endif //EXTRA_CREDIT_2_SIZE_H

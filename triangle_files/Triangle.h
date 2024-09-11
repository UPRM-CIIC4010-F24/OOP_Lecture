// Checks if Triangle has already been defined
#ifndef TRIANGLE_H
// Defines the Triangle class and stores it in this constant
// Constant usually follows FILENAME_H naming scheme.
#define TRIANGLE_H

class Triangle
{
private:
    /* data */
    float sideA;
    float sideB;
    float sideC;
public:
    Triangle(/* args */);
    Triangle(float a, float b, float c);
    ~Triangle();
    float getArea();
    float getPerimeter();
    float getSideA(){
        return sideA;
    }
    float getSideB() {
        return sideB;
    }
    float getSideC() {
        return sideC;
    }
};
#endif
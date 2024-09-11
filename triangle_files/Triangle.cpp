#include<cmath>
#include"Triangle.h"

float Triangle::getPerimeter() {
    return sideA + sideB + sideC;
}
float Triangle::getArea() {
    float perimeter = (sideA + sideB + sideC);
    float semiPermimeter = perimeter/2;
    // Calculate area
    return sqrt(semiPermimeter*(semiPermimeter-sideA)*(semiPermimeter-sideB) * (semiPermimeter-sideC));
}


Triangle::Triangle()
{
    sideA = 10;
    sideB = 10;
    sideC = 10;
}
Triangle::Triangle(float a, float b, float c) {
    sideA = a;
    sideB = b;
    sideC = c;
}

Triangle::~Triangle()
{
}

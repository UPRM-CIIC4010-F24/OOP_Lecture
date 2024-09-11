#include<iostream>
#include "Triangle.h"

using namespace std;
int main() {
    Triangle t1;
    Triangle t2 = Triangle(5, 2.5, 5);
    t1.getSideA();
    cout << "T1 side " << t2.getSideB() << endl;
    cout << t1.getArea() << endl;
    cout << t2.getArea() << endl;
}
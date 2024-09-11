#include<cmath>
#include<iostream>
using namespace std;
/*
A class that establishes coordinates
It needs to be declared first so we can access it in the
Triangle class.
*/
class Coordinates {
    private:
    // Coordinates x and y
    float x;
    float y;
    public:
    float getX(){
        return this->x;
    }
    float getY(){
        return y;
    }
    // We can set default values using  
    Coordinates():x(1), y(1){

    }
    
};
class Triangle
{
private:
    /* data */
    float sideA;
    float sideB;
    float sideC;
    /*
    Usually we use private functions when we have a repetetive task
    that only the class has to worry about
    */
    float getSemiPerimiter();
public:
    /*
    Since this variable is public anyone that creates a Triangle
    can access it.
    */
    Coordinates coords;
    // Constructos
    Triangle(/* args */);
    Triangle(float a, float b, float c);
    // Destructor
    ~Triangle();
    // These functions will be defined outside the declaration
    float getArea();
    float getPerimeter();
    /* 
    Inline functions, implemented inside the declaration
    Expected to be 1-2 lines long at most.
    */
    float getSideB() const{
        return sideB;
    }
    float getSideC() const{
        return sideC;
    }
    /*
    Getters and setters are functions that give access to
    the atrributes of a class.
    Getters are named get<Variable name>
    Setters are named get<Variable name>

    Getters are accessor functions, this means they return a value
    and do not alter the atributes.
    
    Setters are mutator functions, that means the change the
    values of the attributes.
    */
    float getSideA() const{
        return sideA;
    }
    void setSideA(float a){
        sideA = a;
    }

};
// To indicate a function belongs to a class we
// prepend the class' name followed by :: 
float Triangle::getPerimeter() {
    return sideA + sideB + sideC;
}
float Triangle::getSemiPerimiter() {
    float perimeter = (sideA + sideB + sideC);
    float semiPermimeter = perimeter/2;
    return semiPermimeter;
}
float Triangle::getArea() {
    // Get semi-perimeter
    float semiPerimeter = getSemiPerimiter();
    // Calculate area
    return sqrt(semiPerimeter*(semiPerimeter-sideA)*(semiPerimeter-sideB) * (semiPerimeter-sideC));
}

// Default constructor
Triangle::Triangle(): sideA(10), sideB(10), sideC(10)
{
  coords = Coordinates();
}
// Parametized constructor
Triangle::Triangle(float a, float b, float c) {
    sideA = a;
    sideB = b;
    sideC = c;
}

Triangle::~Triangle()
{
}
// Functions that use Triangles
bool largerThan(Triangle t1, Triangle t2){
    if(t1.getArea() > t2.getArea())
        return true;
    return false;
    // This does exactly the same as the code above
    // return t1.getArea() > t2.getArea();
}

/*
This function receives two triangle objects, One by value and
another by reference indicated by the &.

Pass by value passes an independent copy any changes we do to it leave the 
original un affected. Pass by reference passes the memory adress of the original
this implies that we are accessing the original, therefore any changes we do
will affect the object outside of the function.
*/ 
void setSideATo100(Triangle t1, Triangle &t2) {
    t1.setSideA(100);
    cout << "Side A inside the function for triangle passed by value" << t1.getSideA() << endl;
    t2.setSideA(100);
    cout << "Side A inside the function for traingle passed by reference " << t2.getSideA() << endl;
}
// Example of function that returns a triangle
Triangle sumTriangle(Triangle t1, Triangle t2) {
    float a = t1.getSideA() + t2.getSideA();
    float b = t1.getSideB() + t2.getSideB();
    float c = t1.getSideC() + t2.getSideC();
    // A Triangle needs to be created to return it.
    Triangle finalTriangle = Triangle(a, b, c);

    return finalTriangle;
}
/*
This is how you make an object printable. Just replace the second 
parameter with the class you want.
*/
std::ostream& operator<<(std::ostream& out, const Triangle& triangle) {
    // Since triangle is a constant the methods it can access must be constant as well
    return out << "(" << triangle.getSideA() << ", " << triangle.getSideB() << 
  ", " << triangle.getSideC() << ")" <<std::endl;
}

int main() {
    // Creating 3 different triangles, each will be independent
    // of each other and have different values for their sides
    Triangle t1;
    Triangle t2 = Triangle(5, 2.5, 5);
    Triangle t3 = Triangle(2, 2, 2);
    // Can access the public functions
    cout << "T1 side " << t2.getSideB() << endl;
    cout << t1.getArea() << endl;
    cout << t2.getArea() << endl;
    cout << t3.getArea() << endl;

    // Can pass triangles
    cout << "Is t1 larger than t2? "<< largerThan(t1, t2) << endl;

    cout<< "Side A inside of main for t1 (passed by value)" << t1.getSideA()<< endl;
    cout<< "Side A inside of main for t2 (passed by reference)" << t2.getSideA()<< endl;
    setSideATo100(t1, t2);
    cout<< "Side A inside of main for t1 (passed by value)" << t1.getSideA()<< endl;
    cout<< "Side A inside of main for t2 (passed by reference)" << t2.getSideA()<< endl;

    // Storing a triangle returned form a function
    Triangle t4 = sumTriangle(t1, t2);
    // Accessing its information
    cout << "Side A t4 " << t4.getSideA() << endl;
    // Accessing coordinates, notice that since coords is an object as well
    // When we access it we can also access it's functions.
    cout << "Coordinates t1 " << t1.coords.getX() << ", " << t1.coords.getY() << endl;
    // Printing a triangle object
    cout<< t1;
}



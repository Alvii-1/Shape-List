#pragma once

// 
// Zohaib Alvi, VSCode on MacOS Ventura 
// Professor Adam Koehler
// Spring 2023 Semester
// CS 251 Project 4: CanvasList
//
/* This project involves multiple .h files with testing done using catch testing framework in a separate tests.cpp file. This file contains
the Shape classes, Shape, Circle, Rectangle, and RightTriangle, which involve inheritance from the base Shape class. Each class has setters 
and getters for its own specific private data members, however each subsequent class after shape inherits all of shape's member functions, so
the getX, getY, setX and setY are inherited into each of the child classes.  */
//

using namespace std;

class Shape
{
    protected:
        int x;
        int y;

    public: 
        Shape();
        Shape(int x, int y);

        virtual ~Shape();
        virtual Shape* copy();

        int getX() const;
        int getY() const;
        void setX(int);
        void setY(int);
        
        virtual void printShape() const;
};

// below this point are the shape class member function definitions

/* shape class default constructor, sets the x and y data members to be zero by default */
Shape::Shape() {
    x = 0;
    y = 0;
}

/* shape class parameterized constructor, sets x and y to be equal to the provided parameter
values for the new x and y values. */
Shape::Shape(int x, int y) {
    this->x = x;
    this->y = y;
}

/* shape class destructor, empty but required */
Shape::~Shape() {}

/* shape class copy function, creates a new shape pointer to a parameter constructed shape object, using
the x and y values from the object on which the copy() function is called. returns the pointer to a shape */
Shape* Shape::copy() {
    Shape* shapeCopy = new Shape(this->getX(), this->getY());
    return shapeCopy;
}

/* shape class getter function for x data member, returns the data member */
int Shape::getX() const {
    return x;
}

/* shape class getter function for the y data member, returns the data member */
int Shape::getY() const {
    return y;
}

/* shape class setter function, sets the x data member to be equal to the new x value
provided via the parameter. */
void Shape::setX(int newX) {
    x = newX;
}

/* shape class setter function, sets the y data member to be equal to the new y value
provided via the parameter. */
void Shape::setY(int newY) {
    y = newY;
}

/* shape class print function. prints out a message containing the x and y data member values */
void Shape::printShape() const {
    cout << "It's a Shape at x: " << x << ", y: " << y << endl;
}


class Circle : public Shape 
{
    private:
        int radius;

    public: 
        Circle();
        Circle(int r);
        Circle(int x, int y, int r);

        virtual ~Circle();
        virtual Circle* copy();
        
        int getRadius() const;
        void setRadius(int);
        
        virtual void printShape() const;
};

// below this point are the Circle class member function definitions

/* circle class default constructor, uses shape class's default constructor for the x and y
data members, and then sets the new data member radius to be equal to zero */
Circle::Circle():Shape() {
    radius = 0;
}

/* circle class single parameter constructor, uses shape class's default constructor for the
x and y values, then sets the radius data member to be equal to the radius parameter */
Circle::Circle(int r):Shape() {
    radius = r;
}

/* circle class fully parameterized constructor. sets the x, y, and radius data members to be
equal to the corresponding x, y, and r parameter inputs. */
Circle::Circle(int x, int y, int r) {
    this->x = x;
    this->y = y;
    radius = r;
}

/* circle class destructor, empty but required */
Circle::~Circle() {}

/* circle class radius getter function, it simply returns the radius data member's integer value */
int Circle::getRadius() const {
    return radius;
}

/* circle class copy function. it creates a new circle pointer to a new circle object created using
the fully parameterized constructor, and then returns that pointer. */
Circle* Circle::copy() {
    Circle* circleCopy = new Circle(this->getX(), this->getY(), this->getRadius());
    return circleCopy;
}

/* circle class radius setter function. sets the radius data member to be equal to the provided
parameter for the new radius value. */
void Circle::setRadius(int newRadius) {
    radius = newRadius;
}

/* circle class print function. Outputs a message with the x, y, and radius data members for that object */
void Circle::printShape() const {
    cout << "It's a Circle at x: " << x << ", y: " << y << ", radius: " << radius << endl;
}


class Rectangle : public Shape 
{
    private:
        int width;
        int height;

    public: 
        Rectangle();
        Rectangle(int w, int h);
        Rectangle(int x, int y, int w, int h);
        
        virtual ~Rectangle();
        virtual Rectangle* copy();
        
        int getWidth() const;
        int getHeight() const;
        void setWidth(int);
        void setHeight(int);
        
        virtual void printShape() const;
};

// below this point, the member function definitions for the rectangle class

/* rectangle class default constructor. calls the shape class's default constructor to set the
x and y values, and then sets the height and width to be 0 */
Rectangle::Rectangle():Shape() {
    width = 0;
    height = 0;
}

/* rectangle class's constructor for the width and height. calls the shape class's default constructor
for the x and y values, and then sets the width and height data members to be equal to the w and h parameter
inputs, respectively */
Rectangle::Rectangle(int w, int h):Shape() {
    width = w;
    height = h;
}

/* rectangle class fully parameterized constructor. sets the x, y, width, and height data members to the values
provided from the x, y, w, and h parameter inputs, respectively. */
Rectangle::Rectangle(int x, int y, int w, int h) {
    this->x = x;
    this->y = y;
    width = w;
    height = h;
}

/* rectangle class destructor, empty but required. */
Rectangle::~Rectangle() {}

/* rectangle class copy function. Creates a rectangle pointer to a new rectangle object created using the fully
parameterized constructor, which uses the data member values from the object on which copy() is called. It then
returns this pointer to this new rectangle object. */
Rectangle* Rectangle::copy() {
    Rectangle* rectangleCopy = new Rectangle(x, y, width, height);
    return rectangleCopy;
}

/* rectangle class width getter function, returns the width of the rectangle object */
int Rectangle::getWidth() const {
    return width;
}

/* rectangle class height getter function, returns the height of the rectangle object */
int Rectangle::getHeight() const {
    return height;
}

/* rectangle class width setter function, sets the width data member's value to be that of the 
parameter providing the new value for the width. */
void Rectangle::setWidth(int newWidth) {
    width = newWidth;
}

/* rectangle class height setter function, sets the height data member's value to be that of the 
parameter providing the new value for the height. */
void Rectangle::setHeight(int newHeight) {
    height = newHeight;
}

/* rectangle class printShape function prints a message containing all of the data members of the 
rectangle class, including those inherited from the shape class */
void Rectangle::printShape() const {
    cout << "It's a Rectangle at x: " << x << ", y: " << y << " with width: " << width << " and height: " << height << endl;
}


class RightTriangle : public Shape 
{
    private:
        int base;
        int height;

    public: 
        RightTriangle();
        RightTriangle(int b, int h);
        RightTriangle(int x, int y, int b, int h);
        
        virtual ~RightTriangle();
        virtual RightTriangle* copy();
        
        int getBase() const;
        int getHeight() const;
        void setBase(int);
        void setHeight(int);

        virtual void printShape() const;
};

// below this point, RightTriangle class member function definitions

/* Default constructor for the RightTriangle class, it sets the base and height data members
to 0 while also calling the shape class's default constructor to set x and y to 0 */
RightTriangle::RightTriangle():Shape() {
    base = 0;
    height = 0;
}

/* base and height parameterized constructor for the RightTriangle class, it sets the base and height data members
to b and h respectively from the parameters  while also calling the shape class's default 
constructor to set x and y to 0 */
RightTriangle::RightTriangle(int b, int h):Shape() {
    base = b;
    height = h;
}

/* Fully parameterized constructor for the RightTriangle class, it sets x, y, base and height to the 
parameter inputs given by x, y, b, and h respectively */
RightTriangle::RightTriangle(int x, int y, int b, int h) {
    this->x = x;
    this->y = y;
    base = b;
    height = h;
}

/* RightTriangle class destructor, empty but required */
RightTriangle::~RightTriangle() {}

/*RightTriangle class copy function, it creates a pointer to a rightTriangle object which is created
using the fully parameterized constructor, copying the data members of the object on which copy() is called.
It then returns this pointer. */
RightTriangle* RightTriangle::copy() {
    RightTriangle* rightTriangleCopy = new RightTriangle(x, y, base, height);
    return rightTriangleCopy;
}

/* getter function for the base data member of the rightTriangle class, returns the base data member's
integer value */
int RightTriangle::getBase() const {
    return base;
}

/* getter function for the height data member, similar to the getBase function, it simply returns the
integer value of the height data member */
int RightTriangle::getHeight() const {
    return height;
}

/* setter function for the base data member of the RightTriangle class, it sets the base data member
to be equal to the new value given as the newBase parameter*/
void RightTriangle::setBase(int newBase) {
    base = newBase;
}

/* setter function for the height data member of the RightTriangle class, it sets the height data member 
to be equal to the new value given as the newHeight parameter */
void RightTriangle::setHeight(int newHeight) {
    height = newHeight;
}

/* the RightTriangle printshape function outputs a message detailing the location of the right triangle
as an x,y pair, as well as the base and the height */
void RightTriangle::printShape() const {
    cout << "It's a Right Triangle at x: " << x << ", y: " << y << " with base: " << base << " and height: " << height << endl;
}
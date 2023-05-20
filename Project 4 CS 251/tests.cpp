/// @filename tests.cpp
/// @date March 7, 2023

// 
// Zohaib Alvi, VSCode on MacOS Ventura 
// Professor Adam Koehler
// Spring 2023 Semester
// CS 251 Project 4: CanvasList
// catch testing tests.cpp file
//
/* This file contains the test cases for the classes in the CanvasList.h and Shape.h files. 
The tests are divided by the class functions on which they test, beginning with the shape class,
then circle, rectangle, right triangle, and then CanvasList */
//

/// Provided testing file to implement
/// framework based tests in. The example
/// below uses the Catch testing framework
/// version that uses a single .hpp file.

// This tells Catch to provide a main()
#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "shape.h"
#include "canvaslist.h"

using namespace std;

// Below this point are the test cases for the Shape, Circle, Rectangle, and Right Triangle classes

TEST_CASE("1: Shape class default constructor and accessors", "[Shape]") {
  Shape s;
  REQUIRE(s.getX() == 0);
  REQUIRE(s.getY() == 0);
}
TEST_CASE("2: Shape class parameterized constructor", "[Shape]") {
  Shape s(2, 4);
  REQUIRE(s.getX() == 2);
  REQUIRE(s.getY() == 4);
}
TEST_CASE("3: Shape class copy function, copying from existing object", "[Shape]") {
  Shape shapeOriginal(1, 2);
  Shape* shapeCopy;
  shapeCopy = shapeOriginal.copy();

  REQUIRE((*shapeCopy).getX() == shapeOriginal.getX());
  REQUIRE((*shapeCopy).getY() == shapeOriginal.getY());
}
TEST_CASE("4: Shape class setter functions", "[Shape]") {
  Shape s;
  s.setX(2);
  s.setY(4);

  REQUIRE(s.getX() == 2);
  REQUIRE(s.getY() == 4);
}
TEST_CASE("5: Shape class print function", "[Shape]") {
  Shape s(1, 5);

  REQUIRE(s.getX() == 1);
  REQUIRE(s.getY() == 5);

  s.printShape();
}

TEST_CASE("6: Circle class default constructor and accessors", "[Circle]") {
  Circle c;

  REQUIRE(c.getRadius() == 0);
  REQUIRE(c.getX() == 0);
  REQUIRE(c.getY() == 0);
}
TEST_CASE("7: Circle class single parameter constructor (radius)", "[Circle]") {
  Circle c(4);

  REQUIRE(c.getRadius() == 4);
  REQUIRE(c.getX() == 0);
  REQUIRE(c.getY() == 0);  
}
TEST_CASE("8: Circle class fully parameterized constructor", "[Circle]") {
  Circle c(1, 3, 5);
  
  REQUIRE(c.getRadius() == 5);
  REQUIRE(c.getX() == 1);
  REQUIRE(c.getY() == 3);  
}
TEST_CASE("9: Circle class copy function, copying from existing object", "[Circle]") {
  Circle circleOriginal(1, 2, 3);
  Circle* circleCopy;
  circleCopy = circleOriginal.copy();

  REQUIRE((*circleCopy).getRadius() == circleOriginal.getRadius());
  REQUIRE((*circleCopy).getX() == circleOriginal.getX());
  REQUIRE((*circleCopy).getY() == circleOriginal.getY());
}
TEST_CASE("10: Circle class setter functions", "[Circle]") {
  Circle c;
  c.setRadius(3);
  c.setY(2);
  c.setX(1);

  REQUIRE(c.getRadius() == 3);
  REQUIRE(c.getX() == 1);
  REQUIRE(c.getY() == 2);
}
TEST_CASE("11: Circle class print function", "[Circle]") {
  Circle c(2, 4, 6);

  REQUIRE(c.getRadius() == 6);
  REQUIRE(c.getX() == 2);
  REQUIRE(c.getY() == 4);
 
  c.printShape();
}

TEST_CASE("12: Rectangle class default constructor and accessors", "[Rectangle]") {
  Rectangle r;

  REQUIRE(r.getWidth() == 0);
  REQUIRE(r.getHeight() == 0);
  REQUIRE(r.getX() == 0);
  REQUIRE(r.getY() == 0);
}
TEST_CASE("13: Rectangle class width and height parameter constructor", "[Rectangle]") {
  Rectangle r(4, 5);

  REQUIRE(r.getWidth() == 4);
  REQUIRE(r.getHeight() == 5);
  REQUIRE(r.getX() == 0);
  REQUIRE(r.getY() == 0);
}
TEST_CASE("14: Rectangle class fully parameterized constructor", "[Rectangle]") {
  Rectangle r(1, 2, 3, 4);

  REQUIRE(r.getWidth() == 3);
  REQUIRE(r.getHeight() == 4);
  REQUIRE(r.getX() == 1);
  REQUIRE(r.getY() == 2);
}
TEST_CASE("15: Rectangle class setter functions", "[Rectangle]") {
  Rectangle r;

  r.setX(1);
  r.setY(2);
  r.setWidth(3);
  r.setHeight(4);

  REQUIRE(r.getWidth() == 3);
  REQUIRE(r.getHeight() == 4);
  REQUIRE(r.getX() == 1);
  REQUIRE(r.getY() == 2);
}
TEST_CASE("16: Rectangle class copy function, copying from existing object", "[Rectangle]") {
  Rectangle r(2, 4, 3, 4);

  Rectangle *newRectangle;
  newRectangle = r.copy();

  REQUIRE((*newRectangle).getX() == r.getX());
  REQUIRE((*newRectangle).getY() == r.getY());
  REQUIRE((*newRectangle).getWidth() == r.getWidth());
  REQUIRE((*newRectangle).getHeight() == r.getHeight());
}
TEST_CASE("17: Rectangle class print function", "[Rectangle]") {
  Rectangle r(1, 2, 3, 4);

  REQUIRE(r.getWidth() == 3);
  REQUIRE(r.getHeight() == 4);
  REQUIRE(r.getX() == 1);
  REQUIRE(r.getY() == 2);

  r.printShape();
}

TEST_CASE("18: Right Triangle class default constructor and accessors", "[Right Triangle]") {
  RightTriangle r;

  REQUIRE(r.getX() == 0);
  REQUIRE(r.getY() == 0);
  REQUIRE(r.getBase() == 0);
  REQUIRE(r.getHeight() == 0);
}
TEST_CASE("19: Right Triangle class base and height constructor, '[Right Triangle]") {
  RightTriangle r(4, 5);

  REQUIRE(r.getBase() == 4);
  REQUIRE(r.getHeight() == 5);
}
TEST_CASE("20: Right Triangle fully parameterized constructor", "[Right Triangle]") {
  RightTriangle r(2, 4, 10, 5);

  REQUIRE(r.getX() == 2);
  REQUIRE(r.getY() == 4);
  REQUIRE(r.getBase() == 10);
  REQUIRE(r.getHeight() == 5);
}
TEST_CASE("21: Right Triangle copy function, copying from existing object") {
  RightTriangle r(1, 2, 3, 4);

  RightTriangle* r2;
  r2 = r.copy();

  REQUIRE((*r2).getX() == r.getX());
  REQUIRE((*r2).getY() == r.getY());
  REQUIRE((*r2).getBase() == r.getBase());
  REQUIRE((*r2).getHeight() == r.getHeight());
}
TEST_CASE("22: Right Triangle setter functions", "[Right Triangle]") {
  RightTriangle r;

  r.setX(2);
  r.setY(4);
  r.setBase(6);
  r.setHeight(8);

  REQUIRE(r.getX() == 2);
  REQUIRE(r.getY() == 4);
  REQUIRE(r.getBase() == 6);
  REQUIRE(r.getHeight() == 8);
}
TEST_CASE("23: Right Triangle class printSHape function", "[Right Triangle]") {
  RightTriangle r(2, 3, 4, 5);

  REQUIRE(r.getX() == 2);
  REQUIRE(r.getY() == 3);
  REQUIRE(r.getBase() == 4);
  REQUIRE(r.getHeight() == 5);

  r.printShape();
}

// Below this point are the test cases for the CanvasList 

TEST_CASE("24: CanvasList default constructor, front() and size() function ensuring front is NULL and size is 0", "[CanvasList]") {
  CanvasList myCanvas;

  REQUIRE(myCanvas.size() == 0);
  REQUIRE(myCanvas.front() == NULL);
}
// test case 25 pushes multiple shapes to the front of the list and pops them sequentially,
// checking the size and front value of the list after each operation
TEST_CASE("25: CanvasList push_front() function and pop_front() function", "[CanvasList]") {
  CanvasList myC; 

  REQUIRE(myC.size() == 0);

  Shape *s = new Shape(2, 5);
  myC.push_front(s);

  REQUIRE(myC.size() == 1);
  REQUIRE(myC.front()->value == s);

  Shape *r = new Rectangle(1, 3, 8, 5);
  myC.push_front(r);

  REQUIRE(myC.size() == 2);
  REQUIRE(myC.front()->value == r);

  delete myC.pop_front();
  REQUIRE(myC.size() == 1);
  REQUIRE(myC.front()->value == s);

  delete myC.pop_front();
  REQUIRE(myC.size() == 0);
  REQUIRE(myC.front() == NULL);
} 
// test case 26 pushes multiple shapes to the back of the list and pops them sequentially,
// checking the size and front value of the list(which shouldnt change beyond the first insert) 
// after each operation, similar to test 25
TEST_CASE("26: CanvasList push_back() function and pop_back() function", "[CanvasList]") {
  CanvasList myC;

  REQUIRE(myC.size() == 0);

  Shape *c = new Circle(2, 5, 4);
  myC.push_back(c);

  REQUIRE(myC.size() == 1);
  REQUIRE(myC.front()->value == c);

  Shape*r = new RightTriangle(1, 2, 3, 4);
  myC.push_back(r);

  REQUIRE(myC.size() == 2);
  REQUIRE(myC.front()->value == c);

  delete myC.pop_back();
  REQUIRE(myC.size() == 1);
  REQUIRE(myC.front()->value == c);

  delete myC.pop_back();
  REQUIRE(myC.size() == 0);
  REQUIRE(myC.front() == NULL);
}
TEST_CASE("27: CanvasList shapeAt() function, testing individual shape objects at each index", "[CanvasList]") {
  CanvasList myC;

  Shape *s = new Shape();
  myC.push_front(s);

  Shape *s2 = new Shape(1, 2);
  myC.push_front(s2);

  Shape *c = new Circle();
  myC.push_back(c);

  REQUIRE(myC.size() == 3);
  REQUIRE(myC.front()->value == s2);
  REQUIRE(myC.shapeAt(1) == s);
  REQUIRE(myC.shapeAt(2) == c);

  delete s;
  delete s2;
  delete c;
}
TEST_CASE("28: CanvasList clear() and isempty() function on multi-element list", "[CanvasList]") {
  CanvasList myC;

  Shape *r = new Rectangle();
  Shape *c = new Circle(1, 2, 3);
  Shape *r2 = new RightTriangle(1, 5, 9, 11);

  myC.push_back(r);
  myC.push_back(c);
  myC.push_front(r2);

  REQUIRE(myC.size() == 3);
  REQUIRE(myC.front()->value == r2);

  myC.clear();

  REQUIRE(myC.size() == 0);
  REQUIRE(myC.front() == NULL); 
  REQUIRE(myC.isempty() == TRUE);

  delete r;
  delete c;
  delete r2;
}
TEST_CASE("29: CanvasList insertAfter() function, tested by using shapeAt()", "[CanvasList]") {
  CanvasList myC;

  Shape *r = new Rectangle();
  Shape *c = new Circle(1, 2, 3);
  Shape *r2 = new RightTriangle(1, 5, 9, 11);
  Shape *s = new Shape();

  myC.push_back(r);
  myC.push_back(c);
  myC.insertAfter(0, r2);
  myC.insertAfter(1, s);

  REQUIRE(myC.size() == 4);
  REQUIRE(myC.front()->value == r);
  REQUIRE(myC.shapeAt(1) == r2);
  REQUIRE(myC.shapeAt(2) == s);

  delete r;
  delete c;
  delete r2;
  delete s;
}
TEST_CASE("30: CanvasList find() function tested to find the first occurance of the x and y parameters", "[CanvasList]") {
  CanvasList myC;

  Shape* s = new Shape(1, 2);
  Shape* c = new Circle(2, 3, 4);
  Shape* c2 = new Circle(2, 3, 5);

  myC.push_back(s);
  myC.push_back(c);
  myC.push_back(c2);

  REQUIRE(myC.find(1, 2) == 0); 
  REQUIRE(myC.find(2, 3) == 1);

  Shape* r = new Rectangle(2, 3, 4, 5);

  myC.push_front(r);

  REQUIRE(myC.find(2, 3) == 0);

  delete s;
  delete c;
  delete c2;
  delete r;
}
TEST_CASE("31: CanvasList operator=() copying an existing list to new one, clearing original, then ensuring non-equivalence", "[CanvasList]") {
  CanvasList original;

  Shape* s = new Shape(1, 2);
  Shape* c = new Circle(2, 3, 4);
  Shape* c2 = new Circle(2, 3, 5);

  original.push_back(s);
  original.push_back(c);
  original.push_back(c2);

  CanvasList copyList = original;

  REQUIRE(copyList.size() == original.size());

  for (int i = 0; i < copyList.size(); i++) {
    REQUIRE(copyList.shapeAt(i) == original.shapeAt(i));
  }

  original.clear();

  for (int i = 0; i < copyList.size(); i++) {
    REQUIRE_FALSE(copyList.shapeAt(i) == original.shapeAt(i));
  }

  delete s;
  delete c;
  delete c2;
}
TEST_CASE("32: CanvasList removeAt() function, removing specific elements of a 4 element list, tested with shapeAt()", "[CanvasList]") {
  CanvasList myC;

  Shape* s = new Shape(1, 2);
  Shape* c = new Circle(2, 8, 4);
  Shape* c2 = new Circle(9, 3, 5);
  Shape* r = new RightTriangle(1, 8, 3, 4);

  myC.push_back(s);
  myC.push_back(c);
  myC.push_back(c2);
  myC.push_back(r);

  REQUIRE(myC.size() == 4);
  REQUIRE(myC.shapeAt(0) == s);

  myC.removeAt(0);
  REQUIRE_FALSE(myC.shapeAt(0) == s);
  REQUIRE(myC.shapeAt(0) == c);
  REQUIRE(myC.front()->value == c);

  myC.removeAt(2);
  REQUIRE(myC.size() == 2);
  REQUIRE(myC.shapeAt(1) == c2);
  REQUIRE(myC.front()->value == c);

  delete c;
  delete c2;
}
/*
  rect.hpp cs1300/code/cpp/classes

  Because every discussion of C++ classes must begin with a rectangle.
 */

// class Rectangle: this means the compiler is parsing a class
// definition. It can have sections of public, protected, and private
// members, as illustrated below.

#import <iostream>

using namespace std;

class Rectangle {
protected:
  int x; // x and y are protected variables. This means that only
  int y; // subclasses and (of course) this class may access them.
  float length;
  float width;

public:
  // This is a constructor. It is called when we allocate memory for a
  // fresh Rectangle.
  Rectangle();

  // cout << "x is: " << x << endl;

  friend ostream &operator << (ostream& out, Rectangle* state);

  // This is a 'mutator' function. It modifies encapsulated data, like
  // the Rectangle's x and y members.
  void setPosition(int x, int y);

  int getX();
  int getY();
};

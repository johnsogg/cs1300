/*
  rect.hpp

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
         // This is called 'encapsulation': we are confident that only
         // authorized code can access these values directly.

public:
  // This is a constructor. It is called when we allocate memory for a
  // fresh Rectangle.
  Rectangle();

  // There's two interesting aspects to this weird function. First,
  // the 'friend' keyword tells the compiler "This function isn't part
  // of the Rectangle class, but it can access all of my private
  // members." The second part is that it is an overloaded operator:
  // Now when we want to print out a Rectangle, we can just throw it
  // into an output stream like cout. E.g. we can do this:
  //   Rectangle* rect = new Rectangle();
  //   cout << rect << endl;
  friend ostream &operator << (ostream& out, Rectangle* state);

  // This is a 'mutator' function. It modifies encapsulated data, like
  // the Rectangle's x and y members.
  void setPosition(int x, int y);

  
};

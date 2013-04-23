/*
  rect_driver.cpp
 */

#include "rect.hpp"
#include<iostream>

using namespace std;

int main () {
  cout << "Hello from the Rectangle Driver" << endl;
  Rectangle foobar;
  Rectangle* icky = new Rectangle();
  cout << "Icky is: " << icky << endl;
  cout << "Foobar is: " << &foobar << endl;
  //  icky->x = -777; // not gonna doit
  icky->setPosition(67, 93);
  cout << "Icky's x is: " << icky->getX() << endl;
  cout << "Foobar's x is: " << foobar.getX() << endl;
}

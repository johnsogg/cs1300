/*
  lec31.cpp

  Code written in lecture.
 */

#include<iostream>

using namespace std;

void data_types() {

  // character data. 256 possible values
  char letter = 'q'; 
  
  // signed integer data. -2147483648 to 2147483647
  int num_things = 42; 

  // boolean data. true or false (1 or 0)
  bool am_i_serious = true; 

  // floating point (decimal) data. +/- 3.4e +/- 38 (~7 digits)
  float standard_decimal = 89.123; 

  // double precision decimal data +/- 1.7e +/- 308 (~15 digits)
  double big_decimal = 283479238.29384723498234;

  cout << "Several variables and how many bytes they require: " << endl;
  cout << "  char letter: " << letter << " size: " << sizeof(letter) << endl;
  cout << "  int num_things: " << num_things << " size: " << sizeof(num_things) << endl;
  cout << "  bool am_i_serious: " << am_i_serious << " size: " << sizeof(am_i_serious) << endl;
  cout << "  float standard_decimal: " << standard_decimal << " size: " 
       << sizeof(standard_decimal) << endl;
  cout << "  double big_decimal: " << big_decimal << " size: " << sizeof(big_decimal) << endl;
}



  void bar(); // forward declaration

  void foo() {
    bar();
  }

  void bar() {
    cout << "in bar!" << endl;
  }

int main() {
  foo();
}

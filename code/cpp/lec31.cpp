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

/**
 * CS 1300 students often want to convert their test scores into
 * percentages. Write a function that returns a floating point
 * percentage given a score and maximum number of points.
 *
 * Example:
 * cout << get_percent(15, 30) << endl;
 * cout << get_percent(23, 30) << endl;
 *
 * This will output 50.0 for the first line and something close to
 * 76.6667 for the second.
 *
 * Notice that percentages range from 0 to 100, not 0 to 1. (hint,
 * hint)
 *
 * If the passed in score is not between 0 and maxpoints (inclusive)
 * return zero. If maxpoints is not positive, return zero.
 *
 * 2 points
 **/
float get_percent(int score, int maxpoints) {
  float result = (float) score / (float) maxpoints;
  result = 100 * result;
  return result;
}

int main() {
  float p = get_percent(22, 43);
  cout << "Student got a " << 22 << " out of " << 43 
       << " got percentage: " << p << endl;
}

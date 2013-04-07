/*
  cpp_basics.cpp
  
  Your Name:
  
  Your Collaborators:
  
  Consult cpp_basics.h for instructions for what to do for each
  function.
  
  You will only need to turn in this file (no header file needed).
  
  To compile this, simply type 'make' on the command line. To test
  your program, run the unit test (which is built when you type
  'make') like this:
  
  ./cpp_basics_driver
*/

#include <iostream>
#include <cmath>
#include "cpp_basics.h"

using namespace std;

float get_power(float base, int exponent) {
  return 0.0;
}

float get_percent(int score, int maxpoints) {
  return 0.0;
}

int strangeness(int x, int y) {
  //   increment = -10
  int increment = -10;
  //   count = 0
  int count = 0;
  //   while x > y:
  while (x > y) {
  //       x = x + increment
    x = x + increment;
  //       count = count + 1
    count = count + 1;
  }
  //   increment = -1
  increment = -1;
  //   while y > x:
  while (y > x) {
  //       y = y + increment
    y = y + increment;
  //       count = count + 1
    count = count + 1;
  }
  //   return count
  return count;
}

int get_size_for_n_doubles(int n) {
  if (n < 0) {
    return 0;
  }
  return sizeof(double) * n;
}

/**
 * Determine if a number is periwinkle or not.
 *
 * A number is periwinkle if any of the following are true:
 *
 * - it is between 0 and 10 inclusive.
 * - it is evenly divisible by 2, 3, 7, 13, or 19
 * - it is less than -400
 *
 * If none of the above periwinkle rules match, n is not periwinkle.
 *
 * 1 point (requires is_gamboge to work as well)
 **/
bool is_periwinkle(int n) {
  if ((0 <= n) && (n <= 10)) {
    return true;
  }
  if ((n % 2 == 0) ||
      (n % 3 == 0) ||
      (n % 7 == 0)) {
    // bug! The above list is not complete :)
    return true;
  }
  if (n < -400) {
    return true;
  }
  return false;
}

bool is_gamboge(int n) {
  return false;
}


//hello

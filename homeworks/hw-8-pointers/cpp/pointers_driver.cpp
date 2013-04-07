/*
  pointers_driver.cpp

  Note to students: this is a weirdo file. Unless you are already a
  C++ pro, this will be baffling, confusing, and (possibly)
  frightening. Just sayin'. Go ahead and look at the unit test code,
  but realize that this is built using crazy C mis-features called
  macros. They're handy but zomg are they confusing.

 */

#include <cmath>
#include "UTFramework.h"
#include "pointers.h"

#define EPSILON 0.0001

using namespace Thilenius;

bool eq(float actual, float expected) {
  return fabs(actual - expected) < EPSILON;
}

int* fib(int n) {
  int* ret = new int[n];
  ret[0] = 1;
  ret[1] = 1;
  for (int i=2; i < n; i++) {
    ret[i] = ret[i-2] + ret[i-1];
  }
  return ret;
}

SUITE_BEGIN("Pointers")
TEST_BEGIN("GetAddrOfNum")
{
  int num = 63;
  int* num_ptr = &num;
  int* s_ptr = get_address_of_number(num);
  IsTrue("Pointers", num_ptr == s_ptr, "Pointers do not have same value");
  if (s_ptr != NULL) {
    IsTrue("Deref Vals", *num_ptr == *s_ptr, "Pointers do not refer to same value");
  } else {
    IsTrue("Null", false, "Function returns NULL");
  }
}TEST_END

TEST_BEGIN("GetDerefVal")
{
  int num = 934;
  int* ptr = &num;
  int result = get_dereferenced_value(ptr);
  IsTrue("Same Val", result == num, "Wrong :(");
}TEST_END

TEST_BEGIN("MakeArr")
{
  int* result = make_array(4);
  if (result == NULL) {
    IsTrue("Null", result != NULL, "Result should not be NULL");
  } else {
    int prev = result[0];
    bool ascending = true;
    bool odd = true;
    for (int i=1; i < 4; i++) {
      if (prev >= result[i]) {
	ascending = false;
	break;
      }
      if (result[i] % 2 != 1) {
	odd = false;
	break;
      }
    }
    if (!ascending) {
      IsTrue("Ascending", false, "Numbers are not in ascending order");
    } else if (!odd) {
      IsTrue("Odd", false, "Numbers are not odd");
    } else {
      IsTrue("Ascending", true, "Numbers are not in ascending order");
      IsTrue("Odd", true, "Numbers are not odd");
    }
  }

}TEST_END

TEST_BEGIN("GetProduct")
{
  float nums[] = { 4.3, 7.7, -1.3, 14.8 };
  float prod = get_product(nums, 4);
  IsTrue("Product", eq(-637.0364, prod), "Wrong :(");
}TEST_END

TEST_BEGIN("MakeFib")
{
  int* res;
  res = make_fib(-2);
  IsTrue("Null", res == NULL, "Should give NULL array when given negative number");
  res = make_fib(0);
  IsTrue("ZeroLen", res != NULL, "Shouldn't give NULL array when given 0");
  res = make_fib(1);
  if (res == NULL) {
    IsTrue("Null", res != NULL, "Should give NULL array");
  } else {
    IsTrue("OneLen", res[0] == 1, "First element should be 1");
  }
  res = make_fib(2);
  if (res == NULL) {
    IsTrue("Null", res != NULL, "Should give NULL array");
  } else { 
    IsTrue("TwoLen", res[0] == 1, "First element should be 1");
    IsTrue("TwoLen", res[0] == 1, "Second element should be 1");
  }
  int* gfib = fib(4000);
  res = make_fib(4000);
  if (res == NULL) {
    IsTrue("Null", res != NULL, "Should give NULL array");
  } else {   
    int i;
    bool ok = true;
    for (i=0; i < 4000; i++) {
      if (gfib[i] != res[i]) {
	ok = false;
	break;
      }
    }
    if (!ok) {
      IsTrue("Large", gfib[i] == res[i], "Wrong :(");
    } else {
      IsTrue("Large", true, "Wrong :(");
    }
  }
}TEST_END

TEST_BEGIN("MakeBurrito")
{
  burrito* b = make_perfect_burrito();
  IsTrue("Null", b != NULL, "Return was NULL");
  if (b != NULL) {
    float weight = 0.0;
    IsTrue("Salsa", eq(b->salsa, 2.5), "Wrong Salsa");
    weight = weight + b->salsa;
    IsTrue("Rice", eq(b->rice, 3), "Wrong Rice");
    weight = weight + b->rice;
    IsTrue("Peppers", b->peppers > 2 && b->peppers < 4, "Wrong Peppers");
    weight = weight + b->peppers;
    IsTrue("Chicken", eq(b->chicken, b->peppers * 2), "Wrong Chicken");
    weight = weight + b->chicken;
    weight = weight + b->beans;     /* add in weight of other things */
    weight = weight + b->cheese;
    weight = weight + b->pork;
    weight = weight + b->steak;
    float veg = 0.0;
    if (weight < 16) {
      veg = 16.0 - weight;
    }
    IsTrue("Veggies", eq(b->veggies, veg), "Wrong Veggies");
  }  
}TEST_END

SUITE_END

int main (int argc, char* argv[]) {	
  UTFrameworkInit;
}

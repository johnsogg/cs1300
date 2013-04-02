/*
  cpp_basics_driver.cpp

  Note to students: this is a weirdo file. Unless you are already a
  C++ pro, this will be baffling, confusing, and (possibly)
  frightening. Just sayin'. Go ahead and look at the unit test code,
  but realize that this is built using crazy C mis-features called
  macros. They're handy but zomg are they confusing.

 */

#include <cmath>
#include "UTFramework.h"
#include "cpp_basics.h"

#define EPSILON 0.0001

using namespace Thilenius;

bool eq(float actual, float expected) {
  return fabs(actual - expected) < EPSILON;
}

SUITE_BEGIN("CPP Basics")
TEST_BEGIN("GetPower")
{
  float res;
  res = get_power(2.4, 3);
  IsTrue("2.4^3", 
	 eq(13.824, res),
	 "Wrong :(");
  res = get_power(2.4, -3);
  IsTrue("2.4^-3",
	 eq(0, res),
	 "Should be zero");
  res = get_power(0, 3);
  IsTrue("0^-3",
	 eq(0, res),
	 "Should be zero");
  res = get_power(0.42, 10);
  IsTrue("0.42^10",
	 eq(0.00017080, res),
	 "Wrong :(");
}TEST_END

TEST_BEGIN("GetPercent")
{
  float res;
  res = get_percent(15, 30);
  IsTrue("15, 30", 
	 eq(50.0, res),
	 "Wrong :(");
  res = get_percent(30, 30);
  IsTrue("30, 30", 
	 eq(100.0, res),
	 "Wrong :(");
  res = get_percent(23, 30);
  IsTrue("23, 30", 
	 eq(76.6667, res),
	 "Wrong :(");
  res = get_percent(-5, 30);
  IsTrue("-5, 30", 
	 eq(0, res),
	 "Wrong :(");
  res = get_percent(30, 15);
  IsTrue("30, 15",
	 eq(0, res),
	 "Wrong :(");
  res = get_percent(43, 50);
  IsTrue("43, 50",
	 eq(86.0, res),
	 "Wrong :(");  

}TEST_END

TEST_BEGIN("Strangeness")
{
  int res;
  res = strangeness(100, 43);
  IsTrue("100, 43",
	 9 == res,
	 "Wrong :(");
  res = strangeness(10, 43);
  IsTrue("10, 43", 
	 33 == res,
	 "Wrong :(");
  res = strangeness(5354, -4332);
  IsTrue("5354, -4332", 
	 973 == res,
	 "Wrong :(");  
  res = strangeness(834, 834);
  IsTrue("834, 834", 
	 0 == res,
	 "Wrong :(");  
}TEST_END

TEST_BEGIN("GetSizeForDoubles")
{
  int res;
  int exp;
  exp = sizeof(double) * 12;
  res = get_size_for_n_doubles(12);
  IsTrue("12 doubles", 
	 exp == res, 
	 "Wrong :(");
  exp = 0;
  res = get_size_for_n_doubles(0);
  IsTrue("0 doubles", 
	 exp == res, 
	 "Wrong :(");
  res = get_size_for_n_doubles(-10);
  IsTrue("-10 doubles", 
	 exp == res, 
	 "Wrong :(");
}TEST_END

TEST_BEGIN("PeriwinkleVsGamboge")
{
  bool isp;
  bool isg;
  int n;
  n = -401;
  isp = is_periwinkle(n);
  isg = is_gamboge(n);
  IsTrue("-401", 
	 isp && !isg,
	 "Wrong :(");
  n = 11;
  isp = is_periwinkle(n);
  isg = is_gamboge(n);
  IsTrue("11", 
	 !isp && isg,
	 "Wrong :(");

  n = 47;
  isp = is_periwinkle(n);
  isg = is_gamboge(n);
  IsTrue("47", 
	 !isp && isg,
	 "Wrong :(");

  n = 55;
  isp = is_periwinkle(n);
  isg = is_gamboge(n);
  IsTrue("55", 
	 !isp && isg,
	 "Wrong :(");

  n = 149;
  isp = is_periwinkle(n);
  isg = is_gamboge(n);
  IsTrue("149", 
	 !isp && isg,
	 "Wrong :(");

  n = 9;
  isp = is_periwinkle(n);
  isg = is_gamboge(n);
  IsTrue("9", 
	 isp && !isg,
	 "Wrong :(");

  n = 16;
  isp = is_periwinkle(n);
  isg = is_gamboge(n);
  IsTrue("16", 
	 isp && !isg,
	 "Wrong :(");

  n = 57;
  isp = is_periwinkle(n);
  isg = is_gamboge(n);
  IsTrue("57", 
	 isp && !isg,
	 "Wrong :(");

  bool ok = true;
  for (int i=-500; i < 500; i++) {
    isp = is_periwinkle(i);
    isg = is_gamboge(i);
    ok = isp ^ isg;
    if (!ok) {
      break;
    }
  }
  IsTrue("-500 to 500",
	 ok,
	 "Something inconsistent.");
}TEST_END

SUITE_END

int main (int argc, char* argv[]) {	
  UTFrameworkInit;
}

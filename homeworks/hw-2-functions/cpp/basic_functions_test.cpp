/*

  basic_functions_test.cpp

  Note:
  The framework will detect and recover from a seg-fault. To see what
  code caused the seg-fault, find the test that ran BEFORE the fault. 
  Then look at the test after it below.
  
  This is the same file that RetroGrade uses to assign scores. The
  good news is that you can run this on your own machine without
  uploading to RetroGrade. To run in RetroGrade mode, run the program
  with the --retrograde flag, like this:
  
  ./basic_functions_test --retrograde

*/
#include "basic_functions.h"
#include "UTFramework.h"
#include <cstring>
#include <iostream>

using namespace Thilenius;
using namespace std;

extern int RETROGRADE_MODE;
// extern void printUsage(char call[]);

void print_vector(const string &label, vector<int> &vals) {
  cout << label << endl;
  for (std::vector<int>::iterator it = vals.begin(); it != vals.end(); ++it) {
    cout << "  " << *it << endl;
  }
}

 SUITE_BEGIN("Basic Functions")

TEST_BEGIN("Four")
{
  int val = return_four();
  IsTrue("Testing Four", val == 4, "Return value should be four.");
  //  IsTrue("Right Null", four != NULL && four->right == NULL, 
  //	 "The node->right field should be null.");
}TEST_END

TEST_BEGIN("AddNumbers")
{
  int val = add_numbers(4, 9);
  IsTrue("4+9", val == 13, "Return value should be 13");
  val = add_numbers(20, -20);
  IsTrue("20 + -20", val == 0, "Return value should be 0");
}TEST_END

TEST_BEGIN("RepeatYourself")
{
  string ret = repeat_yourself("foo", 4);
  string expected = "foofoofoofoo";
  //  IsTrue("Return value not null", ret != NULL, "Return value should not be null.");
  IsTrue("Foo x 4", expected.compare(ret) == 0, "Return string should be foofoofoofoo");

}TEST_END

TEST_BEGIN("AddOneToAll")
{
  int vals[] = { 7, 10, 3, -1, 120 };
  vector<int> source (vals, vals + sizeof(vals) / sizeof(int));
  //  print_vector("source value", source);
  vector<int> ret = add_one_to_all(source);
  IsTrue("Same Size", ret.size() == source.size(), "Return vector should be same as input.");
  if (ret.size() == source.size()) {
    bool ok = true;
    for (int i=0; i < ret.size(); i++) {
      if (ret[i] != source[i] + 1) {
	ok = false;
	break;
      }
    }
    IsTrue("Correct Elements", ok, "Return vector doesn't have right values.");
  }
}TEST_END

TEST_BEGIN("IsOdd")
{
  IsTrue("Testing 8", is_odd(8) == false, "8 is not odd.");
  IsTrue("Testing 9", is_odd(9) == true, "9 is odd.");
}TEST_END

TEST_BEGIN("WhichCoin")
{
  IsTrue("Penny", "Penny" == which_coin(1), "Penny = 1 cent");
  IsTrue("Nickel", "Nickel" == which_coin(5), "Nickel = 5 cents");
  IsTrue("Dime", "Dime" == which_coin(10), "Dime = 10 cents");
  IsTrue("Quarter", "Quarter" == which_coin(25), "Quarter = 25 cents");
}TEST_END

TEST_BEGIN("GetPrimesBelow")
{

  int vals[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89 };
  vector<int> source (vals, vals + sizeof(vals) / sizeof(int));

  vector<int> ret = get_primes_below(90);
  IsTrue("Same Size", ret.size() == source.size(), "Return vector should be same as input.");
  if (ret.size() == source.size()) {
    bool ok = true;
    for (int i=0; i < ret.size(); i++) {
      if (ret[i] != source[i]) {
	ok = false;
	break;
      }
    }

    IsTrue("Correct Elements", ok, "Return vector doesn't have right values.");
  }

}TEST_END

SUITE_END

void printUsage(char call[]) {
  cout << " Usage: " << call << " [--retrograde]" << endl;
}

int main (int argc, char* argv[]) 
{
  if (argc == 2 && strcmp(argv[1], "--retrograde") == 0) RETROGRADE_MODE = 1;
  else if (argc != 1) { 
    printUsage(argv[0]);
    return -1;
  }
  
  UTFrameworkInit;
  
}

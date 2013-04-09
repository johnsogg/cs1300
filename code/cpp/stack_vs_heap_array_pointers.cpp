/*
  stack_vs_heap_array_pointers.cpp

  You may build and run this easily:

  $ make stack_vs_heap_array_pointers
  $ ./stack_vs_heap_array_pointers
  
  Take special note of the compiler warning that you (should) get
  concerning the validity of one of the return parameters:

	stack_vs_heap_array_pointers.cpp:23:10: warning: address of stack memory
	      associated with local variable 'ret' returned [-Wreturn-stack-address]
	  return ret; // ret will be recycled upon return
		 ^~~
	1 warning generated.

  Sample output is pasted at the bottom of this file. Notice how
  make_stack_array gives you an int* that apparently has garbage in
  it.

  See
  http://stackoverflow.com/questions/6441218/can-a-local-variables-memory-be-accessed-outside-its-scope
  for a good, humorous bit on what's going on.
  
 */

#include<iostream>

using namespace std;

void print_array(int numbers[], int n) {
  for (int i=0; i < n; i++) {
    cout << i << ": " << numbers[i] << endl;
  }
}

int* make_stack_array(int num) {
  int ret[num];
  for (int i=0; i < num; i++) {
    ret[i] = i;
  }
  cout << "Before returning make_stack_array:" << endl;
  print_array(ret, 10);
  return ret; // ret will be recycled upon return
}

int* make_dynamic_array(int num) {
  int* ret = new int[num]; // C++ syntax only
  for (int i=0; i < num; i++) {
    ret[i] = i;
  }
  return ret; // ret will be left alone on return
}

int main() {
  int* stack_arr = make_stack_array(10);
  cout << "make_stack_array(10):" << endl;
  print_array(stack_arr, 10);

  int* dynamic_arr = make_dynamic_array(10);
  cout << "make_dynamic_array(10):" << endl;
  print_array(dynamic_arr, 10);
}

/* 

Sample output:

$ ./stack_vs_heap_array_pointers 
Before returning make_stack_array:
0: 0
1: 1
2: 2
3: 3
4: 4
5: 5
6: 6
7: 7
8: 8
9: 9
make_stack_array(10):
0: 8650318
1: 1
2: 0
3: 0
4: 1597769952
5: 32767
6: -1773896469
7: 32767
8: 0
9: 0
make_dynamic_array(10):
0: 0
1: 1
2: 2
3: 3
4: 4
5: 5
6: 6
7: 7
8: 8
9: 9

*/


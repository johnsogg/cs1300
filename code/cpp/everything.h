/*
  everything.h

  Please start reading in everything.cpp. It will send you here
  occasionally, but most of the good stuff is over there.
 */

/* ----------------------------------------------------------------------
  5. Declaring and Defining functions.

  Hopefully you got here from reading through everything.cpp.

  Since this is the header file, we can't (or shouldn't) actually
  define functions here. The purpose of the header file is to
  _declare_ functions: tell the compiler what things are called, what
  they return, and what kinds of parameters they expect.

  All we're going to do here is declare a function called
  `recite_lyrics` that returns nothing and accepts nothing on input.
  Here's how we do that:
*/

void recite_lyrics();

/*
  That's all! 'void' means the function has no return value,
  'recite_lyrics' is the name of the function, the empty parentheses
  mean it takes no input parameters. We close off the statement with a
  semicolon in order to conform to C++'s syntax. Easy.

  Now go back to everything.cpp and continue where you left off.
 */

void data_types();

void if_statements();

void while_loops();

void scope();

void scope_help();

void while_scope();

void for_loops();

void nested_for_loops();

void arithmetic();

void call_functions();

int add_numbers(int first, int second);

float divide(float numerator, float denominator);

void pointer_intro();

void ptr_params();

void add_numbers_and_erase_evidence(int* first, int* second, int* sum);

void strings();

/*
  Part 18: Structures
  
  Here we define a structure for a student, including their name, age,
  and major.
*/

// haven't included <string> yet in this file, so have to do it now.
#include <string>
// also we're not using namespace std, which is where the string type
// lives, so we turn that on now.
using namespace std;

// here is the student structure
struct student {
  string name;
  int age;
  string major;
}; // note the final semicolon is necessary

/*
  Go back to everything.cpp now and continue with part 18 on
  Structures.
 */

void structures();

int get_sum(int numbers[], int n);

void assign_into_slot();

int* make_five_arr();

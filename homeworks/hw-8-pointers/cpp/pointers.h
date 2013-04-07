/*
  pointers.h
 */

// give access to NULL
#include <cstddef>

/**
 * Return the address of a variable. Notice that there's the
 * additional ampersand in "int& x". This is actually a sort of
 * advanced C++ topic (that is not C). We will talk about this next
 * week. For now, you can treat 'x' like a normal variable. This
 * function should be one line long.
 **/
int* get_address_of_number(int& x);

/**
 * Dereference a pointer variable and return the result.
 **/
int get_dereferenced_value(int* p);

/**
 * Create an array with 'how_many' integers in it. Each integer should
 * be larger than the one before it, and they should all be odd. So,
 * valid return arrays might be 1, 3, 5, 9, or maybe 13, 133, 1333,
 * 1333.
 **/
int* make_array(int how_many);

/** 
 * Iterate through an array (with length 'n') and return the product
 * of those numbers (multiply all the array values together).
 **/
float get_product(float numbers[], int n);

/**
 * Create an array of the given size and set its values using an
 * index. Make the first two elements both '1', and each successive
 * element should be the sum of the previous two.
 *
 * If 'n' is less than zero, return NULL.
 *
 * Otherwise, If 'n' is less than 3, set all indexable elements to
 * '1'.
 *
 * HINT: the 'fib' function from the first page of test 3 has the
 * algorithm for doing something very close to this. The values it
 * produces are called the 'Fibonacci Sequence'.
 **/
int* make_fib(int n);

/**
 * The burrito struct is used in the make_perfect_burrito function.
 **/
struct burrito {
  float rice;
  float beans;
  float salsa;
  float peppers;
  float cheese;
  float pork;
  float steak;
  float chicken;
  float veggies;
};

/**
 * Be able to access (read and write) the members of a struct. Create
 * a and return a pointer to a 'burrito' struct. Its members are all
 * floating point numbers that represent the weight (in ounces) of
 * various ingredients. You should set all the members of this struct
 * to 0 with the following exceptions:
 *
 * - I want 2.5 ounces of salsa.
 * - 3 ounces of rice.
 * - More than 2 ounces of peppers (but less than 4).
 * - Twice as much chicken as peppers.
 * - I want the burrito to be at least 16 ounces. If the burrito is
 *   under-weight, add veggies as necessary to make the entire burrito
 *   weigh 16 ounces.
 **/
burrito* make_perfect_burrito();

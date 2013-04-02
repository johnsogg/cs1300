#ifndef __cpp_basics_h__
#define __cpp_basics_h__

/**
 * Returns a non-negative power of the given nonzero base number. For
 * example, get_power(2.4, 3) should be the same as (2.4 * 2.4 * 2.4).
 * 
 * If the base is zero, this function should return zero.
 *
 * If a negative exponent is passed in, this should return zero. (In
 * the real world a negative exponent is totally ok, but for this
 * homework, the requirement is that the function should return zero.)
 *
 * Since (if called correctly) the exponent is positive, you can use a
 * loop to compute the exponent. I recommend a for-loop, but it is
 * possible to use a while loop with an external counting variable.
 *
 * 2 points
 **/
float get_power(float base, int exponent);

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
float get_percent(int score, int maxpoints);

/**
 *
 *
 * Implement the following Python function in C++.

def strangeness(x, y):
    increment = -10
    count = 0
    while x > y:
        x = x + increment
        count = count + 1
    increment = -1
    while y > x:
        y = y + increment
        count = count + 1
    return count

 *
 * Try running the python version using strangeness(100, 43) and
 * strangeness(10, 43). You should get 9 and 33, respectively.
 *
 * 2 points
 **/
int strangeness(int x, int y);

/**
 * Return how many bytes are necessary to store the given number of
 * double-precision floating point numbers in memory. Note that this
 * might vary depending on the computer this runs on.
 *
 * Hint: use the sizeof function.
 *
 * If the given number n is negative, return zero.
 *
 * 2 points
 **/
int get_size_for_n_doubles(int n);

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
bool is_periwinkle(int n);

/**
 * If a number is periwinkle, it is not gamboge. If a number is not
 * periwinkle, it is gamboge. In other words, all numbers are either
 * periwinkle or gamboge. No number is both, and no number is neither.
 *
 * Consider this little known fact next time you have nothing better
 * to do.
 *
 * 1 point (requires is_periwinkle to work as well)
 **/
bool is_gamboge(int n);

#endif


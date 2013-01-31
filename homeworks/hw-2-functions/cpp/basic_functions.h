#include <string>
#include <vector>

/*
 * This function returns the number 4.
 **/
int return_four();

/*
 * Return the sum of the two input values.
 **/
int add_numbers(int first_number, int second_number);

/*
 * Create and a return a string that is composed of the given text,
 * repeated num_times. For example, if I use it like this:
 *
 *  string thrice = repeat_yourself("Sputnik", 3);
 *
 * ... the value of 'thrice' should be "SputnikSputnikSputnik".
 *
 * You might find http://anaturb.net/C/string_exapm.htm useful.
 **/
std::string repeat_yourself(const std::string &text, int num_times);

/*
 * The input 'numbers' is a list of integers. Create and return
 * another list whose contents are the same as 'numbers' but are one
 * larger. For example, if I call this function with a vector
 * containing:
 *
 *  [4, 8, 9, 0]
 *
 *  ... add_one_to_all returns a vector that contains:
 *
 *  [5, 9, 10, 1]
 **/
std::vector<int> add_one_to_all(const std::vector<int> &numbers);

/*
 * Return True or False, depending on if the input number is odd. Odd
 * numbers are 1, 3, 5, 7, and so on. Even numbers are 0, 2, 4, 6, and
 * so on.
 **/
bool is_odd(int num);

/*
 * The input 'cent_value' is a number representing the number of cents
 * of a US coin. Make this function return a string representing which
 * kind of coin it is. Valid inputs and outputs are as follows:
 *
 * 1 ---- "Penny"
 * 5 ---- "Nickel"
 * 10 --- "Dime"
 * 25 --- "Quarter"
 *
 * Remember that computers think that strings like "penny" and "Penny"
 * are different. Be sure you return EXACTLY the right spelling and
 * capitalization.
 **/
std::string which_coin(int cent_value);

/*
    Given an input number 'num', create a vector<int> that contains
    all the prime numbers that are smaller than it. Do not include 1
    or the number itself in the output.

    A prime number is an integer that can be divided evenly only by
    one and itself.

    For example, if this is called with 24, the return vector<int>
    should contain:

    [ 2, 3, 5, 7, 11, 13, 17, 19, 23 ]

    Helpful hint: make a helper function with the signiture:

    bool is_prime(int num);

    That function should return true if the input number is prime or
    not. Then you can write a short (about five line) function here.

    Another helpful hint: Google is your friend.

    A parting helpful hint: TYPE EVERYTHING YOURSELF. Understand
    it. Break it. Fix it. Ask creative questions and then modify your
    code to answer them.
*/
std::vector<int> get_primes_below(int num);


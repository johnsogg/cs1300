/*
  everything.cpp

  Welcome to your C++ crash course! Written by Gabe Johnson.

  This file, along with the associated header file `everything.h`,
  will give you a step-by-step guide to learning C++.

  READ THROUGH THIS FILE, INCLUDING ALL THE COMMENTS, IN SEQUENCE. It
  is meant to be read in order.

 */

/*
  This is a comment in C++. It starts with a slash-asterisk, and ends
  with an asterisk-slash. This is just like in Java.
*/

// This is another comment in C++. It starts with two slashes, but
// ends at the end of the line. It is easier for me to type in the
// multi-line kind of comment, so that's what I'll do.

/* ----------------------------------------------------------------------
  1. Implementation files and Header files.

  C++ programs (like C and Objective-C) are usually broken up into two
  kinds of files: implementation files like this one, and header
  files. Implementation files contain the details of the code. It
  doesn't technically matter what their file extensions are, but you
  really should obey conventions. A plain old C implementation file
  usually has a `.c` extension, while C++ implementation file might
  have `.cc`, `.C`, or `.cpp`.

  Header files usually have the extension `.h`. Sometimes you might
  see a C++ header file with the file extension `.hpp`. These are just
  conventions.

  Recall how in Python how the interpreter needed to know about a
  function before we could successfully call it. The same is true in
  C++, but the way we go about telling the compiler about symbols is
  different. In C++, we use header files to declare functions and
  other things that we'll learn about later. We write all these
  function declarations in a header file, and then we _include_ that
  header file from the implementation file.
*/

/* ----------------------------------------------------------------------
  2. Including a header file.

  Here's how you include a header file:
 */

#include "everything.h"

/*
  Notice how I ended the comment in order to write `#include
  "everything.h"`. Because I wrote that outside of a comment, the
  compiler will see it. If you read this in an editor, it is probably
  syntax colored differently from this comment.
  
  An `include` statement essentially takes the contents of some other
  file and dumps it into the current file as though you typed
  everything in the included file here.

  Check out 'everything.h' to see what that file looks like, but come
  back here when you're done browsing.
 */

/* ----------------------------------------------------------------------
  3. C++ compilers

  A C++ source program is similar to a Python or Java source program:
  it is a bunch of text that humans can read and write. But in order
  for the computer to use the program, it has to be converted into
  another form. This is what the compiler does.

  There are many C and C++ compilers, and the one installed on your
  computer might actually be a different one from mine. But thanks to
  the wonder of standards, they usually behave the same way.

  I will assume you are using a compiler that can be run on the
  command line with the `g++` command. To see if you have this
  compiler, go to a command line and type `which g++`. If it says
  something like `/usr/bin/g++`, then you are ready. If you don't have
  one you'll need to figure out how to install it on your system. For
  OSX, this StackOverflow post will help:

  http://stackoverflow.com/questions/9329243/xcode-4-4-command-line-tools

  From here on out, whenever a line starts with a dollar symbol, that
  means we are typing things on the command line. The dollar symbol is
  just a marker to indicate this. DO NOT TYPE THE DOLLAR SIGN. Lines
  following the command line input that don't have the dollar sign are
  produced by whatever command we just typed. For example:

  $ which g++
  /usr/bin/g++

  That's what you should see when you ask your shell if you have g++
  installed.

  To compile this C++ program with g++, you may type this:

  $ g++ -c everything.cpp

  This should complete silently. We'll talk about compiler errors
  later. The g++ command created an `object file` as output. That's
  what the `-c` flag means. (When using a command line, the little
  things that have a dash followed by a letter is called a
  `flag`. You'll see this a lot.)

  The object file has the same name as the source file, but with the
  file extension `.o`. This contains machine code that you computer
  can directly use. We'll talk more about object files later.

  The program we are working with includes a `main` function, which
  we'll talk about in the next part. This means we can actually
  execute the program. But we need to tell the compiler to generate a
  binary so we can run it. Here's how you do that:

  $ g++ everything.cpp -o everything

  This tells the compiler to compile `everything.cpp` and then
  generate an output binary called `everything`. Remember this
  command, because you will be using it a lot throughout this
  tutorial.

  Now that you've compiled your program, you can run it like this:

  $ ./everything
  Hello, World!

  By default the program should say 'Hello, World!'. We will change
  that throughout the tutorial. Remember how to run your program,
  because you'll do that a lot too. The dot and slash at the beginning
  are important.
 */

/* ----------------------------------------------------------------------
  4. Main

  In order to run a C++ program, it has to have a `main` function
  defined. There can be only one such function in the program,
  otherwise the computer won't know which one to use. 

  You'll want to remember this spot in the file, because you'll be
  coming back here quite often.

  I'm now going to define the main function, but before I can do that
  I have to also take care of some housekeeping things. I'll explain
  these after the main function definition.
 */

#include <iostream>

using namespace std;

int main() {
  //  cout << "Hello, World!" << endl;
  //  recite_lyrics();
  //  data_types();
  //  if_statements();
  //  while_loops();
  //  scope();
  //  for_loops();
  //  nested_for_loops();
  //  arithmetic();
  //  call_functions();
  //  pointer_intro();
  //  ptr_params();
  //  strings();
  structures();
}

/*
  The first housekeeping item was `#include <iostream>`. This is a
  different kind of `include` statement from what we did before. Since
  we used angle braces (instead of quotes), the compiler knows that
  `iostream` is a _library_ that is already installed somewhere on
  your system. 

  The next housekeeping item is the `using namespace std;` line. This
  tells the compiler that for the rest of this file, we can find
  symbols in the standard namespace. This will be important shortly.

  Next, we can finally declare and define the 'main' function. This is
  where we finally start seeing that C++ doesn't look terribly
  different from Java. When we say `int main()`, we are telling the
  compiler: "there's a function declaration called 'main' here. it
  returns an integer, and doesn't expect any input parameters".

  Since we follow that declaration with an opening curly brace (the
  `{` symbol), this means that we are now _defining_ that function as
  well. If instead we had closed off the declaration with a semicolon,
  that would mean that we were simply telling the compiler that this
  function exists and that it shouldn't freak out whenever it sees a
  reference to it any more.

  The function definition is inside the curly braces. Right now, there
  is only one line there. It is:

  cout << "Hello, World!" << endl;

  This might look really weird to you. It's OK. Looks weird to me too.

  The 'cout' should be pronounced "see out". It is an output
  stream. This is C++'s version of Python's "print" or Java's
  "System.out.println()". Instead of using parenthesis, we use that
  funny "<<" punctuation.

  Think of the "<<" like a funnel that directs data into the thing on
  the pointy end. The data we are directing is "Hello, World!", and we
  are directing it to `cout`.

  Then there's one more "<<" followed by `endl`. This means exactly
  what the first part means, though it doesn't look like it. We're
  still directing data into an output stream, but now that data is
  whatever `endl` is. Turns out that `endl` is pronounced "End Line",
  and is a platform-independent way of saying you want to end the line
  you're on.

  The very last thing that we do there is close of the statement with
  a semicolon. Just like Java, C++ ends statements with semicolons.
 */

/* ----------------------------------------------------------------------
  5. Declaring and Defining functions.

  Right now our program just says "Hello, World!" and stops. But we
  could modify the main() function so that it does something
  else. What should it do? Maybe it should call a function and have
  that function do something awesome? Yes, lets do that.

  First thing to do is to _declare_ a function. For this part, please
  hop over to everything.h and find part 5.
*/

/*
  Ok, now that you've read the part in everything.h where we talk
  about declaring a function, now we can actually define that function
  does. We have to match the declaration from the header file exactly:
 */
void recite_lyrics() {
  cout << "Remember when you were young, you shone like the sun." << endl
       << "Shine on you crazy diamond."  << endl
       << "Now there's a look in your eyes, "
       << "like black holes in the sky." << endl
       << "Shine on you crazy diamond." << endl
       << "You were caught in the crossfire of childhood and stardom," << endl
       << "blown on the steel breeze." << endl
       << "Come on you target for faraway laughter," << endl
       << "come on you stranger, you legend, you martyr, and shine!" << endl;
}

/*
  Notice that there's ONE statement in that entire function. We start
  with `cout` and send lots of text and newlines to the output stream,
  but there's only one statement. That statement ends with a
  semicolon.
  
  This is a simple, silly function. Your mission now is to go up to
  the 'main' function and replace what is there so our recite_lyrics()
  function is called instead. Now, main() should look like this:

  int main() {
    recite_lyrics();
  }

*/

/* ----------------------------------------------------------------------
  6. Recompile and re-run your program

  Whenever we move on to a new function, you will need to remember to
  go back up to the main function and have it call the code that we're
  looking at right now.

  Now that you've edited your main function to call recite_lyrics, we
  need to recompile and run our program. Look in Part 3 to recall how
  to do that.
 */

/* ----------------------------------------------------------------------
  7. Data Types

  C++ data types are similar to Java and Python types. Like Java, C++
  is statically typed, so we must know what kind of variable something
  is when we define or use it. The following function shows several of
  the primitive data types defined in C++.

  It also shows you how much memory each type takes. This is important
  for lots of low-level purposes.
  
  This is declared in the header file, but defined here. To see the
  output, update the main() function to call data_types(), and
  recompile and run the program.
 */

void data_types() {
  // give a whole bunch of variable declarations and definitions. A
  // declaration is where you indicate a variable's name and type.

  char letter = 'q'; // 256 possible values
  short int small_counter = -342; // -32768 to 32767
  unsigned short int pos_small_counter = 4734; // 0 to 65535
  int num_things = 42; // -2147483648 to 2147483647
  long int very_big_thing = 2000000000; // -2147483648 to 2147483647
  bool am_i_serious = true; // true or false (1 or 0)
  float standard_decimal = 89.123; // +/- 3.4e +/- 38 (~7 digits)
  double big_decimal = 283479238.29384723498234; // +/- 1.7e +/- 308 (~15 digits)

  cout << "Several variables and how many bytes they require: " << endl;
  cout << "  char letter: " << letter << " size: " << sizeof(letter) << endl;
  cout << "  short int small_counter: " << small_counter  << " size: " 
       << sizeof(small_counter) << endl;
  cout << "  unsigned short int pos_small_counter: " << pos_small_counter << " size: " 
       << sizeof(pos_small_counter) << endl;
  cout << "  int num_things: " << num_things << " size: " << sizeof(num_things) << endl;
  cout << "  long int very_big_thing: " << very_big_thing << " size: " 
       << sizeof(very_big_thing) << endl;
  cout << "  bool am_i_serious: " << am_i_serious << " size: " << sizeof(am_i_serious) << endl;
  cout << "  float standard_decimal: " << standard_decimal << " size: " 
       << sizeof(standard_decimal) << endl;
  cout << "  double big_decimal: " << big_decimal << " size: " << sizeof(big_decimal) << endl;
}

/* ----------------------------------------------------------------------
  8. If Statements

  C++'s if statements are similar to the other languages you have
  seen. You can have a single 'if' that guards some code to execute
  conditionally. You might also have related 'else if' and (zero or
  one) 'else' clauses as well.
 */

void if_statements() {
  int a = 10;
  bool b = false;
  float c = 33.3;

  // can use literals
  if (true) {
    cout << "This always executes!" << endl;
  } else {
    cout << "This never executes!" << endl;
  }

  // can use inequalities
  if (a > 12) {
    cout << "Wrong." << endl;
  }
  
  // can use several else if clauses
  if (a > 12) {
    cout << "Wrong." << endl;
  } else if (a > 8) {
    cout << "This executes because a > 8" << endl;
  } else if (a == 10) {
    // since the 'else if (a > 8)' clause already ran, we will NOT be
    // able to run any subsequent clauses, even if their conditional
    // test would be true. Later conditional tests are not even tried.
    cout << "This never executes because we already ran a clause." << endl;
  } else {
    cout << "This won't run either." << endl;
  }

  // we can nest if-statements inside one another! Look carefully at
  // the arrangement of curly braces. When we start an if statement,
  // everything inside its curly braces is part of that statement,
  // even if there are more if statements *inside*.
  if (c > a) {
    cout << "This runs because c > a" << endl;
    if (b) { // remember b is a bool
      cout << "Won't run because b is false." << endl;
    } else if (a > 12) {
      cout << "Won't run because a is not greater than 12." << endl;
    } else {
      cout << "This runs because neither related clause executed." << endl;
    }
  } else {
    cout << "This won't run." << endl;
  }

}



/* ----------------------------------------------------------------------
  9. While Statements

  A while statement (or a 'while loop') executes some block as long as
  its condition is tested to be true. The while statement tests its
  condition at the beginning of every loop, and ONLY at the beginning
  of every loop.

  See if you can predict what this function is going to output before
  you run it. If you are wrong, study it, play with it by changing
  values. You should understand exactly why while loops run the way
  they do.
*/

void while_loops() {
  bool is_happy = true;
  int a = 10;
  int b = 5;
  // can loop on a boolean variable
  while (is_happy) {
    cout << "Entered loop. is_happy: " << is_happy << ", "
	 << "a: " << a << ", b: " << b << endl;
    if (b < 0) {
      is_happy = false;
    }
    b = b - 2;
    a = a + 10;
  }
  cout << "Exited loop." << endl;

  // can loop on a boolean expression
  while (a > b) {
    cout << "Entered second loop (a > b). a: " << a << ", b: " << b << endl;
    b = b + 10;
    a = a - 3;
  }
  cout << "Exited second loop." << endl;
}

/*
  10. Scope.

  Variables exist only in certain frames, and are only visible from
  certain places. This is called 'scope'. When a variable is declared,
  it will disappear when its scope no longer exists. For example, when
  we declare a variable at the top of a function, the computer
  allocates memory to store that variable. When the function returns,
  that memory is no longer needed because the function is not running
  any longer. The variable is no longer in scope.

  This is useful because it means we don't need to worry about other
  functions overwriting our variables. We can use the same variable
  name in two different functions, for example, and the two can't
  touch each other.
 */
void scope() {
  int number = 100;
  cout << "Inside the 'scope' function.  Variable 'number' is: " << number << endl;
  cout << "About to call scope_help()... " << endl;
  scope_help();
  // the following will print 100.
  cout << "Back in the 'scope' fucntion. Variable 'number' is: " << number << endl;
}

void scope_help() {
  int number = 3;
  // the following will print 3.
  cout << "Inside the 'scope_help' function. Variable 'number' is: " << number << endl;
}

/*
  The concept of scope extends far beyond functions. We can have
  different scopes within a single function, for example. If we
  declare a variable in a while loop, that variable is not available
  outside of that loop.

  Remember, a declaration is when you specify a variable's type and
  name.
 */
void while_scope() {
  int a = 6; // declared outside while loop
  while (a > 0) {
    int b = a + 10; // b is declared INSIDE the while loop
    cout << "a: " << a << ", b: " << b << endl;
  }
  // for a compiler error, uncomment the next line. It will say
  // something like: error: 'b' was not declared in this scope
  // cout << "Exited loop. a: " << a << ", b: " << b << endl;  
}

/* ----------------------------------------------------------------------
  11. For-loops

  A For-loop (also known as a 'for statement') lets us run a loop a
  set number of times, or as long as some condition is true. It gives
  more flexibility than a while loop.

  A C++ for-loop has three parts, just like one of Java's
  for-loops:

  //   ____A__; _____B___; _C_
  for (int i=0; i < limit; i++) {
    // run code that involves i
  }

  I've annotated this for-loop with labels A, B, and C. Here's what
  they mean:

  A: This runs one time when the for-loop is first reached. This is
  almost always used for initializing some counting variable, and
  usually declares it there as well.

  B: This runs at the TOP of each loop, before the block of code
  executes. This tests the condition that lets us know if we should
  run the block of code another time. This should be some kind of
  boolean expression, like an inequality.

  C: This runs at the BOTTOM of each loop, after the block of code
  executes. This is usually used to increment our counting variable.
 */

void for_loops() {
  cout << "Printing the first four squares..." << endl;
  for (int i=0; i < 4; i++) {
    cout << i << " squared is " << (i * i) << endl;
  }
}

/*
  When you run this you will see the output:

  0 squared is 0
  1 squared is 1
  2 squared is 4
  3 squared is 9

  Notice that it does not reach i=4.
 */

/* ----------------------------------------------------------------------
  12. Nested For-Loops

  We can put for loops inside one another. Actually, we can put any
  kind of loop structure inside any other loop structure. This can be
  a little hard to understand, so here's a simple version to introduce
  you to the idea:
*/
void nested_for_loops() {
  cout << "Here's a multiplication table: " << endl;
  for (int i=0; i < 4; i++) { // i will be 0, 1, 2, 3
    for (int j=3; j < 5; j++) { // j will be 3, 4
      cout << i << " * " << j << " = " << (i * j) << endl;
    }
  }
}
/*
  That nested for-loop code outputs the following.

  Here's a multiplication table: 
  0 * 3 = 0
  0 * 4 = 0
  1 * 3 = 3
  1 * 4 = 4
  2 * 3 = 6
  2 * 4 = 8
  3 * 3 = 9
  3 * 4 = 12

  Notice that since the outer loop will have four values for 'i', and
  the inner loop will have only two values for 'j', that the 'cout'
  statement inside everything runs eight times (because 4 * 2 = 8).
 */

/* ----------------------------------------------------------------------
  13. Arithmetic and casting to other data types

  I've skirted this issue long enough. C++ lets us do arithmetic with
  numeric types like ints and floats. This is the same set of
  arithmetic operations we had in Java and Python.

  We sometimes have to 'cast' variables from one type to another in
  order to get the desired effect. For example, if we have an integer
  and would like to divide it in half and receive a fraction, we need
  to cast it to a floating point value. The syntax to cast a variable
  is to use the data type you want in parentheses directly in front of
  the variable:

  int x = 4;
  float x_as_float = (float) x;
*/
void arithmetic() {
  int a = 7;
  int b = 3;
  float af = (float) a;
  float bf = (float) b;
  int int_res;
  float float_res;

  cout << "We'll start with integers..." << endl;
  int_res = a + b; 
  cout << a << " + " << b << " = " << int_res << endl;
  int_res = a - b; 
  cout << a << " - " << b << " = " << int_res << endl;
  int_res = a * b; 
  cout << a << " * " << b << " = " << int_res << endl;
  int_res = a / b; 
  cout << a << " / " << b << " = " << int_res << endl;
  int_res = a % b; 
  cout << a << " % " << b << " = " << int_res << endl;
  
  cout << "Now we'll use floating point numbers..." << endl;
  float_res = af + bf; 
  cout << af << " + " << bf << " = " << float_res << endl;
  float_res = af - bf; 
  cout << af << " - " << bf << " = " << float_res << endl;
  float_res = af * bf; 
  cout << af << " * " << bf << " = " << float_res << endl;
  float_res = af / bf; 
  cout << af << " / " << bf << " = " << float_res << endl;
  // The following lines would cause a compiler error. Uncomment to
  // find out the details.
  //  float_res = af % bf; 
  //  cout << af << " % " << bf << " = " << float_res << endl;

  // You can combine several operations in a chain, like this:
  int_res = a + a * a + a / a - a * a * a;

  // You can group operations using parentheses, which can change the
  // order that operations are performed. We always perform groups
  // completely before leaving them.
  int c = 10;
  int d = 2;
  int e = 5;
  int_res = d - e + c;
  cout << "d - e + c = " << int_res << endl; 
  int_res = d - (e + c);
  cout << "d - (e + c) = " << int_res << endl;
}

/* ----------------------------------------------------------------------
  14. Functions

  Functions are one of the most important concepts in math, and one of
  the most practically useful in computer programming. We can build
  functions that do some work for us, and then give us an answer.

  We've been defining and using functions throughout this tutorial,
  but here's where we dig in and see what they are all about. 

  A function is a piece of _callable_ code. It has:

  * a name, 
  * a return type, and
  * some list of input parameters. 

  So far, all of our functions (other than main) have returned 'void',
  which is a keyword indicating no value. All functions up until this
  point also took no input parameters.

  The next function, 'call_functions' also returns nothing and takes
  nothing as input. But it uses four functions that do take input and
  give values back.
*/
void call_functions() {
  int a = 5;
  int b = 8;
  int c = add_numbers(a, b); // function call using 'a' and 'b' as
			     // input and storing the result in a
			     // variable 'c'.
  cout << "add_numbers(" << a << ", " << b << ") gives result: " << c << endl;

  // The input to a function could be the result of some other function:
  float e = divide(11, add_numbers(2, 3)); // compute e = 11 / (2 + 3)
  cout << "11 / (2 + 3) is: " << e << endl;
}

/*
  Here's one of the functions we just used. Its name is 'add_numbers',
  it returns an integer, and it takes as input two integers called
  'first' and 'second'.
 */
int add_numbers(int first, int second) {
  return first + second; // the specific return value is the sum of
			 // the inputs
}

/*
  Here's the other function we just used. Its name is 'divide', it
  returns a floating point value, and accepts two floating point
  numbers as input, named 'numerator' and 'denominator'.
 */
float divide(float numerator, float denominator) {
  return numerator / denominator; // return the result of dividing one
				  // by the other
}

/* ----------------------------------------------------------------------
  15. Memory Addresses and Pointers

  This is a topic that causes many students to hyperventilate. C and
  all its related languages very explicitly use the fact that we have
  complete control over the computer we're programming. (Or at least,
  within the little sandbox the operating system gives us.) One thing
  we have control over is manipulating specific spots in the
  computer's main memory. C and C++ let us do this using _pointers_.

  Pointers are not unique to C and C++, but they are so explicitly
  available that many otherwise informed people think that other
  languages don't have them. Other languages have them, they just hide
  them in order to prevent you from doing too much damage.

  But like Zed Shaw says in Learn C the Hard Way: "C is truth".
  Pointers are your introduction to the really tricky stuff. Welcome!
*/
void pointer_intro() {
  // here's a simple integer named bob.
  int bob = 42;

  // here's another integer named sue.
  int sue = 23;

  // bob and sue are variables. But more than that, they are our
  // programming labels for some spot in memory that we can read and
  // get values back. If we read their values, we get 42 and 23:
  cout << "bob's value: " << bob << endl;
  cout << "sue's value: " << sue << endl;

  // But one of facts about variables that most programming languages
  // hide from us is that these variables refer to spots in the
  // computer's memory. When we access 'bob', we are really trying to
  // access some location in memory that has the contents we want (in
  // this case, the number 42).
  // 
  // C and C++ can give us the memory address of a variable using the
  // 'address-of' operator. It's an ampersand, used like this:
  cout << "bob's memory address: " << &bob << endl;
  cout << "sue's memory address: " << &sue << endl;

  // When I run this program, those lines output the following:
  //
  //   bob's memory address: 0x7fff56cebb2c
  //   sue's memory address: 0x7fff56cebb28
  //
  // This will be different each time I run the program because
  // different memory cells will be accessed every time I run
  // it. Anyway, what does '0x7fff56cebb2c' mean? This is a number,
  // written in hexadecimal format. This is a number format that has
  // 16 digits, which are:
  //
  // 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, a, b, c, d, e, f.
  //
  // You don't really need to be able to read hex numbers. I only show
  // you to let you know what a memory address looks like when you
  // print it out. Things that look like this are probably memory
  // addresses.
  //
  // What if we want to _store_ the memory location of a variable?
  // This is what pointers are for. Here you go:
  int* bobs_house = &bob;
  int* sues_house = &sue;
  
  // Now we have two new variables, bobs_house and sues_house. They
  // are both of type "int*". You can pronounce this "int
  // star", "int pointer", "pointer to int", or similar.
  //
  // Whenever we use the address-of operator, it gives us a pointer to
  // whatever variable type we are working on. So if we have other
  // variables of different types:
  bool happy = true;
  float liquid = 12.0;
  
  // We can now use the address-of operator to produce pointers to
  // those variables:
  bool* happy_pointer = &happy;
  float* liquid_pointer = &liquid;

  // So now we have bobs_house and sues_house, which are pointers that
  // hold the memory addresses of bob and sue. You can think of the
  // pointer variable as being like somebody's address, and the
  // variable (whatever it points to) like the person who lives there.
  // 
  // There's one more piece of punctuation you have to be aware
  // of. When we have a pointer variable, we can use it to access the
  // _value_ of the memory cell it refers to. In the case of
  // bobs_house, that value is 42. The punctuation we want is called
  // the 'dereference operator', and it is an asterisk used like this:
  cout << "bob-- In memory address " << bobs_house 
       << " lives the value: " << *bobs_house << endl;
  cout << "sue-- In memory address " << sues_house 
       << " lives the value: " << *sues_house << endl;
  
  // One more thing (well, two more things).
  //
  // 1. When you use the address-of operator, the result is a pointer
  // to whatever type you started with.
  //
  // 2. When you use the dereference operator, the result is the value
  // of whatever exists in the memory address the pointer refers to.
  //
  // This means you could have an arbitrary number of levels of
  // indirection:
  
  int x = 643;
  int* x_ptr = &x; // gives pointer-to-int
  
  // Now if we take the address of x_ptr, we'll get a
  // pointer-to-(pointer-to-int):
  int** x_ptr_ptr = &x_ptr;

  // We can do this an arbitrary number of times but it is already
  // getting out of hand:
  int*** crazy = &x_ptr_ptr;

  cout << "x: " << x << endl;
  cout << "x_ptr: " << x_ptr << endl;
  cout << "x_ptr_ptr: " << x_ptr_ptr << endl;
  cout << "crazy: " << crazy << endl;

  // Now using the dereference operator, we can see how to get at the
  // original data by using several of them:
  cout << "*x_ptr: " << *x_ptr << endl;
  cout << "**x_ptr_ptr: " << **x_ptr_ptr << endl;
  cout << "***crazy: " << ***crazy << endl;

  // We can store variables by using the dereference operator as well:
  int val_in_spot = *x_ptr;
  cout << "Initially, x is: " << x << endl;
  cout << "And val_in_spot: " << val_in_spot << endl;

  // If we manipulate memory with a pointer, any time we dereference a
  // pointer that looks at that memory cell will also reflect that
  // change. Notice: we never assign anything into x, yet it changes.
  *x_ptr = 9001;
  cout << "After changing *x_ptr, value of x is now: " << x << endl;
  cout << "*x_ptr is: " << *x_ptr << endl;  
}

/* ----------------------------------------------------------------------
  16. Pointers as function parameters

  We often pass pointers to functions so their values can be read _and
  written_. Here's a simple example of this.
*/
void ptr_params() {
  int a = 94;
  int b = 6;
  int c = 0;
  cout << "Before: a: " << a << ", b: " << b << ", c: " << c << endl;
  // pass in pointers to a, b, and c using the address-of operator.
  add_numbers_and_erase_evidence(&a, &b, &c);
  // Now notice that a, b, c have all changed!
  cout << "After: a: " << a << ", b: " << b << ", c: " << c << endl;
}

/*
  This function accepts pointers to integers. We use the values
  contained in the memory addresses pointed to by first and second to
  compute a sum, and then store that sum in the memory cell referenced
  by the 'sum' parameter. Then, destroy evidence by setting the values
  in memory for first and second to 1 and 2 respectively.
  
  Notice that this function does not return anything, yet it is able
  to manipulate memory so the calling context (the 'ptr_params'
  function above) can see three changes!
 */
void add_numbers_and_erase_evidence(int* first, int* second, int* sum) {
  *sum = *first + *second;
  *first = 1;
  *second = 2;
}

/* ----------------------------------------------------------------------
  17. Using Strings

  C++ gives us a very large toolkit of data types. Mostly these are
  classes or template classes. We'll talk how those are made
  later. For now, we can _use_ them fairly easily.

  One of the more useful classes is called 'string'. This lets us
  write and record sentences. A string in C++ is similar to the
  strings found in Java and Python.

  To gain access to C++ strings we must have this in our file:
*/
#include <string>
/*
  Now we can use strings. Please refer to cplusplus.com for
  documentation on strings. I will show you some of the common
  operations on them.
 */
void strings() {
  string name = "Gabe Johnson";
  cout << "The string '" << name << "' has " << name.size() << " characters" << endl;
  cout << "The character at index 5 is: '" << name[5] << "'" << endl;
  name.append(" wrote this tutorial");
  cout << "After appending to the string, now it reads: '" << name << "'" << endl;
  name.erase(5, 8);
  cout << "After erasing 8 characters starting at index 5, th string is now:" 
       << endl << "'" << name << "'" << endl;
}

/* ----------------------------------------------------------------------
  18. Structures

  We can make compound records using a 'struct'. For example if we
  want to group together information about a particular student, we
  could make a student structure that contains their name, age, and
  major.

  Please refer to the header file for part 18 and see what it looks
  like.
*/
void structures() {
  // we can create a new student like this:
  student* bob = new student;

  // There's a couple things to note there. First, we used the 'new'
  // keyword. This allocates memory for a student structure, and then
  // returns a pointer to it. Since we're getting a pointer to it, the
  // data type for our variable has to be 'pointer to student', in
  // other words, it has to be student*.

  // To read or write values in the structure, we use the arrow
  // operator, like this:
  bob->name = "Bob Smith";
  bob->age = 20;
  bob->major = "Computer Science";
  cout << "Student Name: " << bob->name << endl;
  cout << "Student Age: " << bob->age << endl;
  cout << "Student Major: " << bob->major << endl;

  // The structures in C++ are useful ways to group similar
  // information. We almost always manipulate them using pointers. But
  // if we want to get a 'bare' structure, we can:

  student bare = *bob; // dereferencing type 'pointer-to-student'
		       // yields type 'student'.
  // We also have to use a different operator to access the fields
  // within the structure. Now we use the dot operator:
  cout << "Bare Name: " << bare.name << endl;
  cout << "Bare Age: " << bare.age << endl;
  cout << "Bare Major: " << bare.major << endl;

}

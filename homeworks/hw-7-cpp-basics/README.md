C++ Basics
==========

This is the first in a short but intense series of assignments to test
your ability to program in C++. We will start off by having you write
functions containing loops of various kinds, and doing some simple
arithmetic.

If you weren't in class, or if you were the kid playing minecraft in
the back row, you might have missed these references:

__Learn C the hard way__. Yes, C is not exactly the same as C++, but
for our purposes, learning one is as good as learning the other. C++
_adds_ to C, but it doesn't change much. I haven't found a C program
that can't be compiled with a C++ compiler (though, I haven't looked
very hard).

[http://c.learncodethehardway.org/book/](http://c.learncodethehardway.org/book/)

__everything.cpp__. I also prepared a to-the-point text on learning
C++. It is presented in the form of source code. Begin reading
`everything.cpp` at the top, and read it sequentially. The comments
are especially instructive, so make sure to pay attention.

[https://github.com/johnsogg/cs1300/blob/master/code/cpp/everything.cpp](https://github.com/johnsogg/cs1300/blob/master/code/cpp/everything.cpp)


Getting the Code
=========

You are __strongly__ encouraged to use github to download the code. If
you already have a git repository going, just do:

	$ git pull
	
... and it should just work (unless there are conflicts, in which case
you can resolve that through the cunning use of renaming the offending
files and trying again)

If you _don't_ already have the github repository on your machine:

	$ git clone https://github.com/johnsogg/cs1300.git
	
... that will grab the entire course github repository. The homework
is in `homeworks/hw-7-cpp-basics/cpp/`

Compiling the Code
=========

Get the code first. Got it? Great.

Compile the code by changing directories to where the `cpp_basics.cpp`
file is. Then, run `make`. You should see something like this:

	$ make
	c++ -I/include -g -Wall -Wextra -std=c++0x -c ./UTFramework.cpp
	c++ -I/include -g -Wall -Wextra -std=c++0x -c ./cpp_basics.cpp -o cpp_basics.o
	./cpp_basics.cpp:25:23: warning: unused parameter 'base' [-Wunused-parameter]
	float get_power(float base, int exponent) {
						  ^
	./cpp_basics.cpp:25:33: warning: unused parameter 'exponent'
		  [-Wunused-parameter]
	float get_power(float base, int exponent) {
									^
	./cpp_basics.cpp:29:23: warning: unused parameter 'score' [-Wunused-parameter]
	float get_percent(int score, int maxpoints) {
						  ^
	./cpp_basics.cpp:29:34: warning: unused parameter 'maxpoints'
		  [-Wunused-parameter]
	float get_percent(int score, int maxpoints) {
									 ^
	./cpp_basics.cpp:33:21: warning: unused parameter 'x' [-Wunused-parameter]
	int strangeness(int x, int y) {
						^
	./cpp_basics.cpp:33:28: warning: unused parameter 'y' [-Wunused-parameter]
	int strangeness(int x, int y) {
							   ^
	./cpp_basics.cpp:37:32: warning: unused parameter 'n' [-Wunused-parameter]
	int get_size_for_n_doubles(int n) {
								   ^
	./cpp_basics.cpp:41:24: warning: unused parameter 'n' [-Wunused-parameter]
	bool is_periwinkle(int n) {
						   ^
	./cpp_basics.cpp:45:21: warning: unused parameter 'n' [-Wunused-parameter]
	bool is_gamboge(int n) {
						^
	9 warnings generated.
	c++ -I/include -g -Wall -Wextra -std=c++0x -c ./cpp_basics_driver.cpp
	c++ -I/include -g -Wall -Wextra -std=c++0x -pthread cpp_basics.o cpp_basics_driver.o UTFramework.o -o cpp_basics_driver
	clang: warning: argument unused during compilation: '-pthread'

This is _ok_. It means you have the code, it compiles correctly, but
it doesn't do anything yet.

If you type `make` one more time, it will say `make: Nothing to be
done for 'all'.` This means you haven't edited any source files, so
there's nothing new to do.

You can clean your repository by typing `make clean`. This will remove
all the object files (and emacs backup files~ if you have any). If
there is something strange with your project, trying cleaning your
source tree with this command and then rebuilding everything with
`make`.

Running the Code
=========

Having built the code with `make`, you may now run the driver by
executing the `cpp_basics_driver` file. 

__Note: ALWAYS RUN THE CODE ON YOUR MACHINE BEFORE TURNING IT IN TO
RETROGRADE__. The `cpp_basics_driver` executable is exactly the same
thing that Retrograde will use to test your code. So if it doesn't
work on your local machine, it won't work on RG. Also, if you run it
locally and there is an infinite loop, you will know.

Infinite loops are *bad*.

Here's what that looks like in black and white:

	$ ./cpp_basics_driver 

	Suite: CPP Basics
	|   
	|   Test: GetPower
	|   |   - 2.4^3
	|   |   |   Wrong :(
	|   |   - 2.4^-3
	|   |   - 0^-3
	|   |   - 0.42^10
	|   |   |   Wrong :(
	|   Failed!
	|   
	|   Test: GetPercent
	|   |   - 15, 30
	|   |   |   Wrong :(
	|   |   - 30, 30
	|   |   |   Wrong :(
	|   |   - 23, 30
	|   |   |   Wrong :(
	|   |   - -5, 30
	|   |   - 30, 15
	|   |   - 43, 50
	|   |   |   Wrong :(
	|   Failed!
	|   
	|   Test: Strangeness
	|   |   - 100, 43
	|   |   |   Wrong :(
	|   |   - 10, 43
	|   |   |   Wrong :(
	|   |   - 5354, -4332
	|   |   |   Wrong :(
	|   |   - 834, 834
	|   Failed!
	|   
	|   Test: GetSizeForDoubles
	|   |   - 12 doubles
	|   |   |   Wrong :(
	|   |   - 0 doubles
	|   |   - -10 doubles
	|   Failed!
	|   
	|   Test: PeriwinkleVsGamboge
	|   |   - -401
	|   |   |   Wrong :(
	|   |   - 11
	|   |   |   Wrong :(
	|   |   - 47
	|   |   |   Wrong :(
	|   |   - 55
	|   |   |   Wrong :(
	|   |   - 149
	|   |   |   Wrong :(
	|   |   - 9
	|   |   |   Wrong :(
	|   |   - 16
	|   |   |   Wrong :(
	|   |   - 57
	|   |   |   Wrong :(
	|   |   - -500 to 500
	|   |   |   Something inconsistent.
	|   Failed!
	|   
	Failed!

When you do this on a normal terminal there are lots of pretty colors.

Coding Strategy
=========

Start early.

Focus on one function at a time.

Use lots of `cout` statements. See `everything.cpp` for more examples
than you can possibly want.

Write a little code, then compile. Run it frequently. Repeat. You get
no more points for doing an epic hacking session before dusting off
your compiler.

How To Turn This In
========

Turn in the code by going to RG and submitting your `cpp_basics.cpp`
file. That's the only file you need to turn in. The server has its own
private version of everything else (and will overwrite your version if
you upload it).


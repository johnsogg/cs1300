Homework 1: Linked Lists (15 points)
==========

This homework assignment gives you a chance to build a useful,
real-world data structure called a Linked List.

[Linked Lists Basics](http://cslibrary.stanford.edu/103/LinkedListBasics.pdf)
from Stanford is remarkably legible, and it helpfully uses a similar
simplified coding technique that we will use in this assignment. 

Heap vs. Stack Memory
---------

If you find examples on the web, be aware of this very notable
difference between C and C++: in C you might build a new node like
this:

	struct node* new_node = malloc(sizeof(struct node));
	
In C++ the way we will do it is a bit different:

	node* new_node = new node;
	
In C++, the `new` keyword allocates memory from what is called _the
heap_. This kind of memory is different from _the stack_. 

Variables created with `new` are said to come from _the heap_, and
they are _not_ automatically reclaimed when they are scoped out. The
computer will _not_ clean up after you. If you create lots of
variables with `new` and never clean up after yourself, you'll end up
taking up all sorts of memory that you aren't actually using. This is
called a _memory _leak_.

Variables you create declare inside a function (without using `new`)
are automatically forgotten and reclaimed for other uses when their
scope goes away. We say those variables are in a part of memory called
_the stack_. Since that memory is recycled, they are safe to use
without (much) fear of creating a memory leak.

This is the last time you'll hear about this in CS1300. But be aware:
every time you use `new`, there should be _exactly one_ call to
`delete` somewhere to free that memory. When we are done with a
variable that exists on the heap, we can tell the computer that spot
can be recyled like this:

	delete some_variable;

Instructions
--------

Implement the following functions in `linked_list.cpp`. Use the
provided Makefile to build your program (cd to where your source code
lives, where the Makefile is, and type `make`). You may compile and
run `linked_list_driver` to see how well it works, or not. 

__Do not add a `main` function to your `linked_list.cpp` file.__ This
will cause RetroGrade to choke. Instead, edit the driver's `manual()`
function, and run that code like this:

	./linked_list_driver --manual

The point value for correctly implementing each is given below:

1. init_node = 1 point
1. report = 2 points
1. append_data = 1 point
1. append = 2 points
1. insert_data = 1 point
1. insert = 3 points
1. remove = 3 points
1. size = 1 point
1. contains = 1 point


Homework 2: Functions
=========

Functions are little pieces of code that act sort of like
mini-programs. You can either define your own functions, or you can
use functions that somebody else defined.

Here's a simple function:

	def add_numbers_one_line(a, b):
		return a + b
		
There's a lot going on there. 

__def__: First, we use the keyword `def` to tell Python that we are
about to define a new function. Whatever comes right after that `def`
keyword will be the name of our new function. 

__name__: In this case, the name of the function is
`add_numbers_one_line`.

__parameters__: After the new function's name, we have to provide a
comma-separated list of parameters inside parentheses. In this case,
we have two parameters, `a` and `b`. If you don't have any parameters,
you still have to write the parentheses, there's just nothing between
them.

__colon__: Right after the closing parenthesis, you need a colon
character, `:`.  This tells python that you are about to give it a big
long (or not so long) list of instructions that will be run whenever
you call this function.

__suite__: Python is a unique language in that it keeps blocks of code
together using indentation. You might have looked at other languages
that use lots of curly braces `{ .. }`. Python uses indentation for
the same purpose. The python word for the bunch of code that defines
something is called a `suite`. Everything in a suite shares at least
the same minimum indentation. We'll see advanced examples in a bit.

__statements__: The suite is composed of a bunch of statements. These
are usually single lines of code. In this example, there's only one
statement: `return a + b`.

__return statement__: The return statement is a special statement that
_stops_ execution and sends a value back to wherever the function was
called. To return something, you simply type `return` followed by an
expression. (See the note about expressions below.)

Now that I've given you an anatomy lesson, let's take a look at
another version of this function that has more lines of code, but does
the same thing:

	def add_numbers(a, b):
		print "add_numbers got two things: " + str(a) + " and " + str(b)
		result = a + b
		print "add_numbers is going to return " + str(result)
		return result

You can see the various syntactic structures like `def` and the
parameter list. And in this example the suite is more obvious because
there are four lines that are indented the same amount.

Misc Notes
=========
	
How to give things names
------------

Functions (and all variables) have to be named according to a certain
convention. They can't contain spaces or most kinds of
punctuation. There are rules for naming things like this:

1. They have to start with a letter or the `_` (underscore) character.

2. The rest of the name has to be made up of letters, digits, or
underscore characters.

The name you give these things is called an `identifier`. You might
see that term thrown around when you read stuff on the Internet, so
now you know what it means.

What's an Expression?
--------

An expression is a statement that gives a value. Examples might be
`2+2` or `open('my_file.txt')`. The first expression gives the value
`4`, the other gives a more complicated value---it yields a file
object.

Expressions can be pretty complicated. You might have had a sadistic
math teacher when you were in middle school who asked you to do
something like this:

	( (x + 4 - 2) / (x - 1) ) * ( 10 + (x / 3) )

Cheat Sheet for Test 1
=========

Keywords
=======

The Python interpreter expects you to give it a bunch of `statements`
that it can use to turn code into a running program. Many of the words
in these statements are reserved, which means you shouldn't use them
(and if you do, you'll get errors).

For example, the word `if` is a keyword. I can create a variable
called `foo` like this:

	foo = 3

But if I try to create a variable called `if`, Python complains:
	
	File "<stdin>", line 1
      if = 3
         ^
	SyntaxError: invalid syntax

Here is an _incomplete_ list of keywords. I am only including the ones
we've covered so far, or that I know people have used in the homework.
	
    and: used to combine two truth expressions
	or: used to combine two truth expressions
	is: determines if an expression is true
	not: determines if an expression is not true

    def: used to define a new function
	return: used to give a value back from a function

	if: used in flow control to determine if a suite should execute
	elif: used in flow control to determine if a suite should execute
	else: used in flow control to execute a default suite

	for: used in flow control to begin a loop through something
	in: used in a loop to separate a loop variable from the thing 
	    you're iterating over
	while: a different kind of loop. we haven't covered it yet, but 
	       many students have used it already

	import: used to bring code in from a different place

	pass: used as a standin for a block of code that does nothing
	
	print: a special function that sends text to your screen
	
Comments
=======

A `comment` is text that the interpreter ignores. Comments begin with
a pound sign (`#`) and continue until the end of the line. Example:

	another_age = (your_age / 2) + 7    # compute half your age plus seven

Comments can be helpful for documenting your code. They also are
useful if you want to temporarily disable lines of code.

Literals
=======

A _literal_ is a value that the interpreter can use directly.
	
	4
	4.2
	'this is a string'
	True
	False
	[ 4, 'this is a string', 4.2, True, False ]
	{ 'name' : 'Gabe', 'dog' : 'Sputnik', 'job' : 'CS Instructor' }

Literals produce values that are of a specific type. So in the
examples above, `4` is an integer, `4.2` is a floating point number,
`'this is a string'` is a string, `True` and `False` are the two
boolean values, the thing in the `[ .. ]` square brackets is a list,
and the thing in the `{ .. }` curly braces is an associative array.

We haven't covered associative arrays yet, and they won't be on the
test.

Notice that strings can be defined using either `'single quotes'` or
`"double quotes"`.

Variables
========

A _variable_ is something that we call by name, and it contains a
value. For example, here are some variables.

	an_integer = 4
	a_floating_point_number = 4.2
	my_string = 'this is a string'

Variables are just names we can use to refer to some value. They can
change by assigning new values into them:

	dog_name = "Fluffy"
	dog_name = "Fido"
	dog_name = "Sputnik"
	
Here we just abused the `dog_name` variable by initializing it to
`"Fluffy"`, then changing it to `"Fido"`, and finally arriving at
`"Sputnik"`.

Arithmetic Operations
=========

The standard arithmetic operations for addition, subtraction,
multiplication, and division look like this:

	result = 4 + 2       # addition
	result = 4 - 2       # subtraction
    result = 4 * 2       # multiplication
	result = 4 / 2       # division

When dividing integers, the result will be expressed as an integer as
well. Consider this code:

	result = 17 / 5      # result is now 3

Result is `3` because we are working with integers. If we use at least
one floating point value (literal floating point numbers have to use a
decimal point) it gives us the more accurate answer:

	result = 17.0 / 5    # result is 3.4
	result = 17 / 5.0    # result still 3.4

There is another operator that is commonly used. It is called the
`modulo` operator, and it is represented with the percent sign
(`%`). Modulo gives you the remainder of a division operation.

	result = 17 % 5      # result is 2
	
Division and modulo have a close relationship. Remember when you did
long division as a kid and you would get a result that looked like:

	17 / 5   equals  3, remainder 2
	
The division operator `/` gives us the 3, the modulo operator `%`
gives the 2.

Truth Tests
=======

A truth is one that gives a truth value. We can compare boolean
variables (`True` or `False`) or we can compare numbers or other
items. First some examples, then I'll explain the operators:

	True or False      # True
    False and False    # False
	7 < 10             # True
	10 <= 10           # True
	11 <= 10           # False
    10 == 11           # False

The `and` and `or` operators compare boolean values. A boolean value
is either a literal `True` or `False`, or it is a variable or function
return value that equates to `True` or `False`. We can also use things
that aren't booleans in these statements, but when Python sees
something that isn't a boolean, it converts that thing into a boolean
so it can perform the operation. We haven't seen that yet in class,
though.

We can compare numbers and get a truth value with one of these
operators:

	a == b    # Equality test: does a equal b?
	a < b     # Inequality: is a less than b?
    a <= b    # Inequality: is a less than or equal to b?
	a > b     # Greater than
	a >= b    # Greater than or equal to

Truth values are used most often as the gatekeepers in Loops and If
Statements (see below)

Lists
======

Lists are a nice built-in feature of Python. They give you an ordered
sequence of items: numbers, strings, booleans, even other lists! The
individual items contained in a list don't have to be the same,
either, but for our purposes they've mostly contained integers.

The most common operations with lists are creating them (either from
scratch, or based on a range), and appending to them. We can also
iterate through them (see the second on loops below).

	my_list = [ ]                   # create an empty list named my_list
	other_list = range(3, 20, 4)	# initialize other_list to [3, 7, 11, 15, 19] 
    my_list.append(11)			    # my_list is now [ 11 ]

Other operations you can do with lists are provided here since I
mentioned them in class (briefly), but these will NOT be on the test:

	my_list.insert(20, 4)			# [ 20, 11 ]
	my_list.extend(other_list)		# [20, 11, 3, 7, 11, 15, 19]
	my_list.index(7)				# 3
	my_list.index(999)				# ValueError :(
	my_list.count(11)				# 2
	my_list.sort()					# [3, 7, 11, 11, 15, 19, 20]
	my_list.remove(15)				# [3, 7, 11, 11, 19, 20]
	my_list.pop()	# returns 20, list is now [3, 7, 11, 11, 19]

If Statements
=======

An `if` statement lets you execute blocks of code conditionally. There
are several variants of an `if` statement, summarized thusly:

	# variant 1 has a single gatekeeper condition.
	if (condition):
		<suite>
	
	# variant 2 has a single gatekeeper and an 'else' clause.
	if (condition):
		<suite>
	else:
		<suite>
	
	# variant 3 has any number of 'elif' clauses, which
	# have their own gatekeepers. The final 'else' is optional.
	if (condition1):
		<suite>
	elif (condition2):
		<suite>
	elif (condition3):
		<suite>
	else:
		<suite>
	
The parentheses around the conditions are optional.

When the interpreter sees one of these things with a gatekeeper (an
`if` or an `elif`), it tests the condition. If the condition can be
resolved to True, it runs the block of code below it. Those blocks are
called `suites`, and they are all indented the same amount (one more
than the related `if`).

When one of the suites is executed, _none of the remaining elif
clauses will be tried_. When the suite is executed, the program skips
ahead to the part just below the last clause.

For example:

	thing = "Fruit"
	if thing == "Monkey":
		print "monkey"
	elif thing == "Fruit":
		print "it's fruit!"
	else:
		print "None of the above."
	print "Outside of if statement."

The above prints `it's fruit!`, followed immediately by `Outside of if
statement`.

Note that it is possible that none of the conditions are True. In that
case, the `else` clause runs, if it is present. If the `else` clause
isn't present, that means none of the suites will run.

Loops
=======

A loop is a way to iterate over several values such as a list. There
are a few ways to loop in Python, but so far we've only seen the `for`
loop. Lets say we have a list called `bunch_of_items`. Using this
list, a `for` loop has the following structure.

	for single_item in bunch_of_items:
		<suite>

There's a few things going on here.

__for__: this is the keyword that lets Python know it is going to
enter a loop. When Python sees this it expects the rest to follow.

__single_item__: this is the name that we've chosen to represent an
individual item of the list. You can call it an iteration
variable. The first time through the loop `single_item` will be the
first value in the `bunch_of_items` list; the second time through it
has the second value, and so on.

__in__: this separates the iteration variable name from the list
name. It is just some Python grammar to make it read easier---it is
necessary, though.

__bunch_of_items__: this is the thing that we are going to iterate
over. Technically it doesn't need to be a list, but we've only used
lists in this context as of yet.

__the last colon__: take careful note of the colon character `:` at
the end of that line. It is necessary. Without it you get a syntax
error.

__suite__: this is a block of code that will be executed for each
element in `bunch_of_items`, and the variable `single_thing` is
different each time. The suite should all have the same base
indentation---this means it has to be indented one level from the 'f'
in the `for` keyword.

Functions
=========

Functions are little pieces of code that act sort of like
mini-programs. You can either define your own functions, or you can
use functions that somebody else defined.

Abstractly, here's the syntax for a function definition:

	def <name> ( <parameters> ) :
		<suite of statements>

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
the same purpose. The Python word for the bunch of code that defines
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
	
Names - How to give things names
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

Expressions
--------

An expression is a statement that gives a value. Examples might be
`2+2` or `open('my_file.txt')`. The first expression gives the value
`4`, the other gives a more complicated value---it yields a file
object.

Expressions can be pretty complicated. You might have had a sadistic
math teacher when you were in middle school who asked you to do
something like this:

	( (x + 4 - 2) / (x - 1) ) * ( 10 + (x / 3) )

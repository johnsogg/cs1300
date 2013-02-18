Misc Stuff, and Intro to Objects
==========

This HW is a mixed bag. It is your introduction to objects and
classes. I'm also throwing in some questions about other things that
we haven't talked about before but can't put off any longer.

While Loops
--------

A `while` loop gives us a way to keep doing something as long as some
condition is true. For example, say we were baking a cake. If we were
crazy, we might write the algorithm for baking a cake in the oven like
this (using English, this isn't Python):

1. Put the unbaked cake in the oven.
2. While the cake is not yet done, keep baking it.
3. Take the cake out of the oven.
4. While the cake is too hot to eat, let it cool.
5. Enjoy your cake. 
6. The cake is not a lie!

Since we have experience with cakes and ovens and hot things, we know
how to interpret the above. As long as we're stuck on step 2, we don't
proceed to step 3.

In Python, we can write a `while` loop like this:

	while (condition):
		<suite of code that runs as long as condition is True>

To give a specific example, here's a while loop that keeps looping as
long as we
[say there are five lights](http://www.youtube.com/watch?v=o_eSwq1ewsU).

	response = "4"
	while response == "4":
		response = raw_input("How many lights do you see? ")
		print "You responded: " + response
		if response == "4":
			print "No, you seem to be mistaken. Let's continue..."
	print "Done with loop."

Here's what this does. We initialize `response` to the string
"4". Then, as long as `response` remains "4", we will keep asking how
many lights you see. When you answer anythong other than "4", it
stops, and continues. Once it continues, you see 'Done with loop.'


Boolean Logic
--------

Boolean logic lets us do math with truth statements (`True` and
`False` in Python, `true` and `false` in C++ and Java). For example if
somebody says "It is daytime and it is night time" they just provided
you with two assertions, (the part about day, and the part about
night), and you can combine them in a way to determine if the overall
statement is true. We know from experience that it can't be both day
and night time, so we know the entire statement is false.

But if that person said "It is daytime _or_ it is nighttime", there is
a pretty good chance it is true, depending on how we split the day up. 

In programming languages and many related areas, we can use a small
number of operators to combine truth values. The two most common
boolean operations are `and` and `or`. They work sort of like addition
or multiplication. They work with two inputs. Math people call them
`p` and `q`, but I'll call them `first_thing` and `second_thing`. Here
is everything you need to know about these operations:

	first_thing   second_thing    and    or
	true          true            true   true
	true          false           false  true
	false         true            false  true
	false         false           false  false

In other words:

* An `and` statement is only true when both inputs are true.
* An `or` statement is only false when both inputs are false.

Using this in Python is easy:

	if first_thing and second_thing:
		<code runs when first AND second things are true>
	else:
		<code runs with the other block doesn't>
		
	if first_thing or second_thing:
		<code runs when first OR second thing is true>
	else:
		<code runs if the above block doesn't>

Simple Classes
---------

We refer to real world items by category. In class I gave an example
using a Phone. I have a phone, you have a phone, but they are
different objects. Yet, they are both examples of phones. We can make
sub-categories, too: some phones are made by Samsung, others by
Apple.

This observation of the real world is what led software researchers to
develop the idea of "classes": We could have a class of things called
`Phone`, and then we can make lots of different _instances_ of that
class. The instances are all independent objects that were all defined
based on the `Phone` class.

This week, we're going to take some baby steps with classes in Python.

To relate this to last week's homework on dictionaries, here's how we
might define a `class` for a CU student, rather than using
dictionaries.

First, define the Student class using  the following syntax.

	class Student:
		name = "Unknown Name"
		age = 0
		major = "Unknown Major"

Now that we've defined the Student class, we can create instances:

	s1 = Student()
	s2 = Student()

We access each student's name, age, major, and other 'members' using dot syntax:

	print s1.name
	print s2.major

Right now the instances have the same data. We can customize them by
assigning into the member variables:

	s1.name = "Betty Boop"
	s1.age = 19
	s1.major = "Flapping"

Give Popeye something to do too.

	s2.name = "Popeye"
	s2.age = 26
	s2.major = "Sailor"

Now we can print things to convince each other that the objects really
are independent.

	print "Meet " + s1.name + ", a " + str(s1.age) + " year old majoring in " + s1.major
	print "Also say hello to " + s2.name + " who is a " + s2.major

We can define functions that use objects, like this:

	def greet_student(student):
		print "Hello, " + student.name

And we can call functions that use objects as input:

	greet_student(s1) # prints Hello, Betty Boop
	greet_student(s2) # prints Hello, Popeye

So last week we used this kind of uncomfortable syntax to access data
in a dictionary. Now we can use a cleaner syntax with objects.
 
	mickey = { 'name' : 'Mickey Mouse',
			   'age' : 84,
			   'major' : 'Animation' }

Compare the syntax for these:

	print "Syntax for dictionary: " + mickey['name']
	print "Syntax for objects: " + s1.name

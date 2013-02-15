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

`and` and `or` are your friends.

Simple Classes
---------

We'll do some simple class definitions and make simple objects. No
methods yet, just differenet objects sort of like the dictionary
homework.

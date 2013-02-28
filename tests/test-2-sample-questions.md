Sample Questions (Test 2)
=========

We'll do this test a bit different. This test will be shorter so
everybody can finish in the 50 minutes. Take a test when you come in
(we'll have someone at both doors handing them out). Take a seat and
start right away. I'll stop the test right at 1:50, but you should
have more than enough time to finish this one.

__Don't write a lot. This will be single-word (or number) answer for
all the questions.__

Programming (Writing)
--------

* Define a new class that represents a `Candle`. The candle's member
  variables should be `lit` (a boolean that is false by default), and
  `remaining_wax` (a floating point value that is 4.0 by default). It
  should have a method called `glimmer` that prints out one of the
  following: "Oooh shiny" if it is currently lit, or "Boring!" if it
  is not lit. Every time 'glimmer' is called when the candle is lit,
  it should reduce the amount of remaining wax by 0.1. When the wax
  hits or dips below 0, we should extinguish the candle.
  
* Extra credit: assuming we light the candle, how many times will it
  print 'Oooh shiney' when we call the `glimmer` function?
  
* Write a function that takes a dictionary as input and prints out
  key/value pairs in the following format:

	    key 'foo' has value: 49	  
		key 400 has value: "Tarzan"

* Follow-on question: do we need to know the keys for the dictionary
  in advance? Why or why not?

The following are repeats from first test sample questions. They are
still relevant.


* Write a function that takes a number representing the month and
  prints a message that tells you what season it is. For this question
  assume that Winter is 1 2 3; Spring is 4, 5, 6; Summer is 7, 8, 9;
  Fall is 10 11 12. _The solution for this question is below._
	
* If I want to represent the number of kids I have, what's the most
  appropriate data type? 
  
* If I want to represent a sequence of my kids' ages, what's the most
  appropriate data type? 
  
* If I want to represent my oldest kid's name, what's the most
  appropriate data type? 
  
* If I want to accurately represent my oldest kid's height in meters,
  what's the most appropriate data type?

__Answer to the season question:__

	def(month_num):
		if month_num <= 0 or month_num > 12:
			print "That's not a month!"
	    elif month_num <= 3:
			print "Winter"
		elif month_num <= 6:
			print "Spring"
		elif month_num <= 9:
			print "Summer
		else:
			print "Spring"
  
__The answers to the kid questions are:__

* integer
* list (of integers)
* string
* float

Programming (Reading)
---------

Some of these are adaptations of sample questions from the previous
test. So go over them again---I changed some stuff.

1. Given the following code:

	    for dingle in dongle:
		    print type(dingle)

  What do the following things mean?

  * `for`
  * `dingle`
  * `dongle`

  If I set `dongle = ['a', 3, True, "Yam"]` and then ran that
  for-loop, what would print? What is the value of `dongle` during the
  last time it runs? How many times would the `for` loop iterate?

2. What does the following print out? (The answer is a single number,
not a Russian novel.)

		x = 18
		while (x > 4):
			x = x * 0.5
		print x

3. What are the types of the following literals?

  * 42
  * 42.0
  * "Sputnik"
  * [ 42, 42.0, "Sputnik" ]
  * { 'name' : "Sputnik", 'age' : 4 }
  * True
  * False
  * None

4. Given the following:

		class House:
			num_bedrooms = 2
			num_baths = 3
			# constructor:
	        def __init__(self, br, bath):
				self.num_bedrooms = br
				self.num_baths = bath
			# party method
			def throw_raging_party(self):
				print "Yay! Partay!"
			# cleaning method
			def clean_rooms(self):
				num_cleaned = self.num_bedrooms + self.num_baths
				return num_cleaned

  * What is the return type of `throw_raging_party`?
  * What is the return type of `clean_rooms`? Can you even say for
    certain?
	
  Say that we now do the following:

		my_house = House(3, 4)
		your_house = House(6, 8)
		your_house.clean_rooms()
		my_house.throw_raging_party()

  * What is the type of `House`?
  * What is the type of `my_house`?
  * What is the return type of `my_house.throw_raging_party()`?
  * What specific value does that function return?
  * What is the return type of `your_house.clean_rooms()`?
  * What specific value does that function return?
  
_(Note: the code for this is in `test-2-sample-code.py` if you want to
check it out.)_


__Answer to the dingle/dongle question__

	<type 'str'>
	<type 'int'>
	<type 'bool'>
	<type 'str'>

__Answer to the not-a-russian-novel question__

	2.25
	
__Answer to the literal type question__

	42 is an integer
	42.0 is a floating point
	"Sputnik" is a string
	[ .. ] is a list
	{ .. } dictionary
	True is a boolean
	False is a boolean
	None is None (None is its own type)

__Answers to the House party question__

`throw_raging_party` doesn't return anything explicitly, so the return type is None.

You can't say for sure what the return type of `clean_rooms` is going
to be, though it seems pretty clear it should be an integer. The
reason you can't say for sure is because we haven't given anything a
value 

* `House` is a class
* `my_house` is an instance (of `House`)
* `my_house.throw_raging_party()` returns None, which is of type None
* `your_house.clean_rooms()` returns 14 (that's 8 + 6), which is an integer

Sample Questions (Test 1)

Development
---------

* What do you call the kind of file that contains the human-readable
form of a program?

* What is the meaning of the following three lines that are typed
into a command line interface?

	ls
	pwd
	cd ../my_favorite_place/
	
* What's the common name of the program that interprets and runs
Python programs?

Debugging
--------

For all of the following blocks of code: (a) Spot the bug, (b) propose
  a way to fix it. (Note that there may be more than one bug).
  

	for val in my_list
		print "The value is ", val


	my_name = raw_input('What's your name? ')
	print "Your name is " + my_name
	
	# if the list 'numbers' contains a 3, return it.
	# otherwise, return 0.
	def find_three(numbers):
		for num in numbers:
			if (num = 3):
				return 3
			return 0

Programming
--------

* Write a few lines of code that: (1) asks the user how old they are,
  and (2) prints a message about how old they will be in ten years.
  
* Write a function that takes a list as input and returns the last
  item in that list. If the list is empty it should return None.

* Write a function that takes a number representing the month and
  prints a message that tells you what season it is. For this question
  assume that Winter is 1 2 3; Spring is 4, 5, 6; Summer is 7, 8, 9;
  Fall is 10 11 12.

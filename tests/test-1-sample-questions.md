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

* If you type `python my_awesome_program.py` at the command prompt and it
  gives you the following error, what's the problem?

	    ls: my_wonderful_program.py: No such file or directory

  If you knew that your program was in the directory
  `/home/user/code/my_wonderful_program/`, what is one way you can run
  the program? (There is more than one right answer, you only need to
  give one.)

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
		
	
	# find the sum of all the even numbers in 'numbers'
	result = 0
	for num in numbers:
		if num % 2 == 1:
			result = num

Programming (Writing)
--------

* Write a few lines of code that: (1) asks the user how old they are,
  and (2) prints a message about how old they will be in ten years.
  
* Write a function that takes a list as input and returns the last
  item in that list. If the list is empty it should return None.

* Write a function that takes a number representing the month and
  prints a message that tells you what season it is. For this question
  assume that Winter is 1 2 3; Spring is 4, 5, 6; Summer is 7, 8, 9;
  Fall is 10 11 12.

* Write two lines of code that tests if the number stored in a
  variable called `birthday` is even (it is evenly divisible by two),
  and prints "Hello" if it is.
  
* Write a few lines of code that uses a `for` loop to print "Number
  <n>" where <n> is one of the odd numbers below 14. In other words,
  write a `for` loop that will cause this to be printed:
  
		Hello 1
		Hello 3
		Hello 5
		Hello 7
		Hello 9
		Hello 11
		Hello 13
	
* If I want to represent the number of kids I have, what's the most
  appropriate data type? 
  
* If I want to represent a sequence of my kids' ages, what's the most
  appropriate data type? 
  
* If I want to represent my oldest kid's name, what's the most
  appropriate data type? 
  
* If I want to accurately represent my oldest kid's height in meters,
  what's the most appropriate data type?
  
The answers to the kid questions are:

* integer
* list (of integers)
* string
* float (we didn't cover this in detail)

Programming (Reading)
---------

Given the following code:

	for dingle in dongle:
		print dingle

What's do the following things mean?

* `for`
* `dingle`
* `dongle`

If I set `dongle = ['a', 3, True, "Yam"]` and then ran that for-loop,
what would print? What is the value of `dongle` during the last time
it runs? How many times would the `for` loop iterate?

What does the following code print out?

    #---------------------------------------------------
    x = 4
	y = "Foo"
    print y * x

	#---------------------------------------------------
    for i in range(4):
		print "Go" * i

    #---------------------------------------------------
	weight_a = 10
    weight_b = 50
	weight_c = 70    
	# note that the following is ok since we're using a comma:
    # print "foo", b
	weights = [weight_b, weight_c, weight_a]
    for value in weights:
		print "Weight:", value
    for value in weights:
		if value > 30:
    		print "Heavy thing: ", value

	#---------------------------------------------------
    print "I ain't speakin' proper English!"
	print 'I ain\'t speakin\' proper English!'

    #---------------------------------------------------	
	numbers = range(5, 30, 6)
    print numbers
	for num in numbers:
    	print num * 2

	#---------------------------------------------------
    def math_thing(a, b, c):
		result = (b + c) / a
    	print "Is ((b + c) / a) == a?"
		if (result == a):
    		print "Yes"
		else:
    		print "No"
		return result

    result_1 = math_thing(4, 10, 6)
	result_2 = math_thing(4, 15, 6)
    print "Res 1: " + str(result_1)
	print "Res 2: " + str(result_2)

    #---------------------------------------------------
	def is_green(num):
    	if (num == 5):
			return True
    	elif (num % 3 == 0):
			return True
    	elif (num > 11):
			return True
    	else:
			return False

    for i in range(1, 12):
		print i, ": ", is_green(i)

The actual output for the above code is as follows (separated with the
dashed lines):

    FooFooFooFoo
	-----------------
	
	Go
    GoGo
	GoGoGo
	-----------------
    Weight: 50
	Weight: 70
    Weight: 10
	Heavy thing:  50
    Heavy thing:  70
	-----------------
	I ain't speakin' proper English!
    I ain't speakin' proper English!
	-----------------
	[5, 11, 17, 23, 29]
    10
	22
    34
	46
    58
	Is ((b + c) / a) == a?
    Yes
	Is ((b + c) / a) == a?
    No
	Res 1: 4
    Res 2: 5
	-----------------	
	1 :  False
    2 :  False
	3 :  True
    4 :  False
	5 :  True
    6 :  True
	7 :  False
    8 :  False
	9 :  True
    10 :  False
	11 :  False
	-----------------

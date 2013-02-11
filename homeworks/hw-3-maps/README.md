Python Dictionaries
=========

This homework is about dictionaries, and how they can be used to
collect information about related things. For example, in class we saw
that we could create a dictionary with data about my dog.

	# create an associative array like this:
	dog = { 'name' : 'Sputnik', # dog's name
			'pronoun' : 'he',   # pronoun: he/she/it
			'pos_pron' : 'his', # possessive pronoun: his/her/its
			'age' : 4,          # dog's age (an integer)
			'occupation' : 'Being Awesome', # note last comma is ok
	}
	
A dictionary can be initialized as above, with a bunch of key/value
pairs. Or, we can make an empty dictionary like this:

	empty_dog = { }
	
When we make an empty dictionary we can assign values into it by
inventing keys (which can be a few things, but in all of these
examples they are either strings or integers). We can use this to
assign a value like this:

	empty_dog['age'] = 1
	
Or we can access values like this:

	print empty_dog['age']

Now that we've added something to `empty_dog`, it isn't really empty
anymore. So we can create another dictionary and set it equal to
`empty_dog`:

	puppy = empty_dog

At this point, `empty_dog` and `puppy` refer to the same
dictionary. Anything you do to one is reflected in the other, because
there _is no other_, they are just two names for the same thing. _Am I
blowing your mind yet?_ 

To think of this another way: You can refer to the same person by
different names as well. For example, you might call your mother "Mom"
or "Alice". But I digress.

We can add a bunch of values to our new `puppy` dictionary by
assigning into unused slots:

	puppy['name'] = 'Fluffy'
	puppy['pronoun'] = "she"
	puppy['pos_pron'] = 'her'
	puppy['occupation'] = 'Flopping around playfully'
	
We can overwrite dictionary slots by using a key that is already in
the dictionary:

	puppy['age'] = 2
	puppy['occupation'] = 'Sleeping'

Now that we have some data in our puppy dictionary we can iterate
through it and see what's in there. Iterate over the keys like this:

	for k in puppy.keys():
		print k

That is a very common use case with dictionaries, so the people who
made Python give you a shortcut. You can write it like the following,
with the same effect:

	for k in puppy.keys():
		print k

Inside the for-loop you can also get the value contained in the
dictionary for some key. This is how you do it:

	for k in puppy:
		print "Key: " + str(k) + " --> Value: " + str(puppy[k])
		
This prints the following:

	Key: pos_pron --> Value: her
	Key: age --> Value: 2
	Key: name --> Value: Fluffy
	Key: pronoun --> Value: she
	Key: occupation --> Value: Sleeping
	
Remember the `dog` dictionary from above? We can compare dictionary
contents just like we do normal variables.

	if dog['age'] < puppy['age']:
		print dog['name'], "is younger than", puppy['name']
	else:
		print dog['name'], "is older than (or the same age as)", puppy['name']

You can even write functions that take dictionaries as input, just
like functions can take strings and integers and lists as input.
	
For More Python Dictionaries
-----------

You can read about Python Dictionaries in Zed Shaw's
[_Learn Python The Hard Way_](http://learnpythonthehardway.org/book/ex39.html),
chapter 39.

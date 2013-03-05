from sys import argv

# this is about string interpolation and raw_input
# dog_name = raw_input("What's your dog's name? ")
#cat_name = raw_input("And yer cat's name? ")
## use a Tuple to interpolate your string.
# print "Cool, your dog's name is %s and your cat's name is %s" % (dog_name, cat_name)

# casting to ints
# dog_age = raw_input ("What's your dog's age? ")
# print "The type of dog_age is:"
# print type(dog_age)
# print "Your doggies age is " + dog_age
# dog_age_as_number = int(dog_age)
# dog_age_next = dog_age_as_number + 1
# print "Next year, your dog will be " + str(dog_age_next)

print "What is argv? " + str(type(argv))
prog_name, dog_name, cat_name, dog_age = argv
# prog_name = argv[0] # this is legit too
# dog_name = argv[1]
print "Your program name is: " + prog_name
print "Dog: " + dog_name
print "Cat: " + cat_name
print "Dog Age: " + dog_age

# this demonstrates lists with multiple types in them
my_list = [ ]
my_list.append("Sputnik the awesome doggie")
my_list.append(4)
print my_list


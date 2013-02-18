# first, define the Student class using 
# the following syntax.
class Student:
    name = "Unknown Name"
    age = 0
    major = "Unknown Major"

# Now that we've defined the Student class,
# we can create instances:
s1 = Student()
s2 = Student()

# We access each student's name, age, major,
# and other 'members' using dot syntax:
print s1.name
print s2.major

# Right now the instances have the same data.
# We can customize them by assigning into the
# member variables:
s1.name = "Betty Boop"
s1.age = 19
s1.major = "Flapping"

# Give Popeye something to do too.
s2.name = "Popeye"
s2.age = 26
s2.major = "Sailor"

# now we can print things to convince each other
# that the objects really are independent.

print "Meet " + s1.name + ", a " + str(s1.age) + " year old majoring in " + s1.major

print "Also say hello to " + s2.name + " who is a " + s2.major

# we can define functions that use objects, like this:
def greet_student(student):
    print "Hello, " + student.name

# and we can call functions that use objects as input:
greet_student(s1) # prints Hello, Betty Boop
greet_student(s2) # prints Hello, Popeye

# so last week we used this kind of uncomfortable
# syntax to access data in a dictionary. Now we
# can use a cleaner syntax with objects.
mickey = { 'name' : 'Mickey Mouse',
           'age' : 84,
           'major' : 'Animation' }

# compare the syntax for these:
print "Syntax for dictionary: " + mickey['name']
print "Syntax for objects: " + s1.name


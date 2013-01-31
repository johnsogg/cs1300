my_empty_list = []
print type(my_empty_list)

my_list = [ 1, 7, 10, 2, 5 ]
my_stringy_list = [  "one", "three", "monkey", "foo"] 
my_mixed_list = [ 42, "forty two", True, 61.933, False, None ]

for thing in my_list:
    print "My thing is:" + str(thing)

print ""

for thing in my_stringy_list:
    print "My stringy thing is: " + thing

squares = []
for num in my_list:
    print "num squared is: " + str(num * num)
    square = num * num
    squares.append(square)

print squares

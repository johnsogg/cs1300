def return_four():
    return 4

def add_numbers(red, blue):
    green = red + blue
    print "I got " + str(green)
    return green

my_fav_num = add_numbers(6, 9)
print "On outside: ", my_fav_num

my_other_num = add_numbers(2.5, 3.3)
print "On outside: " + str(my_other_num)




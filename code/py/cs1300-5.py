
def add_one(num):
    value = num + 1
    return value

def show_line(line_num, line_value):
    print str(line_num) + ": " + line_value
    
my_file = open("test-data.txt")
i=0
for my_line in my_file:
    show_line(i, my_line)
    i = i+1

print "I am going to add_one using 41."
result = add_one(41)
print "The result is " + str(result)


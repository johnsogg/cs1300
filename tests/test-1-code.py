my_num = 4
if my_num == 4:
    print "Yay"
else:
    print "Not four."


# find the sum of all the given
# numbers divisible that are by six
numbers = range(25, 40)
result = 0
for num in numbers:
    if num % 6 == 1:
        result = num
print "Result: " + str(result)



def is_purple(num):
    if num > 100:
        return True
    if num < 40:
        return False
    for x in range(2, num):
        if num % x == 0:
            return False
    return True

print "Is 53 purple? " + str(is_purple(num))

def repeat_yourself(text, num_times):
    print text * num_times
    return num_times - 1


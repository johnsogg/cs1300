# we get a list of numbers
# we need to calculate the min, max,
# mean, and median values of this list.

input_data = [6, 9, 3, 2, -4, 10, 14, 3, ] 
# input_data[0] is 6
# input_data[1] is 9
# input_data[2] is 3
# and so on, up to input_data[7] = 3

print input_data

input_data.sort() # you are not responsible for knowing about 'sort()'
print input_data

val = None
for x in input_data:
    val = x
print input_data[0]
print val

# the following gives us the value of the last data cell
print input_data[len(input_data) - 1]

# another way to do this is
print input_data[-1]

print "Now the list is:"
print input_data

# average of 5, 10, 20 is
# (5 + 10 + 20) / 3

# [6, 9, 3, 2, -4, 10, 14, 3, ] 
val = 0 # declare/initialize val out here so
        # it is visible outside the for-loop
n = 0   # same thing.
for x in input_data:
    val = val + x
    n = n + 1
    print n
    # we could also increment 'val' like the following:
    # val += x

# another way of doing this:
# val = sum(list)

print "At the end the sum is", val

mean = val / n
print "The mean is:", mean

floating_mean = float(val) / float(n)
print "The floatin mean is:", floating_mean



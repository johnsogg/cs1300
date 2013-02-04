# we get a list of numbers
# we need to calculate the min, max,
# mean, and median values of this list.

input_data = [6, 9, 3, 2, -4, 10, 14, 3, ] 
# input_data[0] is 6
# input_data[1] is 9
# input_data[2] is 3

print input_data

input_data.sort()
print input_data

val = None
for x in input_data:
    val = x
print input_data[0]
print val

print input_data[len(input_data) - 1]

print "Now the list is:"
print input_data

# average of 5, 10, 20 is
# (5 + 10 + 20) / 3

# [6, 9, 3, 2, -4, 10, 14, 3, ] 
val = 0 # declare/initialize val out here so
        # it is visible outside the for-loop
n = 0   # same thing.
for x in input_data:cd ../lkjaslkfjqdlkgfjewdklv;nlkasjdflkjasdflkahjsdfkjhp[]cvxfguiolfgdxzvfuy80[uyfxgdy9upyfgxip'
    val = val + x
    n = n + 1
    print n
    # val += x
# another way of doing this:
# val = sum(list)

print "At the end the sum is", val

mean = val / n
print "The mean is:", mean

floating_mean = float(val) / float(n)
print "The floatin mean is:", floating_mean



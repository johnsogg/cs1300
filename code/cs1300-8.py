
def is_evenly_div(numer, denom):
    # modulo!
    remainder = numer % denom
    print numer, " % ", denom, " is ", remainder
    if remainder == 0:
        print "It is zero! Evenly divides!"
        return True
    else:
        print "It is", remainder, "and is not evenly divisible"
        return False

blue = 17
green = 7
is_it_divisible = is_evenly_div(blue, green)
print "The type of is_it_divisible is: " + str(type(is_it_divisible))
print "Is it divisible? " + str(is_it_divisible)

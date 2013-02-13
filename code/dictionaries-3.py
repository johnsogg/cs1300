dog = { 'name' : 'Sputnik',
        'age' : 4 }

print dog
print len(dog)

for k in dog:
    print k

for v in dog.values():
    print v

print "What type is dog?"
print type(dog)

print "Is dog a dictionary?"
print type(dog) is dict

print "Is dog a list?" # can do this with
# str, bool, int, float
print type(dog) is list





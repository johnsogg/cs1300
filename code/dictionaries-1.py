# create an associative array like this:
dog = { 'name' : 'Sputnik', # dog's name
        'pronoun' : 'he',   # pronoun: he/she/it
        'pos_pron' : 'his', # possessive pronoun: his/her/its
        'age' : 4,          # dog's age (an integer)
        'occupation' : 'Being Awesome', # note last comma is ok
}

# now you can use the values contained in this dictionary by
# using the 'dog' variable, the square brackets, and the key
# that you're interested in using. Like this:
print "My dog's name is", dog['name']
print dog['pos_pron'], "occupation is", dog['occupation']
print dog['pronoun'], "is", dog['age'], "years old."
print "" # blank line
print "The information for my dog is..."
print dog


buckets = { 0 : 0.42,
            1 : 1.23,
            2 : 183.23 }

print "the buckets variable prints as:", buckets

print "lets iterate over the keys in the buckets dictionary:"
for key in buckets.keys():
    print key, "is a key in the buckets dictionary"
    print "     its value is", buckets[key]

print "iterate over the values in the same way:"
for val in buckets.values():
    print val

print "You can see if the dictionary has a key."
print "Does buckets have key=1?", buckets.has_key(1)
print "Does buckets have key=4?", buckets.has_key(4)

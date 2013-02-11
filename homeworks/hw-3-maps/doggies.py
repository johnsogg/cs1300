 # create an associative array like this:
dog = { 'name' : 'Sputnik', # dog's name
        'pronoun' : 'he',   # pronoun: he/she/it
        'pos_pron' : 'his', # possessive pronoun: his/her/its
        'age' : 4,          # dog's age (an integer)
        'occupation' : 'Being Awesome', # note last comma is ok
        }

empty_dog = { }

empty_dog['age'] = 1
print empty_dog['age']

puppy = empty_dog
print puppy['age']

puppy['name'] = 'Fluffy'
puppy['pronoun'] = "she"
puppy['pos_pron'] = 'her'
puppy['occupation'] = 'Flopping around playfully'

puppy['age'] = 2
puppy['occupation'] = 'Sleeping'

for k in puppy.keys():
    print k

for k in puppy:
    print k

for k in puppy:
    print "Key: " + str(k) + " --> Value: " + str(puppy[k])


if dog['age'] < puppy['age']:
    print dog['name'], "is younger than", puppy['name']
else:
    print dog['name'], "is older than (or the same age as)", puppy['name']

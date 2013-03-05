
# return true if a's name is b's name
# and a's major is b's major
# and a's age is b's age
# return false otherwise
def are_students_the_same(a, b):
    age_same = a['age'] == b['age']
    name_same = a['name'] == b['name']
    major_same = a['major'] == b['major']
    return age_same and name_same and \
        major_same


betty_boop = { 'age' : 20,
               'name' : "Betty",
               'major' : "Sailor" }
popeye = { 'age' : 22,
           'name' : 'Popeye',
           'major' : 'Sailor' }

#are_students_the_same(betty_boop, popeye)
result1 = are_students_the_same(popeye, betty_boop)
result2 = are_students_the_same(popeye, popeye)

if result1:
    print "HUZZAH Result 1 is TRUE!"
else:
    print ":("

if result2:
    print "HUZZAH Result 2 is TRUE!"
else:
    print ":("


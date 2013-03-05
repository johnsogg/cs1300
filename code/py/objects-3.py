# this is the dictionary way of doing
# stuff.
st_d = { 'name' : 'Rufus',
         'age' : 19,
         'major' : 'Basketweaver'}

print st_d['name'] + " is " + str(st_d['age'])

class Student:
    name = "?"
    age = 0
    major = "Undecided"

    def __init__(self, n, a, m):
        self.name = n
        self.age = a
        self.major = m

st_o = Student("Dorp Zirconium", 33, "Music")
# Don't need this since it was passed in with
# the constructor.
# st_o.name = "Rufus"
# st_o.age = 33
# st_o.major = "Music"

print st_o.name + " is " + str(st_o.age)

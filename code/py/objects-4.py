class Student:
    name = "?"
    age = 0
    major = "Undecided"

    def __init__(self, n, a, m):
        self.name = n
        self.age = a
        self.major = m
        print "Made new student", n, a, m

fn = [ "Bob", "Gabe", "Jillian", "Monkeybutter" ]
ln = [ "Jones", "Johnson", "Brown", "Zirconium","Foo" ]

students = []
for i in range(5):
    first = fn[i % len(fn)]
    last = ln[i % len(ln)]
    s = Student(first + " " + last, 20, "BA in CS")
    students.append(s)

print "Made", len(students), "students"
print students

for stud in students:
    if stud.name == "Gabe Johnson":
        stud.major = "Underwater Basketweaving"
        break

for stud in students:
    print stud.name, "is a", stud.major, "major"


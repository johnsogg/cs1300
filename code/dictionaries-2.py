student_1 = { }

print "Printing our empty dictionary..."
print student_1
print "The type of that thing is:"
print type(student_1)
student_1['age'] = 20
student_1['major'] = "Theater"
print "The age of this student is:"
print student_1['age']
print "The student's major is:"
print student_1['major']

student_2 = { 'age' : 42,
              'major' : 'MCDB',
              'in_state' : False,
             }

print "The other student is", student_2['age'], "years old."

def print_student(a_student):
    print "*** PRINTING STUDENT! ***"
    print "Age: " + str(a_student['age'])
    print "Major: ", a_student['major']
    

print_student(student_1)
print_student(student_2)

def switch_majors(a_student, new_major):
    a_student['major'] = new_major

switch_majors(student_2, "CSCI")
print_student(student_2)

student_1['address'] = "1234 White Str."
student_1['phone'] = "8675309"

print "\nNow I'll show you the keys."
for k in student_1.keys():
    print "A key is:", k
print "\nNow I'll show you the value."
for v in student_1.values():
    print "A value is:", v
print "\nNow I'll show you the pairs."
for keyval in student_1.keys():
    print "The key", keyval, " --> ", student_1[keyval]




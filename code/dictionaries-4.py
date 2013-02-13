# this is the implementation of the get_student_dictionary_as_list
# function. The other functions were just examples (and I didn't try
# running them, so there is likely a problem with those.)

# param: 'student'. it is a dictionary.
# output: a list containing name, major, age
def get_student_dictionary_as_list(student):
    ret_list = [ ]
    ret_list.append(student['name'])
    ret_list.append(student['major'])
    ret_list.append(student['age'])
    return ret_list

def get_student_dictionary_wrong(student):
    ret_list = [ ]
    # student.keys() looks like
    #             ['name', 'major', 'age']
    # or
    # it might be ['age', 'major', 'name']
    # it might not be the order you want
    for k in student.keys():
        if k == 'age':
            ret_list[2] = student[k]
        elif k == 'major':
            pass
        elif k == 'name':
            ret_list[0] = student[k]
        ret_list.append(student[k])
    return ret_list

def do_it_really_wrong(student):
    ret_list = [ 'Gandalf', 'Wizardry', 23093 ]
    for k in student:
        if k == 'name':
            ret_list[0] = student[k]

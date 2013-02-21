#include <string>

using namespace std;

class Student {
 public:
  string name;
  int age;
  string major;
};

/**
 * Create and return a student object whose name, age, and major are
 * the same as those given as input here.  - 1 point
 **/
Student make_student(string name, int age, string major);

/**
 * Add one to the given student's age. This function doesn't return
 * anything! So all you need to do is increment the student's age, and
 * if student looks one year older after this function completes, you
 * did your job.  - 2 points
 **/
void make_student_older(Student &student);

/**
 * create and return a new Student object that has the same name, age,
 * and major as the input student.  - 2 points
 **/
Student copy_student(Student &student);

/**
 * Most college students are younger than 23. We'd like to know if
 * this student is older than 23. Return True if that is the case.  -
 * 1 point
 **/
bool is_older(Student &student);

/**
 * Musicians are a lot of fun, so let's find out if the student's
 * major is 'Music' or not. Return True if the major is 'Music'.  - 1
 * point
**/
bool is_musician(Student &student);

/**
 * A little known fact: musicians older than 23 have substantially
 * more fun than other people. Return True only if the given student
 * is both a musician and is older than 23.  - 3 points
 **/
bool is_older_musician(Student &student);

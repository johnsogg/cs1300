/*

  objects_driver.cpp

*/

#include <cstring>
#include <cstdlib>
#include "objects.h"
#include "UTFramework.h"

using namespace Thilenius;
using namespace std;

extern int RETROGRADE_MODE;


Student mkstud(string n, int a, string m);
Student* mkstuds();

Student mkstud(string n, int a, string m) {
  Student s;
  s.name = n;
  s.age = a;
  s.major = m;
  return s;
}

Student* mkstuds() {
  Student* ret = new Student[4];
  ret[0] = mkstud("James Bond", 38, "Bartending");
  ret[1] = mkstud("Charlie Parker", 50, "Music");
  ret[2] = mkstud("Marky Mark", 20, "Music");
  ret[3] = mkstud("Bob Bobson", 21, "Landscape Architecture");
  return ret;
}

SUITE_BEGIN("Sorting")

//  IsTrue("Returned A Node", four != NULL, 
//	 "A Null node was returned by the init_node( ) function.");

TEST_BEGIN("MakeStudent")
{
  Student s = make_student("Bob", 19, "Spelunking");
  IsTrue("Checking Student Name", 
	 s.name == "Bob",
	 "Name was not the same.");
  IsTrue("Checking Student Age", 
	 s.age == 19,
	 "Age was not the same.");
  IsTrue("Checking Student Major", 
	 s.major == "Spelunking",
	 "Major was not the same.");

}TEST_END

TEST_BEGIN("MakeStudentOlder")
{
  Student* studs = mkstuds();
  for (int i=0; i < 4; i++) {
    Student s = studs[i];
    int a = s.age;
    make_student_older(s);
    IsTrue("Ensuring Age is Higher",
	   s.age == (a + 1),
	   "Age was wrong.");
  }
}TEST_END

TEST_BEGIN("CopyStudent")
{
  Student* studs = mkstuds();
  for (int i=0; i < 4; i++) {
    Student s = studs[i];
    Student s_copy = copy_student(s);
    IsTrue("Copied Name", s_copy.name == s.name, "Copied name was wrong.");
    IsTrue("Copied Age", s_copy.age == s.age, "Copied age was wrong.");
    IsTrue("Copied Major", s_copy.major == s.major, "Copied major was wrong.");
  }
}TEST_END

TEST_BEGIN("IsOlder")
{
  Student* studs = mkstuds();
  IsTrue("Check Older", is_older(studs[0]), "Age 38 is older than 23.");  // 38
  IsTrue("Check Older", is_older(studs[1]), "Age 50 is older than 23.");  // 50
  IsTrue("Check Older", !is_older(studs[2]), "Age 20 is not older than 23."); // 20
  IsTrue("Check Older", !is_older(studs[3]), "Age 21 is not older than 23."); // 21
}TEST_END

TEST_BEGIN("IsMusician")
{
  Student* studs = mkstuds();
  IsTrue("Check Music", !is_musician(studs[0]), "Is not a musician."); 
  IsTrue("Check Music", is_musician(studs[1]), "Is a musician."); 
  IsTrue("Check Music", is_musician(studs[2]), "Is a musician.");
  IsTrue("Check Music", !is_musician(studs[3]), "Is not a musician.");


}TEST_END

TEST_BEGIN("IsOlderMusician")
{
  Student* studs = mkstuds();
  IsTrue("Check Older Music", !is_older_musician(studs[0]), "Is not an older musician.");
  IsTrue("Check Older Music", is_older_musician(studs[1]), "Is an older musician.");
  IsTrue("Check Older Music", !is_older_musician(studs[2]), "Is not an older musician.");
  IsTrue("Check Older Music", !is_older_musician(studs[3]), "Is not an older musician.");

}TEST_END

SUITE_END

void printUsage(char call[]) {
  cout << " Usage: " << call << " [--retrograde]" << endl;
}

int main (int argc, char* argv[]) 
{

  if (argc == 2 && strcmp(argv[1], "--retrograde") == 0) RETROGRADE_MODE = 1;
  else if (argc != 1) { 
    printUsage(argv[0]);
    return -1;
  }
  
  UTFrameworkInit;
  
}

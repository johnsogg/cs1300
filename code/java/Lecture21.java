// this is a one-line comment

/*

   This is a mult-line
   comment
   that has many lines
   can you see?

*/

public class Lecture21 {
    public static void main(String[] args) {
	System.out.println("Hello World");
	char my_char = 'd';
	// In Python, the following is...
	// print "my_char is" + my_char
	System.out.println("my_char is " + my_char);
	// In Python the following integer printing...
	// my_num = 42
	// print "my_num is" + str(my_num)
	int my_num = 42;
	System.out.println("my_num is " + my_num);
	// You can't use the comma like this:
	// System.out.println("my_num is", my_num);
	String my_awesome_string = "Foobar! Hi.";
	System.out.println("awesome: " +
			   my_awesome_string);
	float my_f = 7.5f;
	float other_f = (float) 49.43;
	System.out.println("my_f: " + my_f);
	double myDouble = 7.5;
	double myOtherDouble = 7.5d; // WHY????
	double myLastDouble = 7d; // same as 7.0
    }
}

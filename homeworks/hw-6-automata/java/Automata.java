/*
    Automata.java

    See the README.md in the homework directory.

    Your Name:

    Your Collaborators:

    There are several methods for you to implement below. They are
    indicated with IMPLEMENT THIS METHOD. Instructions are embedded
    within. Happy hacking!

 */
import java.util.Map;
import java.util.HashMap;
import static java.lang.System.out;

public class Automata {
    // this is a main function that runs if we happen to run the
    // Automata class. This is *not* what RetroGrade uses. It is here
    // for you to test things out on your own.

    // pattern #1 is small and can be used for testing.
    final static String PATTERN_1 = "  *    *  *      *  *      *";
    // if you use PATTERN_2, you'll think there's a bug. There isn't :)
    final static String PATTERN_2 = " * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *";
    final static String PATTERN_3 = "                                 *                                                            ";

    public static void main(String[] args) {
	// create a new Automata instance and call it 'grover'.
	Automata grover = new Automata();

	// Add simple rules. Note that "x" is a string, but 'x' is a
	// char. The type of quote matters. Feel free to change
	// these. The default values I'm giving you are the ones for
	// the Sierinski triangle (read the wikipedia page for 'Rule
	// 90') if you want to see why this works.
	grover.addRule("***", ' ');
	grover.addRule("** ", '*');
	grover.addRule("* *", ' ');
	grover.addRule("*  ", '*');
	grover.addRule(" **", '*');
	grover.addRule(" * ", ' ');
	grover.addRule("  *", '*');
	grover.addRule("   ", ' ');

	// Give grover a starting pattern.
	String pat = PATTERN_1; // change to 1, 2, 3, or your own.
	grover.setInitialPattern(pat); 

	// Now that we have a rule set and an initial pattern, we can
	// tell grover to print out the initial state and then iterate
	// through some number of cycles.
	grover.printPrev();
	grover.run(pat.length()); // makes a square image
    }

    // Declare the member variables associated with instances of this class.
    private Map<String, Character> rules;
    private char[] prev;

    public Automata() {
	// create a new Map that relates String keys to char
	// values. then assign it to the object's "rules" member
	// variable.
	this.rules = new HashMap<String, Character>();
    }

    public void addRule(String pattern, char output) {
	// Associate this pattern with an output char. In Python this
	// would be like the following (if 'rules' is a dictionary):
	//   rules[pattern] = output
	rules.put(pattern, output);
    }

    public char applyRule(String pat) {
	// this is done for you.
	char ret = '?';
	if (!rules.containsKey(pat)) {
	    out.println("Warning: the rule map does not have a key '" + pat + "'");
	} else {
	    ret = rules.get(pat);
	}
	return ret;
    }

    public void printPrev() {
	// This is done for you. It prints the previous state.
	if (prev == null) {
	    out.println("No data. Get to work!");
	} else {
	    for (char c : prev) {
		out.print(c);
	    }
	    out.println();
	}
    }

    public void setInitialPattern(String input) {
	// IMPLEMENT THIS METHOD.

	// Instructions: You are given a String, but you need to
	// initialize 'prev', which is a char[] (that's pronounced
	// 'char array'). There are several ways to do this. One way
	// to do this is to initialize 'prev' to be the same size as
	// the input string, and then iterate through the characters
	// contained in 'input' and set each character directly.
	
	// Example. If the input String is "hello", the initial
	// pattern should be the char string equivalent to { 'h', 'e',
	// 'l', 'l', 'o' }.


    }

    public void run(int iterations) {
	// IMPLEMENT THIS METHOD.

	// Write a loop that runs the specified number of times, and
	// each time through the loop it does two things: (1) calls
	// the 'cycle' method, and (2) calls the 'printPrev()' method.


    }

    public void cycle() {
	// IMPLEMENT THIS METHOD.

	// This method advances the automaton's life cycle by one
	// stage. The previous state of the automaton is described by
	// the 'prev' character array. The goal here is to create a
	// different character array that represents the next cycle of
	// the automaton's evolution. Iterate through each character
	// in 'prev' and calculate the next state, and store it in
	// some character array that you initialize here.
	//
	// To do this correctly, you should implement and use the
	// 'getPattern(int)' and use the 'applyRule' method that is
	// already defined for you to get the output. If the pattern
	// isn't known it will output a warning message. Like this:
	//
	// String pat = getPattern(i);
	// char output = applyRule(pat);


    }

    public String getPattern(int idx) {
	// IMPLEMENT THIS METHOD.

	// Using the index provided, look in the 'prev' character
	// array and create a new String based on what you find there
	// in the 3-member neighborhood of idx. Then return that
	// String.
	//
	// If idx is 0, the return String should use prev[prev.length
	// - 1], prev[0], and prev[1] combined.
	//
	// if idx is prev.length-1 (the last indexable cell): prev[idx
	// - 1], prev[idx], prev[0]
	//
	// otherwise the return value should use idx-1, idx, and
	// idx+1.
	//
	// To combine two chars into a string, you might be interested
	// to know that if you use the '+' operator, Java will try to
	// use them as numbers. You can force Java to cast them to
	// Strings by including a String in the concatenation
	// process. Like this:
	//
	// String failString = ch1 + ch2 + ch3; // fails
	// String myString = "" + ch1 + ch2 + ch3; // works
	
	return ""; // change this to return something reasonable
    }

}

import static java.lang.System.out;

public class Lecture23 {
    public static void main(String[] args) {
	example1();
	cellularAutomataSimple();
    }

    public static void example1() {
	// Notice the 'import static java.lang.System.out'. This will
	// save you some typing. Now you can just say:
	out.println("Going to create an integer array of size 4:");
	int[] numbers = { 2, 10, 7, 89 };
	for (int num : numbers) {
	    out.println("Next number: " + num);
	}
	out.println("Your arrays have fixed size. Can't get around it.");
	String[] cells = new String[8];
	out.println("If you print out the default Strings without\n" +
		    "setting them to anything, here's what it does:");
	for (int i=0; i < cells.length; i++) {
	    out.println("String #" + i + ": " + cells[i]);
	}
	out.println("Notice that we used one form of the 'for' loop\n" +
		    "for the integer array, and the other kind for\n" +
		    "the String array. This was only done for the\n" +
		    "sake of example. You could use either. In the\n" +
		    "second case, we used the counter 'i' to show\n" +
		    "which index we were on.");
	out.println("\nWe may index array cells when assigning or\n" +
		    "when accessing values. We accessed values in this\n" + 
		    "way above, as in 'cells[i]'. To assign into a cell\n" +
		    "we say cells[i] = \"Something\". Like this:");
	for (int i=0; i < cells.length; i++) {
	    if (i % 3 == 0) {
		cells[i] = "*";
	    } else {
		cells[i] = " ";
	    }
	    out.println("String #" + i + ": " + cells[i]);
	}	
	// notice: no return value, since this is a 'void' function.
    }

    public static void cellularAutomataSimple() {
	out.println("\nCellular Automaton (Simple)\n");
	// In this example we'll make a simple cellular automaton. You
	// might think of it as a creature that grows and changes over
	// time. The way it changes is based on simple rules.
	// 
	// For example, here's a possible starting condition for our
	// creature:
	//
	// *  ** *** ** * ** * *** * * **
	//
	// It is just a string of splats and spaces. We can represent
	// this in an array, like this:
	String[] initial = { "*", " ", " ", " ", "*", "*", " ", "*", 
			     "*", "*", " ", "*", "*", " ", "*", " ", 
			     "*", "*", " ", "*", " ", "*", "*", "*", 
			     " ", "*", " ", "*", " ", "*", "*", " ",
			     "*", " ", " ", " ", "*", "*", " ", "*", 
			     "*", "*", " ", "*", "*", " ", "*", " ", 
			     "*", "*", " ", "*", " ", "*", "*", "*", 
			     " ", "*", " ", "*", " ", "*", "*", " ",
			     "*", " ", " ", " ", "*", "*", " ", "*", 
			     "*", "*", " ", "*", "*", " ", "*", " ", 
			     "*", "*", " ", "*", " ", "*", "*", "*", 
			     " ", "*", " ", "*", " ", "*", "*", " " };
	// Then if we want to print it out we can just iterate through
	// the array and print each cell:
	for (int i=0; i < initial.length; i++) {
	    out.print(initial[i]); // note: using 'print', not 'println'.
	}
	// output a newline to go to the beginning of next line.
	out.println();
	
	// We can create another reference to an array like this:
	String[] prevLine = initial; // note that prevLine is also a
				     // String array.
	// And we can make another String[] with the right length:
	String[] thisLine = new String[prevLine.length];
	// 'thisLine' is a String array with the same length as
	// prevLine but it has default data (a bunch of null strings).
	
	// For our simple cellular automata, we will use rules such as
	// the following: Looking at the previous line, if the cells
	// above looked like "***" then our cell will have a blank. We
	// can examine the specific cells using the counter:
	//   String aboveLeft = prevLine[i-1];
	//   String aboveCenter = prevLine[i];
	//   String aboveRight = prevLine[i+1];
	//
	// Here are the rules, where * is a 1 and a space is a 0:
	//
	//   parent pattern 111  110  101  100  011  010  001  000
	//   next pattern    0    1    0    1    1    0    1    0
	
	for (int time=0; time < 100; time++) {
	    thisLine[0] = prevLine[0];
	    for (int i=1; i < prevLine.length - 1; i++) {
		String pat = getPattern(prevLine, i);
		String here = null;
		if ("***".equals(pat)) {
		    here = " ";
		} else if ("** ".equals(pat)) {
		    here = "*";
		} else if ("* *".equals(pat)) {
		    here = " ";
		} else if ("*  ".equals(pat)) {
		    here = "*";
		} else if (" **".equals(pat)) {
		    here = "*";
		} else if (" * ".equals(pat)) {
		    here = " ";
		} else if ("  *".equals(pat)) {
		    here = "*";
		} else if ("   ".equals(pat)) {
		    here = " ";
		}
		thisLine[i] = here;
	    }
	    thisLine[thisLine.length - 1] = prevLine[prevLine.length - 1];
	    // now that thisLine is assembled, output it.
	    for (int i=0; i < thisLine.length; i++) {
		out.print(thisLine[i]);
	    }
	    out.println();
	    // now set prevLine to thisLine and reset thisLine.
	    prevLine = thisLine;
	    thisLine = new String[prevLine.length];
	}
    }

    public static String getPattern(String[] line, int i) {
	String ret = line[i-1] + line[i] + line[i+1];
	return ret;
    }

    
}

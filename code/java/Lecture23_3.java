import static java.lang.System.out;

public class Lecture23_3 {
    public static void main(String[] snoopy) {
	// example1(snoopy);
	// example2();
	example3();
    }

    public static void example3() {
	String[] line = { "*", "*", " ", " ", "*", " ", "*" };
	String[] nextLine = new String[line.length];
	for (int i=0; i < line.length; i++) {
	    if (line[i].equals("*")) {
		nextLine[i] = " ";
	    } else {
		nextLine[i] = "*";
	    }
	}
	printLine(line);
	printLine(nextLine);
    }

    public static void printLine(String[] items) {
	for (String x : items) {
	    out.print(x);
	}
	out.println();
    }

    public static void example2() {
	String[] stuff = { "Phone", "Monkey", "Platinum" };
	out.println("Stuff has: " + stuff.length);
	String[] moreStuff = new String[6];
	out.println("My new array with six things in it:");
	for (String x : moreStuff) {
	    out.println(" --> " + x);
	}
	out.println("Changing some values, then printing again.");
	moreStuff[3] = "Jimmybob";
	moreStuff[1] = "Sputnik";
	for (int i=0; i < moreStuff.length; i++) {
	    out.println(" element " + i + " is: " + moreStuff[i]);
	}
    }

    public static void example1(String[] fluffy) {
	out.println("Word up 1300!");
	out.println("my input args array has " + fluffy.length);
	for (String s : fluffy) {
	    out.println("  An input arg is: " + s);
	}
	// snoopy[3] is going to be an integer
	int element3 = Integer.parseInt(fluffy[3]);
	out.println("Got integer: " + element3);

	
    }
}

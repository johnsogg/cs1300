public class Lecture21_2 {
    public static void main(String[] args) {
	// in Python, looping thru first 5 nums:
	// for x in range(5): ...
	// in Java, we have to do this:
	for (int i=0; // iteration variable
	     i < 5; // looping condition
	     i++) // cleanup/increment statement
	    {
	    System.out.println("Round " + i);
	    }
	for (int even = 2;
	     even < 13;
	     even = even + 2) {
	    System.out.println("Even number: " + even);
	}
	/*
	for (double count = 0;
	     count < 3;
	     count = count + 0.1) {
	    System.out.println("Even number: " + count);	    
	}
	*/
	int dad = 10;
	while (dad > 0) {
	    System.out.println("Dad: " + dad);
	    dad = dad - 3;
	}
    }
}

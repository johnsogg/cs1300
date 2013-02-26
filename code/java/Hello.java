public class Hello {
    
    public static void main(String[] args) {
	// for x in range(6):
	for (int i=0; i < 6; i++) {
	    sayHi();
	}
	int count = 10;
	System.out.println(count);
	// can also do count = count + 1 in both langs
	// can also do count++ in both langs
	count++; // python equiv is count = count + 1
	System.out.println(count);
	// is there a difference between ++count and count++?
	//
	// yes.

	
	
    }

    static void sayHi() {
	System.out.println("Hello this is new in here.");
    }
}



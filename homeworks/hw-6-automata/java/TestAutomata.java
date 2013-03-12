
// Note on the TemplateTest:
//
// You really only need to do two things:
//
// 1. Search/replace TemplateTest with the name of your test.
//
// 2. Implement a bunch of functions that start with test and end with
// the name of the test you want. The names should match those
// provided in ../description-common.json. For example if a test is
// FooThingWorks, your test function should be testFooThingWorks.
//
// Nothing else is required as long as you attach the RetroPrinter to
// your test runner.

import org.junit.Test;
import org.junit.Before;
import static org.junit.Assert.*;
import org.junit.runner.JUnitCore;
import java.lang.reflect.Field;
import java.util.Map;

public class TestAutomata {

    public static void main(String[] args) {
	JUnitCore core= new JUnitCore();
	core.addListener(new RetroPrinter());
	core.run(TestAutomata.class);
    }

    Automata auto = new Automata();
    String pattern = "  *    *  *      *  *      *";

    @Before
    public void init() {
	auto = new Automata();
	auto.addRule("***", ' '); // 111 -> 0
	auto.addRule("** ", '*'); // 110 -> 1
	auto.addRule("* *", ' '); // 101 -> 0
	auto.addRule("*  ", '*'); // 100 -> 1
	auto.addRule(" **", '*'); // 011 -> 1
	auto.addRule(" * ", ' '); // 010 -> 0
	auto.addRule("  *", '*'); // 001 -> 1
	auto.addRule("   ", ' '); // 000 -> 0
    }

    @SuppressWarnings("unchecked")
    private Map<String, Character> getRules() {
	Map<String, Character> ret = null;
	try {
	    Field p = auto.getClass().getDeclaredField("rules");
	    p.setAccessible(true);
	    ret = (Map<String, Character>) p.get(auto);
	} catch (Exception ex) {
	    System.out.println("Got exception: " + ex);
	    assertTrue(false);
	    ex.printStackTrace();
	}
	return ret;
    }

    @SuppressWarnings("unchecked")
    private char[] getPrev() {
	char[] ret = null;
	try {
	    Field p = auto.getClass().getDeclaredField("prev");
	    p.setAccessible(true);
	    ret = (char[]) p.get(auto);
	} catch (Exception ex) {
	    System.out.println("Got exception: " + ex);
	    assertTrue(false);
	    ex.printStackTrace();
	}
	return ret;
    }

    @SuppressWarnings("unchecked")
    private void setPrev(char[] dataz) {
	try {
	    Field p = auto.getClass().getDeclaredField("prev");
	    p.setAccessible(true);
	    p.set(auto, dataz);
	} catch (Exception ex) {
	    System.out.println("Got exception: " + ex);
	    assertTrue(false);
	    ex.printStackTrace();
	}
    }

    @Test 
    public void testInitPattern() {
	auto.setInitialPattern(pattern);
	char[] prev = getPrev();
	assertEquals(pattern.length(), prev.length);
	if (prev.length == pattern.length()) {
	    boolean ok = true;
	    for (int i=0; i < prev.length; i++) {
		if (prev[i] != pattern.charAt(i)) {
		    ok = false;
		    break;
		}
	    }
	    if (!ok) {
		assertTrue(ok);
	    }
	}
    }

    @Test 
    public void testRun() {
	setPrev(pattern.toCharArray());
	char[] prev = getPrev();
	assertEquals("Sanity Check", prev.length, pattern.length());
	auto.run(10);
	String exp = "*** ** ******** *    * *****";
	prev = getPrev();
	assertEquals("Post-run Sanity Check", prev.length, exp.length());
	assertArrayEquals("Same data?", prev, exp.toCharArray());
    }

    @Test 
    public void testCycle() {
	setPrev(pattern.toCharArray());
	auto.cycle();
	String exp = "** *  * ** *    * ** *    * ";
	char[] prev = getPrev();
	assertEquals("Post-run Sanity Check", prev.length, exp.length());
	assertArrayEquals("same data?", prev, exp.toCharArray());
    }

    @Test 
    public void testGetPatternInside() {
	//           0         1         2
	//           0123456789012345678901234567
	String in = "*        * ****** ** ****** ";
	setPrev(in.toCharArray());
	String pat = auto.getPattern(4);
	assertEquals("Idx 4", pat, "   ");
	pat = auto.getPattern(9);
	assertEquals("Idx 9", pat, " * ");
	pat = auto.getPattern(16);
	assertEquals("Idx 16", pat, "** ");
	//	assertEquals(one.next, three);
	//	assertNull(three.next);
	//      assertTrue(false);
    }

    @Test 
    public void testGetPatternStart() {
	//           0         1         2
	//           0123456789012345678901234567
	String in = "*        * ****** ** ****** ";
	setPrev(in.toCharArray());
	String pat = auto.getPattern(0);
	assertEquals("Idx 0", pat, " * ");
    }

    @Test 
    public void testGetPatternEnd() {
	//           0         1         2
	//           0123456789012345678901234567
	String in = "*        * ****** ** ****** ";
	setPrev(in.toCharArray());
	String pat = auto.getPattern(27);
	assertEquals("Idx 27", pat, "* *");
    }


}

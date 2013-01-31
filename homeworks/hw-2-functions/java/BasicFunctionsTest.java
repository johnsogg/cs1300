import org.junit.Test;
import org.junit.Before;
import static org.junit.Assert.*;
import org.junit.runner.JUnitCore;
import java.util.List;
import java.util.ArrayList;
import junit.textui.TestRunner;
import junit.framework.JUnit4TestAdapter;

public class BasicFunctionsTest {

    public static void main(String[] args) {
	JUnitCore core= new JUnitCore();
	core.addListener(new RetroPrinter());
	core.run(BasicFunctionsTest.class);
    }

    BasicFunctions basic;

    @Before
    public void init() {
	basic = new BasicFunctions();
    }

    @Test 
    public void testFour() {
	//	assertEquals(top.next, one);
	//	assertNull(three.next);
	assertEquals(4, basic.returnFour());
    }

    @Test 
    public void testAddNumbers() {
	assertEquals(52, basic.addNumbers(40, 12));
	assertEquals(42, basic.addNumbers(40, 2));
    }
    
    @Test 
    public void testRepeatYourself() {
	assertEquals("KooKooKooKoo", basic.repeatYourself("Koo", 4));
    }

    @Test 
    public void testAddOneToAll() {
	List<Integer> in = new ArrayList<Integer>();
	in.add(5);
	in.add(10);
	in.add(7);
	in.add(39);
	in.add(-6);
	List<Integer> expected = new ArrayList<Integer>();
	expected.add(6);
	expected.add(11);
	expected.add(8);
	expected.add(40);
	expected.add(-5);
	List<Integer> reply = basic.addOneToAll(in);
	assertEquals(expected.size(), reply.size());
	boolean ok = true;
	for (int i=0; i < expected.size(); i++) {
	    if (expected.get(i) != reply.get(i)) {
		ok = false;
		break;
	    }
	}
	assertTrue(ok);
    }

    @Test 
    public void testIsOdd() {
	assertTrue(basic.isOdd(9));
	assertFalse(basic.isOdd(66));
    }

    @Test 
    public void testWhichCoin() {
	assertEquals("Penny", basic.whichCoin(1));
	assertEquals("Nickel", basic.whichCoin(5));
	assertEquals("Dime", basic.whichCoin(10));
	assertEquals("Quarter", basic.whichCoin(25));
    }

    @Test 
    public void testGetPrimesBelow() {
	int[] primes = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 
			 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89 };
	List<Integer> primeList = new ArrayList<Integer>();
	for (int i : primes) {
	    primeList.add(i);
	}
	List<Integer> reply = basic.getPrimesBelow(90);
	assertEquals(primeList.size(), reply.size());
	System.out.println("primeList: " + primeList);
	boolean ok = true;
	for (int i=0; i < primeList.size(); i++) {
	    if (primeList.get(i) != reply.get(i)) {
		ok = false;
		break;
	    }
	}
	assertTrue(ok);
    }

}

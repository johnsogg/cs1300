
// Note on the SlugTest:
//
// You really only need to do two things:
//
// 1. Search/replace SlugTest with the name of your test.
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

public class SlugTest {

    public static void main(String[] args) {
	JUnitCore core= new JUnitCore();
	core.addListener(new RetroPrinter());
	core.run(SlugTest.class);
    }

    @Before
    public void init() {

    }

    @Test 
    public void testRace() {
	Slug slug = new Slug("Minnie");
	Race race = new Race();
	race.slugs.add(slug);
	Slug winner = race.do_race();
	assertTrue(winner != null);
	//	assertEquals(one.next, three);
	//	assertNull(three.next);
	//      assertTrue(false);
    }


}

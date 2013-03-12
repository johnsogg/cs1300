import unittest
from RetroPrinter import RetroPrinter
from sys import argv

from automata import *

class RetroTest(unittest.TestCase):

    def __init__(self, methodName, outputName):
        super(RetroTest, self).__init__(methodName) # call superconstructor
        self.outputName = outputName

    # Helper functions for unit tests, like mknode...
    # def mknode(self, num):
    #     ret = bt_node()
    #     ret.data = num
    #     return ret

    def setUp(self):
        self.auto = Automata()
        self.pattern = "  *    *  *      *  *      *"
	self.auto.addRule("***", ' ') # 111 -> 0
	self.auto.addRule("** ", '*') # 110 -> 1
	self.auto.addRule("* *", ' ') # 101 -> 0
	self.auto.addRule("*  ", '*') # 100 -> 1
	self.auto.addRule(" **", '*') # 011 -> 1
	self.auto.addRule(" * ", ' ') # 010 -> 0
	self.auto.addRule("  *", '*') # 001 -> 1
	self.auto.addRule("   ", ' ') # 000 -> 0        

    def tearDown(self):
        pass

    # then a bunch of test functions. asserts left here for copy/paste
    # def test_foo(self):
    #     self.assertIsNotNone("obviously ok", "failure msg")
    #     self.assertEqual(42, 42, "failure msg")
    #     self.assertIsNone(None, "failure msg")
    #     self.assertTrue(True, "failure msg")
    #     self.assertFalse(False, "failure msg")
    
    def testInitPattern(self):
        self.auto.setInitialPattern(self.pattern)
        self.assertEqual(self.auto.prev, self.pattern)

    def testRun(self):
        self.auto.prev = self.pattern
        self.auto.run(10)
        exp = "*** ** ******** *    * *****"
        self.assertEqual(self.auto.prev, exp)

    def testCycle(self):
        self.auto.prev = self.pattern
        exp = "** *  * ** *    * ** *    * "
        self.auto.cycle()
        self.assertEqual(self.auto.prev, exp)

    def testGetPatternInside(self):
        #    0123456789012345678901234567
        i = "*        * ****** ** ****** "
        self.auto.prev = i
        pat = self.auto.getPattern(4)
        self.assertEqual(pat, "   ")
        pat = self.auto.getPattern(9)
        self.assertEqual(pat, " * ")
        pat = self.auto.getPattern(16)
        self.assertEqual(pat, "** ")

    def testGetPatternStart(self):
        #    0123456789012345678901234567
        i = "*        * ****** ** ****** "
        self.auto.prev = i
        pat = self.auto.getPattern(0)
        self.assertEqual(pat, " * ")
        

    def testGetPatternEnd(self):
        #    0123456789012345678901234567
        i = "*        * ****** ** ****** "
        self.auto.prev = i
        pat = self.auto.getPattern(27)
        self.assertEqual(pat, "* *")

if __name__ == '__main__':
    retro = False
    if (len(argv) > 1 and argv[1] == "--retrograde"):
        retro = True
    print "Retro mode: " + str(retro)
    suite = unittest.TestSuite()
    # now pair the above functions to the retrograde name
    tests = [
        RetroTest("testInitPattern", "InitPattern"),
        RetroTest("testRun", "Run"),
        RetroTest("testCycle", "Cycle"),
        RetroTest("testGetPatternInside", "GetPatternInside"),
        RetroTest("testGetPatternStart", "GetPatternStart"),
        RetroTest("testGetPatternEnd", "GetPatternEnd"),
        ]
    for test in tests:
        suite.addTest(test)
    if retro:
        result = RetroPrinter()
        print "Running Python test suite..."
        suite.run(result)
        print "Done running Python test suite."
    else:
        runner = unittest.TextTestRunner()
        runner.run(suite)


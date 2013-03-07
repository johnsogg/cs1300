import unittest
from RetroPrinter import RetroPrinter
from sys import argv

from race import Race
from slug import Slug

class RetroTest(unittest.TestCase):

    def __init__(self, methodName, outputName):
        super(RetroTest, self).__init__(methodName) # call superconstructor
        self.outputName = outputName

    def setUp(self):
        pass

    def tearDown(self):
        pass

    # then a bunch of test functions. asserts left here for copy/paste
    def test_race(self):
        slug = Slug("Mickey")
        race = Race()
        race.slugs.append(slug)
        winner = race.do_race()
        self.assertTrue(winner is not None)

        # self.assertIsNotNone("obviously ok", "failure msg")
        # self.assertEqual(42, 42, "failure msg")
        # self.assertIsNone(None, "failure msg")
        # self.assertTrue(True, "failure msg")
        # self.assertFalse(False, "failure msg")


if __name__ == '__main__':
    retro = False
    if (len(argv) > 1 and argv[1] == "--retrograde"):
        retro = True
    print "Retro mode: " + str(retro)
    suite = unittest.TestSuite()
    # now pair the above functions to the retrograde name
    tests = [
        RetroTest("test_race", "TestRace"),
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


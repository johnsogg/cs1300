#
# maps_test.py
#
# You don't need to edit this file. But you can run it like this:
#
# python maps_test.py

import unittest
from maps import *
from sys import argv

class MapsTest(unittest.TestCase):
    
    def setUp(self):
        pass

    def tearDown(self):
        pass

    def test_make_empty_dictionary(self):
        result = make_empty_dictionary()
        self.assertEqual(dict, type(result), "Should return a dictionary")
        self.assertEqual(0, len(result), "Dictionary should have 0 length")

    def test_make_student_dictionary(self):
        result = make_student_dictionary()
        self.run_common_assertions(result, "Unknown Name",
                                   "Unknown Age", "Unknown Major")

    def run_common_assertions(self, result, target_name, target_age, target_major):
        self.assertEqual(dict, type(result), "Should return empty dictionary")
        self.assertEqual(3, len(result), "Dictionary should have 3 length")
        self.assertTrue(result.has_key('name'), "Key 'name' not found.")
        self.assertTrue(result.has_key('age'), "Key 'age' not found.")
        self.assertTrue(result.has_key('major'), "Key 'major' not found.")
        self.assertEqual(target_name, result['name'])
        self.assertEqual(target_age, result['age'])
        self.assertEqual(target_major, result['major'])

    def test_make_real_student_dictionary(self):
        result = make_real_student_dictionary("Bob", 20, "Basket Weaving")
        self.run_common_assertions(result, "Bob", 20, "Basket Weaving")
        result = make_real_student_dictionary("Alice", 19, None)
        self.run_common_assertions(result, "Alice", 19, None)
        result = make_real_student_dictionary(None, None, None)
        self.run_common_assertions(result, None, None, None)

    def test_get_student_dictionary_as_list(self):
        stud = { 'name'  : "Gandalf",
                 'age'   : 12832,
                 'major' : "Wizardry" }
        result = get_student_dictionary_as_list(stud)
        self.assertEqual(list, type(result), "Should return a list")
        self.assertEqual(3, len(result), "Should be a list with 3 items")
        self.assertEqual("Gandalf", result[0], "First item should be 'Gandalf'")
        self.assertEqual("Wizardry", result[1], "Second item should be 'Wizardry'")
        self.assertEqual(12832, result[2], "Last item should be 12832")

    def test_which_student_is_older(self):
        gandalf = { 'name'  : "Gandalf",
                    'age'   : 12832,
                    'major' : "Wizardry" }
        bilbo   = { 'name'  : "Bilbo Baggins",
                    'age'   : 111,
                    'major' : "Creative Writing" }
        frodo   = { 'name'  : "Frodo Baggins",
                    'age'   : 33,
                    'major' : "Ringbearer" }
        frodo_twin = { 'name'  : "Frodo Baggins Evil Twin",
                    'age'   : 33,
                    'major' : "Dropout" }

        older = which_student_is_older(bilbo, gandalf)
        self.run_common_assertions(older, "Gandalf", 12832, "Wizardry")
        self.assertEqual(gandalf, older, "The returned dictionary should be the same one that was passed in.")
        older = which_student_is_older(frodo, bilbo)
        self.run_common_assertions(older, "Bilbo Baggins", 111, "Creative Writing")
        self.assertEqual(bilbo, older, "The returned dictionary should be the same one that was passed in.")
        older = which_student_is_older(frodo_twin, frodo)
        self.run_common_assertions(older, "Frodo Baggins Evil Twin", 33, "Dropout")
        self.assertEqual(frodo_twin, older, "The returned dictionary should be the same one that was passed in.")

    
    def test_are_students_the_same(self):
        bilbo   = { 'name'  : "Bilbo Baggins",
                    'age'   : 111,
                    'major' : "Creative Writing" }
        bilbo2  = { 'name'  : "Bilbo Baggins",
                    'age'   : 111,
                    'major' : "Creative Writing" }
        frodo   = { 'name'  : "Frodo Baggins",
                    'age'   : 33,
                    'major' : "Ringbearer" }
        frodo_twin = { 'name'  : "Frodo Baggins",
                    'age'   : 33,
                    'major' : "Dropout" }
        result = are_students_the_same(bilbo, frodo)
        self.assertEquals(bool, type(result), "Should return True or False")
        self.assertFalse(result, "Bilbo and Frodo shouldn't be the same.")
        result = are_students_the_same(bilbo, bilbo2)
        self.assertEquals(bool, type(result), "Should return True or False")
        self.assertTrue(result, "Bilbo and Bilbo2 should be the same.")
        result = are_students_the_same(bilbo, bilbo)
        self.assertEquals(bool, type(result), "Should return True or False")
        self.assertTrue(result, "Bilbo and Bilbo should be the same.")
        result = are_students_the_same(frodo, frodo_twin)
        self.assertEquals(bool, type(result), "Should return True or False")
        self.assertFalse(result, "Bilbo and Bilbo2 should be the same.")

if __name__ == '__main__':
    num_args = len(argv) - 1
    if num_args == 0:
        print "Running Python test suite..."
        unittest.main()
        print "... done running Python test suite."
    else:
        print "Running specific tests:"
        for arg in argv[1:]:
            print "\t" + arg
        suite = unittest.TestSuite()
        tests = []
        for arg in argv[1:]:
            suite.addTest(MapsTest(arg))
        runner = unittest.TextTestRunner()
        runner.run(suite)


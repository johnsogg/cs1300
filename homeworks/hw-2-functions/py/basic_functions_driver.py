#
# basic_functions_driver.py
#
# You don't need to edit this file. But you can run it like this:
#
# python basic_functions_driver.py
#
# ... this will show you where your errors are. If instead it says
# something like the following:
#
# Ran 7 tests in 0.001s
#
# OK
#
# ... that means all the tests passed!
#
# HOWEVER, be aware that these are not exactly the same tests that
# RetroGrade will use.

import unittest
from basic_functions import *

class BasicTest(unittest.TestCase):
    
    def setUp(self):
        pass

    def tearDown(self):
        pass

    def test_four(self):
        maybe_four = return_four()
        self.assertEqual(4, maybe_four, "return_four should return 4")

    def test_add_numbers(self):
        self.assertEqual(7, add_numbers(2, 5))
        self.assertEqual(9, add_numbers(10, -1))
        self.assertEqual(14, add_numbers(7, 7))
        self.assertEqual(100, add_numbers(900, -800))

    def test_repeat_yourself(self):
        self.assertEqual("NomNomNom", repeat_yourself("Nom", 3))
        self.assertEqual("Tricky!", repeat_yourself("Tricky!", 1))
        self.assertEqual("uuuuuuuuuu", repeat_yourself("u", 10))

    def test_add_one_to_all(self):
        input_list = [5, 10, 40, 19]
        expected_list = [6, 11, 41, 20]
        self.assertEqual(expected_list, add_one_to_all(input_list))

    def test_is_odd(self):
        self.assertEqual(False, is_odd(4))
        self.assertEqual(True, is_odd(3))
        self.assertEqual(False, is_odd(10))
        self.assertEqual(True, is_odd(-13))
        self.assertEqual(False, is_odd(40))
        self.assertEqual(True, is_odd(397321))
    
    def test_which_coin(self):
        self.assertEqual("Penny", which_coin(1))
        self.assertEqual("Nickel", which_coin(5))
        self.assertEqual("Dime", which_coin(10))
        self.assertEqual("Quarter", which_coin(25))

    def test_get_primes_below(self):
        massive = [ 2,   3,  5,  7, 11, 
                    13, 17, 19, 23, 29, 
                    31, 37, 41, 43, 47, 
                    53, 59, 61, 67, 71, 
                    73, 79, 83, 89, 97, 
                    101, 103]
        self.assertEquals(massive[:massive.index(11)], get_primes_below(11))
        self.assertEquals(massive[:massive.index(43)], get_primes_below(42))
        self.assertEquals(massive[:massive.index(47)], get_primes_below(44))
        self.assertEquals(massive[:massive.index(101)], get_primes_below(100))

if __name__ == '__main__':
    print "Running Python test suite..."
    unittest.main()
    print "... done running Python test suite."

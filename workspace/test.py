from main import *
import unittest

class Test(unittest.TestCase):
    def test_case1(self):
        self.assertEqual(calc(["10", "11"]), 0)
    def test_case2(self):
        self.assertEqual(calc(["001", "100", "010"]), 2)

if __name__ == '__main__':
    unittest.main()

from main import *
import unittest

class Test(unittest.TestCase):
    def test_case0(self):
        self.assertEqual(1, solve(1, 1, 1))
    def test_case1(self):
        self.assertEqual(3, solve(1, 4, 2))
    def test_case2(self):
        self.assertEqual(4, solve(1, 5, 2))
    def test_case3(self):
        self.assertEqual(2, solve(2, 1, 1))
    def test_case4(self):
        self.assertEqual(5, solve(2, 4, 2))
    def test_case4(self):
        self.assertEqual(6, solve(2, 5, 2))

if __name__ == '__main__':
    unittest.main()

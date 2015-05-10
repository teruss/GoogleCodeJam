from main import *
import unittest

class Test(unittest.TestCase):
    def test_case1(self):
        self.assertEqual(3, solve(1, 4, 2))
    def test_case2(self):
        self.assertEqual(7, solve(1, 7, 7))
    def test_case3(self):
        self.assertEqual(10, solve(2, 5, 1))


if __name__ == '__main__':
    unittest.main()

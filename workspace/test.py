from main import *
import unittest

class Test(unittest.TestCase):
    def test_case1(self):
        self.assertEqual(solve(1), 1)
    def test_case2(self):
        self.assertEqual(solve(19), 19)
    def test_case3(self):
        self.assertEqual(solve(23), 15)

if __name__ == '__main__':
    unittest.main()

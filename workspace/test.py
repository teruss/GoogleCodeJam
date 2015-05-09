from main import *
import unittest

class Test(unittest.TestCase):
    def test_case1(self):
        self.assertEqual(solve(2, 3, 6), 7)
    def test_case2(self):
        self.assertEqual(solve(4, 1, 2), 0)
    def test_case3(self):
        self.assertEqual(solve(5, 1, 3), 0)
    def test_case4(self):
        self.assertEqual(solve(3, 3, 8), 8)
    def test_case5(self):
        self.assertEqual(solve(5, 2, 0), 0)
    def test_case6(self):
        self.assertEqual(solve(5, 5, 20), 20)
    def test_case7(self):
        self.assertEqual(solve(5, 5, 14), 3)
    def test_case8(self):
        self.assertEqual(solve(4, 4, 9), 2)
    def test_case9(self):
        self.assertEqual(solve(15, 1, 15), 14)

if __name__ == '__main__':
    unittest.main()

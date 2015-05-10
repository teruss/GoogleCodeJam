from main import *
import unittest

class Test(unittest.TestCase):
    def test_case1(self):
        self.assertEqual(solve([(1, 1, 12), (359, 1, 12), (2, 1, 12), (358, 1, 12)]), 0)
    def test_case2(self):
        self.assertEqual(solve([(180, 1, 100000), (180, 1, 1)]), 1)
    def test_case3(self):
        self.assertEqual(solve([(180, 2, 1)]), 0)
    def test_case4(self):
        self.assertEqual(solve([(180, 1, 30), (180, 1, 10)]), 1)


if __name__ == '__main__':
    unittest.main()

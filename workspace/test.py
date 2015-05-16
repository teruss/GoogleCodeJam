from main import *
import unittest

class Test(unittest.TestCase):
    def test_case0(self):
        self.assertEqual(0, solve(6, 'BANANAS', 'MONKEY'))
    def test_case1(self):
        self.assertEqual(0, solve(4, 'AA', 'AAA'))
    def test_case2(self):
        self.assertEqual(1, solve(2, 'AB', 'B'))

if __name__ == '__main__':
    unittest.main()

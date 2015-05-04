from main import *
import unittest

class Test(unittest.TestCase):
    def test_case1(self):
        self.assertEqual(calc(1, 9), 1)
    def test_case2(self):
        self.assertEqual(calc(1, 10), 2)

if __name__ == '__main__':
    unittest.main()

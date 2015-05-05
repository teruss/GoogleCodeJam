from main import *
import unittest

class Test(unittest.TestCase):
    def test_case1(self):
        self.assertEqual(calc([9, 4, 36, 1]), [3, 3, 4])
    def test_case2(self):
        self.assertEqual(calc([1, 1, 1, 1]), [2, 3, 4])

if __name__ == '__main__':
    unittest.main()

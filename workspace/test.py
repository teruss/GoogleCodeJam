from main import *
import unittest

class Test(unittest.TestCase):
    def test_case1(self):
        self.assertEqual(0, solve(6, 'BANANAS', 'MONKEY'))
    def test_case2(self):
        self.assertEqual(0, solve(4, 'AA', 'AAA'))
    def test_case3(self):
        self.assertEqual(1, solve(2, 'AB', 'B'))
    def test_case4(self):
        self.assertAlmostEqual(0.8888889, solve(2, 'GOOGLE', 'GO'))
    def test_case5(self):
        self.assertAlmostEqual(9, solve(100, 'ABCDEFGHIJKLMNOPQRSTUVWXYZ', 'ROSENCRANTZ'))
    def test_case6(self):
        self.assertAlmostEqual(2 - (4.0/7.0) ** 2, solve(2, 'QGBGGZG', 'G'))


if __name__ == '__main__':
    unittest.main()

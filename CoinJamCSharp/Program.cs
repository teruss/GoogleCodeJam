using System;
using System.Numerics;

namespace CoinJamCSharp
{
    class Program
    {

        static BigInteger nextJamCoin(BigInteger x)
        {
            var str = x.ToString();
            var x2 = Convert.ToInt64(str, 2) + 2;
            var b2 = Convert.ToString(x2, 2);
            var x3 = BigInteger.Parse(b2);
            return x3;
        }

        static BigInteger frombase(BigInteger x, int b)
        {
            BigInteger res = 0;

            BigInteger y = 1;
            while (x > 0)
            {
                res += (x % 10) * y;
                y *= b;
                x /= 10;
            }

            return res;
        }

        static bool tryFindDivisor(BigInteger y, out BigInteger z)
        {
            //for (BigInteger x = 2; x * x <= y; x++)
            for (BigInteger x = 2; x * x <= 10000; x++)
            {
                if (y % x == 0)
                {
                    z = x;
                    return true;
                }
            }
            z = -1;
            return false;
        }

        static void Main(string[] args)
        {
            Console.WriteLine("Case #1:");
            //int N = 16;
            //int J = 50;
            int N = 32;
            int J = 500;
            BigInteger x = 1;
            for (int i = 0; i < N - 1; i++)
            {
                x *= 10;
            }
            x++;
            for (; ; x = nextJamCoin(x))
            {
                BigInteger[] v = new BigInteger[9];
                bool f = false;
                for (int i = 2; i <= 10; i++)
                {
                    var y = frombase(x, i);
                    BigInteger z;
                    if (tryFindDivisor(y, out z))
                    {
                        v[i - 2] = z;
                    }
                    else
                    {
                        f = true;
                        break;
                    }
                }
                if (f)
                    continue;
                Console.Write(x);
                for (int i = 0; i < 9; i++)
                {
                    Console.Write(" {0}", v[i]);
                }
                Console.WriteLine();

                if (--J == 0)
                {
                    break;
                }
                continue;
            }
        }
    }
}

#include <vector>
#include <iostream>
#include <bitset>
#include <sstream>
using namespace std;

long long nextJamCoin(long long x)
{
	stringstream ss;
	ss << x;
	auto str = ss.str();
	bitset<64> b(str);
	auto x2 = b.to_ullong() + 2;
	bitset<64> b2(x2);
	stringstream ss2;
	ss2 << b2.to_string();
	long long x3;
	ss2 >> x3;
	return x3;
}

long long base(long long x, int b)
{
	long long res = 0;

	long long y = 1;
	while (x > 0)
	{
		res += (x % 10) * y;
		y *= b;
		x /= 10;
	}

	return res;
}

bool tryFindDivisor(long long y, long long& z)
{
	for (long long x = 2; x * x <= y; x++)
	{
		if (y % x == 0)
		{
			z = x;
			return true;
		}
	}
	return false;
}

int main()
{
	int N = 16;
	int J = 50;
	long long x = 1;
	for (int i = 0; i < N - 1; i++)
	{
		x *= 10;
	}
	x++;
	cout << "Case #1:" << endl;
	for (;; x = nextJamCoin(x)) {
		long long v[9];
		bool f = false;
		for (int i = 2; i <= 10; i++)
		{
			auto y = base(x, i);
			long long z;
			if (tryFindDivisor(y, z))
			{
				v[i - 2] = z;
			}
			else {
				f = true;
				break;
			}
		}
		if (f)
			continue;
		cout << x;
		for (int i = 0; i < 9; i++)
		{
			cout << " " << v[i];
		}
		cout << endl;

		if (--J == 0)
		{
			break;
		}
		continue;
	}
	return 0;
}

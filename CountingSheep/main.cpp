#include <iostream>
#include <bitset>
using namespace std;

int main()
{
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t)
	{
		long long N;
		cin >> N;

		cout << "Case #" << t << ": ";

		if (N == 0)
		{
			cout << "INSOMNIA";
		}
		else
		{
			bitset<10> bits;

			int c = 1;
			for (auto x = N;; x += N, ++c)
			{
				auto n = x;
				while (n > 0)
				{
					bits[n % 10] = true;
					n /= 10;
				}
				if (bits.all())
				{
					break;
				}
			}
			cout << c * N;
		}
		cout << endl;
	}
}
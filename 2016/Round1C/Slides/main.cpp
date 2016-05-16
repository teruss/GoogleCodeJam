#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

int main()
{
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		int B;
		unsigned long long M;
		cin >> B >> M;

		cout << "Case #" << t << ": ";
		auto x = 1llu << (B - 2);
		if (x < M)
		{
			cout << "IMPOSSIBLE" << endl;
			continue;
		}
		cout << "POSSIBLE" << endl;
		if (x == M)
		{
			for (int i = 0; i < B; i++)
			{
				for (int j = 0; j < B; j++)
				{
					if (j > i)
					{
						cout << 1;
					}
					else
					{
						cout << 0;
					}
				}
				cout << endl;
			}
			continue;
		}
		bitset<64> b(M);
		for (int i = B - 2; i >= 0; i--)
		{
			cout << b[i];
		}
		cout << 0 << endl;
		for (int i = 1; i < B; i++)
		{
			for (int j = 0; j < B; j++)
			{
				if (j > i)
				{
					cout << 1;
				}
				else
				{
					cout << 0;
				}
			}
			cout << endl;
		}
	}
	return 0;
}
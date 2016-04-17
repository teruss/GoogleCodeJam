#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		cout << "Case #" << t << ":";

		int K, C, S;
		cin >> K >> C >> S;

		if (S * C < K)
		{
			cout << " IMPOSSIBLE" << endl;
			continue;
		}

		for (int i = 1; i <= K; i += C)
		{
			long long p = 1;
			for (int j = 0; j < C; j++)
			{
				p = (p - 1) * K + min(i + j, K);
			}
			cout << " " << p;
		}

		cout << endl;
	}
	return 0;
}
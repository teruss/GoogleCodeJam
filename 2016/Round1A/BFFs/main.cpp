#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		int N;
		cin >> N;

		vector<int> f(N);
		for (int i = 0; i < N; i++)
		{
			cin >> f[i];
			f[i]--;
		}

		vector<int> p(N);
		for (int i = 0; i < N; i++)
		{
			p[i] = i;
		}

		int r = 0;
		do
		{
			auto first = p[0];
			auto second = p[1];
			for (int i = 1; i < N; i++)
			{
				auto prev = p[i - 1];
				auto cur = p[i];

				if ((f[cur] == prev || f[cur] == first) && (f[first] == cur || f[first] == second))
				{
					r = max(r, i + 1);
				}

				if (f[cur] == prev)
				{
					continue;
				}
				
				if (i == N - 1 || f[cur] != p[i + 1])
				{
					break;
				}
			}
		} while (next_permutation(p.begin(), p.end()));

		cout << "Case #" << t << ": " << r << endl;
	}
	return 0;
}
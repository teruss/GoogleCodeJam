#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <set>
using namespace std;

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++)
	{
		cout << "Case #" << t << ":";

		int N;
		cin >> N;

		set<int> s;
		for (int i = 0; i < N*2-1; i++)
		{
			for (int j = 0; j < N; j++)
			{
				int h;
				cin >> h;
				auto iter = s.find(h);
				if (iter == s.end())
				{
					s.insert(h);
				}
				else
				{
					s.erase(iter);
				}
			}
		}

		for (auto x : s)
		{
			cout << " " << x;
		}
		cout << endl;
	}
	return 0;
}
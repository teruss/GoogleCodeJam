#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int C;
		cin >> C;
		int I;
		cin >> I;
		vector<int> P(I);
		for (int j = 0; j < I; j++)
		{
			cin >> P[j];
			P[j] <<= 16;
			P[j] |= j;
		}
		sort(P.begin(), P.end());
		int l, r;
		for (int j = 0; j < I - 1; j++)
		{
			auto f = lower_bound(P.begin() + 1 + j, P.end(), (C - (P[j] >> 16)) << 16);
			if (f != P.end() && ((*f) >> 16) + (P[j] >> 16) == C)
			{
				l = ((*f) & 0xFFFF) + 1;
				r = (P[j] & 0xFFFF) + 1;
				if (l > r)
				{
					swap(l, r);
				}
				break;
			}
		}
		
		cout << "Case #" << (i + 1) << ": " << l << " " << r << endl;
	}
	return 0;
}


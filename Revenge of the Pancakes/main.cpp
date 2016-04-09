#include <iostream>
#include <string>
#include <bitset>
using namespace std;

int main()
{
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t)
	{
		string S;
		cin >> S;

		cout << "Case #" << t << ": ";

		int c = S.back() == '-';
		for (size_t i = 1; i < S.length(); i++)
		{
			c += S[i - 1] != S[i];
		}
		cout << c;
		cout << endl;
	}
}
#include <iostream>
#include <string>
#include <sstream>
#include <deque>
using namespace std;

int main()
{
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		cout << "Case #" << t << ": ";

		string S;
		cin >> S;

		deque<char> deq;
		deq.push_back(S[0]);

		for (size_t i = 1; i < S.size(); i++)
		{
			if (S[i] >= deq[0])
			{
				deq.push_front(S[i]);
			}
			else
			{
				deq.push_back(S[i]);
			}
		}

		for (size_t i = 0; i < deq.size(); i++)
			cout << deq[i];
		cout << endl;
	}
	return 0;
}
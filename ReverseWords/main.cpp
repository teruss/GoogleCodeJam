#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int main()
{
	string n;
	getline(cin, n);
	stringstream nss(n);
	int N;
	nss >> N;
	for (int i = 0; i < N; i++)
	{
		string str;
		getline(cin, str);

		stringstream ss(str);

		vector<string> v;
		while (ss)
		{
			string s;
			ss >> s;
			if (!s.empty())
			{
				v.push_back(s);
			}
		}

		cout << "Case #" << (i + 1) << ":";
		while (!v.empty())
		{
			cout << " " << v.back();
			v.pop_back();
		}
		cout << endl;
	}
	return 0;
}
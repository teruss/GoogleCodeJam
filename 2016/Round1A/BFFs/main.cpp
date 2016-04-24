#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
using namespace std;

int dfs(int index, const vector<int> &f, vector<int> &depth, int c, bitset<1000>& done)
{
	if (depth[index] >= 0)
	{
		return c - depth[index];
	}
	depth[index] = c;
	done[index] = true;
	return dfs(f[index], f, depth, c + 1, done);
}

int lengthOf(const vector<vector<int>>& r, int origin, int except)
{
	if (r[origin].empty())
		return 0;
	int res = 0;
	for (auto x : r[origin])
	{
		if (x != except)
			res = max(res, 1 + lengthOf(r, x, except));
	}
	return res;
}

int solveLine(const vector<int> &f)
{
	int N = f.size();
	vector<vector<int>> r(N);

	for (int i = 0; i < N; i++)
	{
		r[f[i]].push_back(i);
	}

	int res = 0;
	for (int i = 0; i < N; i++)
	{
		int left = i;
		int right = f[left];
		if (f[right] == left && left < right)
			res += 2 + lengthOf(r, left, right) + lengthOf(r, right, left);
	}

	return res;
}

int solve(const vector<int> &f)
{
	int N = f.size();
	int res = 0;
	bitset<1000> done;
	for (int i = 0; i < N; i++)
	{
		vector<int> depth(N, -1);
		if (!done[i])
			res = max(res, dfs(i, f, depth, 0, done));
	}

	res = max(res, solveLine(f));

	return res;
}

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

		cout << "Case #" << t << ": " << solve(f) << endl;
	}
	return 0;
}
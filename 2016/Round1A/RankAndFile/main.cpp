#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
using namespace std;

bool nextStep(int current, const vector<vector<int>>& pieces, vector<vector<int>>& heights, bitset<64>& rank, bitset<64>& file)
{
	int N = heights.size();
	if (current == N * 2 - 1)
		return true;
	auto piece = pieces[current];

	for (int i = 0; i < N; i++)
	{
		if (rank[i])
			continue;
		if (heights[i][0] == 0 || heights[i][0] == piece[0])
		{
			if (i > 0 && heights[i - 1][0] >= piece[0])
			{
				break;
			}
			auto temp = heights[i];
			for (int j = 0; j < N; j++)
			{
				if (heights[i][j] != 0 && heights[i][j] != piece[j])
				{
					goto vertical;
				}
			}
			heights[i] = piece;
			rank[i] = true;
			if (!nextStep(current + 1, pieces, heights, rank, file))
			{
				heights[i] = temp;
				rank[i] = false;
				break;
			}
			else {
				return true;
			}
		}
	}
	vertical:
	for (int i = 0; i < N; i++)
	{
		if (file[i])
			continue;
		if (heights[0][i] == piece[0])
		{
			vector<int> h(N);
			for (int j = 0; j < N; j++)
			{
				h[j] = heights[j][i];
			}

			for (int j = 0; j < N; j++)
			{
				if (heights[j][i] != 0 && heights[j][i] != piece[j])
				{
					return false;
				}
			}

			for (int j = 0; j < N; j++)
			{
				heights[j][i] = piece[j];
			}
			file[i] = true;
			
			if (!nextStep(current + 1, pieces, heights, rank, file))
			{
				for (int j = 0; j < N; j++)
				{
					heights[j][i] = h[j];
				}
				file[i] = false;
				break;
			}
			else
			{
				return true;
			}
		}
	}
	return false;
}

void solve(const vector<vector<int>>& pieces, vector<vector<int>>& heights)
{
	bitset<64> rank, file;
	
	if (!nextStep(0, pieces, heights, rank, file))
	{
		return;
	}
}

void findAnswer(vector<vector<int>>& pieces, const vector<vector<int>>& heights, vector<int>& ans)
{
	int N = heights.size();

	for (int i = 0; i < N; i++)
	{
		auto iter = find(pieces.begin(), pieces.end(), heights[i]);
		if (iter == pieces.end())
		{
			ans = heights[i];
			return;
		}
		pieces.erase(iter);
	}
	for (int i = 0; i < N; i++)
	{
		vector<int> h(N);
		for (int j = 0; j < N; j++)
		{
			h[j] = heights[j][i];
		}
		auto iter = find(pieces.begin(), pieces.end(), h);
		if (iter == pieces.end())
		{
			ans = h;
			return;
		}
		pieces.erase(iter);
	}
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++)
	{
		cout << "Case #" << t << ":";

		int N;
		cin >> N;

		vector<vector<int>> pieces(N*2-1, vector<int>(N));
		for (int i = 0; i < N*2-1; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> pieces[i][j];
			}
		}
		sort(pieces.begin(), pieces.end());

		vector<vector<int>> heights(N, vector<int>(N));

		solve(pieces, heights);

		vector<int> ans;
		findAnswer(pieces, heights, ans);

		for (int i = 0; i < N; i++)
		{
			cout << " " << ans[i];
		}
		cout << endl;
	}
	return 0;
}
#include "stdafx.h"
#include "CppUnitTest.h"

#include <iostream>
#include <vector>
#include <map>
#include <bitset>
#include <cassert>

#include <direct.h>
#include <stdlib.h>  
#include <stdio.h>  
#include <fstream>
using namespace std;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

//Returns my solution's directory
#define TEST_CASE_DIRECTORY GetDirectoryName(__FILE__)

string GetDirectoryName(string path) {
	const size_t last_slash_idx = path.rfind('\\');
	if (std::string::npos != last_slash_idx)
	{
		return path.substr(0, last_slash_idx + 1);
	}
	return "";
}

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			ifstream file;

			file.open(std::string(TEST_CASE_DIRECTORY) +"sample.txt", ios::in);    // open file

			stringstream ss;
			main__(file, ss);

			fstream answer(std::string(TEST_CASE_DIRECTORY) + "sample_out.txt");

			string l, r;
			while (ss >> l)
			{
				answer >> r;
				Assert::AreEqual(l, r);
			}

			file.close();
		}

		typedef map<int, int> Keys;
		typedef vector<pair<int, vector<int>>> Chests;
		typedef bitset<201> Flag;

		bool checkTarget(map<int, vector<int>> chestsKeys, Flag &usedCK, Flag currentKeys, int target)
		{
			if (usedCK[target])
				return false;
			auto ck = chestsKeys[target];
			if (currentKeys[target])
				return true;

			auto types = ck;

			for (auto t : types)
			{
				if (t == target || usedCK[target])
					continue;

				usedCK[target] = true;
				if (checkTarget(chestsKeys, usedCK, currentKeys, t))
					return true;
				usedCK[target] = false;
			}
			return false;
		}

		bool anyKeyReachable(Keys &keys, const Chests &chests, Flag flag)
		{
			Flag neededKeys;
			for (int i = 0; i < chests.size(); i++)
			{
				if (flag[i]) continue;

				neededKeys[chests[i].first] = true;
			}

			Flag currentKeys;
			for (auto p : keys)
			{
				if (p.second > 0)
					currentKeys[p.first] = true;
			}

			if ((neededKeys & currentKeys) == neededKeys)
				return true;

			map<int, vector<int>> chestsKeys;
			for (int i = 0; i < chests.size(); i++)
			{
				if (flag[i])
					continue;
				for (int j = 0; j < chests[i].second.size(); j++)
				{
					chestsKeys[chests[i].second[j]].push_back(chests[i].first);
				}
			}

			for (auto ck : chestsKeys)
			{
				auto type = ck.first;
				Flag usedCK;
				if (!checkTarget(chestsKeys, usedCK, currentKeys, type))
					return false;

				currentKeys |= usedCK;

				if ((currentKeys & neededKeys) == neededKeys)
					return true;
			}
			return true;
		}

		bool check(Keys &keys, const Chests &chests, Flag flag, vector<int> &out)
		{
			if (out.size() == chests.size())
			{
				return true;
			}
			map<int, int> keyMap = keys;

			for (int i = 0; i < chests.size(); i++)
			{
				if (flag[i])
				{
					continue;
				}
				auto chest = chests[i];
				auto type = chest.first;
				keyMap[type]--;
				for (auto k : chest.second)
				{
					keyMap[k]++;
				}
			}

			for (int k = 1; k <= 200; k++)
			{
				if (keyMap[k] < 0)
				{
					return false;
				}
			}

			if (!anyKeyReachable(keys, chests, flag))
				return false;

			for (int i = 0; i < chests.size(); i++)
			{
				auto type = chests[i].first;
				if (flag[i] || keys[type] <= 0)
				{
					continue;
				}
				keys[type]--;
				flag[i] = true;
				out.push_back(i);
				for (auto k : chests[i].second)
				{
					keys[k]++;
				}
				if (check(keys, chests, flag, out))
				{
					return true;
				}
				for (auto k : chests[i].second)
				{
					keys[k]--;
				}
				flag[i] = false;
				keys[chests[i].first]++;
				out.pop_back();
			}
			return false;
		}

		int main__(istream& in, ostream& out)
		{
			int T;
			in >> T;
			for (int t = 1; t <= T; t++)
			{
				int K, N;
				in >> K >> N;
				Keys keys;
				for (int k = 0; k < K; k++)
				{
					int type;
					in >> type;
					keys[type]++;
				}

				vector<pair<int, vector<int>>> chests(N);
				map<int, vector<int>> chestsKeys;
				for (int i = 0; i < N; i++)
				{
					int keyType, numKeys;
					in >> keyType >> numKeys;
					vector<int> keysInChest(numKeys);
					for (int j = 0; j < numKeys; j++)
					{
						in >> keysInChest[j];
						chestsKeys[keysInChest[j]].push_back(i);
					}
					chests[i] = make_pair(keyType, keysInChest);
				}

				out << "Case #";
				vector<int> res;
				if (check(keys, chests, Flag(), res))
				{
					out << t << ":";
					for (auto r : res)
					{
						out << " " << r + 1;
					}
					out << endl;
				}
				else
				{
					out << t << ": IMPOSSIBLE" << endl;
				}
			}
			return 0;
		}

	};
}
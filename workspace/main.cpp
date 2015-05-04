#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <limits>
#include <map>
using namespace std;

int P;
vector<int> p;
map<pair<int, int>, int> memo;

int calc(int a, int b) {
    auto key = make_pair(a, b);
    auto iter = memo.find(key);
    if (iter != memo.end())
	return iter->second;
    
    int res = 0;
    for (auto q : p) {
	if (a <= q && q <= b) {
	    int tmp = (b - a) + calc(a, q - 1) + calc(q + 1, b);
	    if (!res || tmp < res)
		res = tmp;
	}
    }
    return memo[key] = res;
}

int solve(int P_, const vector<int> &p_) {
    P = P_;
    p = p_;
    memo.clear();
    return calc(1, P);
}

int result() {
    int P_, Q_;
    cin >> P_ >> Q_;
    vector<int> p_(Q_);
    for (int i = 0; i < Q_; i++)
	cin >> p_[i];
    return solve(P_, p_);
}

#ifndef CATCH_CONFIG_MAIN
int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
	cout << "Case #" << t << ": " << result() << endl;
    }
    return 0;
}
#endif

#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <limits>
#include <map>
#include <tuple>
#include <queue>
using namespace std;

typedef tuple<long, long, long> DHM;
typedef tuple<long, long, long, long> hiker;
long solve(const vector<DHM> &groups) {
    long j = 0;
    long maxH = 0;
    
    priority_queue<hiker, std::vector<hiker>, std::greater<hiker> > que;
    for (auto g : groups) {
	auto D = get<0>(g);
	auto H = get<1>(g);
	auto M = get<2>(g);
	for (int h = 0; h < H; h++) {
            auto t = (M + h) * (360 - D);
	    que.push(make_tuple(t, j, M + h, 0));
            j += 1;
	}
    }

    maxH = j;
    // auto newQ = que;
    // while (!newQ.empty()) {
    // 	auto x = newQ.top();
    // 	cout << get<0>(x) << "," << get<1>(x) << "," << get<2>(x) << "," << get<3>(x) << endl;
    // 	newQ.pop();
    // }

    // cout << que.empty() << endl;
    
    auto c = maxH;
    auto res = maxH;
    vector<bool> used(maxH);
    long lastT = -1;
    long cnt = 0;
    //    cout << cnt << "," << maxH << endl;
    while (cnt < maxH) {
	auto t = get<0>(que.top());
        while (t == get<0>(que.top())) {
            auto current = que.top();
	    que.pop();
            if (!used[get<1>(current)]) {
                used[get<1>(current)] = true;
                c -= 1; 
	    } else {
                c += 1;
                cnt += 1;
	    }
                
            que.push(make_tuple(get<0>(current) + get<2>(current) * 360, get<1>(current), get<2>(current), get<3>(current) + 1));

	    // auto newQ = que;
	    // while (!newQ.empty()) {
	    // 	auto x = newQ.top();
	    // 	cout << get<0>(x) << "," << get<1>(x) << "," << get<2>(x) << "," << get<3>(x) << endl;
	    // 	newQ.pop();
	    // }	    
	}
	res = min(res, c);
    }        
    return res;
}

int result() {
    int N;
    cin >> N;
    vector<DHM> dhm(N);
    for (int i = 0; i < N; i++) {
	int d, h, m;
	cin >> d >> h >> m;
	dhm[i] = make_tuple(d, h, m);
    }
    return solve(dhm);
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

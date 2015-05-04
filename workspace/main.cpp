#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

long solve(int x) {
    return x;
}

string result() {
    int x;
    cin >> x;
    return to_string(solve(x));
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

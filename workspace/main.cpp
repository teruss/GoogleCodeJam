#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

long solve(int x) {
    return 0;
}

string result() {
    int x;
    cin >> x;
    return "" + solve(x);
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
	cout << "Case #" << t << ": " << result() << endl;
    }
    return 0;
}

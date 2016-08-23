#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

vector<int> max, min;

string insert(int i) {

	if (max.empty()) {
		max.push_back(i);
		return string(i);
	}
	if (min.empty()) {
		min.push_back(i);
		return string(i);
	}
	if (max[0] < min[0]) {
		int t = max[0];
		max[0] = min[0];
		min[0] = t;
	}

	
}

int main() {

	make_heap (max.begin(), max.end());
	make_heap (min.begin(), min.end());


	int N;
	char c;
	int i;
	cin >> N;
	while (N--) {
		cin >> c >> i;
	}
    return 0;
}

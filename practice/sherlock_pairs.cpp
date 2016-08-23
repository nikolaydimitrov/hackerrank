#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;

uint64_t compute(uint64_t *a, uint64_t n) {

	uint64_t i, result = 0;
	unordered_map<uint64_t,uint64_t> counts;
	for (i=0; i<n; ++i) {
		counts[a[i]]++;
	}
	for (auto &kv : counts) {
		result += (kv.second-1)*kv.second;
	}
	return result;
}

int main() {

	uint64_t T, N, i, a[100000];
	cin >> T;
	while (T--) {
		cin >> N;
		for (i=0; i<N; ++i) {
			cin >> a[i];
		}
		cout << compute(a, N) << endl;
	}
	return 0;
}

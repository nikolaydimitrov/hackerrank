#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <climits>
using namespace std;

int main() {

	int64_t *a, N, i, res = LLONG_MIN, curres = 0, sum = 0;

	cin >> N;
	a = new int64_t[N];

	for (i=0; i<N; ++i) {
		cin >> a[i];
		curres += (i+1)*a[i];
		sum += a[i];
	}

	for (i=0; i<N; ++i) {
		if (res < curres) {
			res = curres;
		}
		curres -= sum;
		curres += N*a[i];
	}

	cout << res;

	delete a;
	return 0;
}

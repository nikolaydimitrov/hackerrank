#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {

	const int n=78;
	int a[n] = {-1,3,-4,5,1,-6,2,1};
	int i, sum = 0, left = 0;

	for (i=0; i<n; ++i) {
		sum += a[i];
	}
	for (i=0; i<n; ++i) {
		if (left == sum-left-a[i]) {
			cout << i << ", ";
		}
		left += a[i];
	}
    return 0;
}

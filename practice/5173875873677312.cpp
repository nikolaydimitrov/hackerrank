#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {

	const int n=6;
	int a[n+1] = {4,5,1,2,0,3,-1},
		i,j, emptySlot = n, moves = 0;

	for (i=0; i<n; ++i) {
		if (a[i] == i) continue;
		// Find where i is => j
		for (j=i+1; j<n+1; ++j) {
			if (a[j] == i) break;
		}
		a[emptySlot] = a[i];
		a[i] = a[j];
		emptySlot = j;
		a[j] = -1;
		moves += 2;

		while (j != n) {
			for (j=i+1; j<n+1; ++j) {
				if (a[j] == emptySlot) break;
			}
			a[emptySlot] = a[j];
			emptySlot = j;
			if (j!=n) {
				moves++;
			}
		}
	}
	for (i=0; i<n; ++i) {
		cout << a[i] << ",";
	}
	cout << endl << moves;

    return 0;
}

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

#define N 100000

int buf[N];

inline void swap(int &a, int &b) {
	int c = a;
	a = b;
	b = c;
}

void merge_sort(int *a, int l, int r) {
	if (l >= r) {
		return;
	}
	int m = l+(r-l)/2;
	merge_sort(a, l, m);
	merge_sort(a, m+1, r);

	int i=l, j=m+1, k=0;
	while (k < r-l+1) {
		while ((a[i]<=a[j] || j>r) && i<=m) {
			buf[k++] = a[i++];
		}
		while ((a[i]>=a[j] || i>m) && j<=r) {
			buf[k++] = a[j++];
		}
	}
	k--;
	while (k>=0) {
		a[l+k] = buf[k--];
	}
}

int main() {

	int a[] = {8,1,2,4,6,10,1,4,3,11,17,-1};
	merge_sort(a, 0, sizeof(a)/sizeof(int)-1);
	for (int i=0; i<sizeof(a)/sizeof(int); ++i) {
		cout << a[i] << ",";
	}
    return 0;
}


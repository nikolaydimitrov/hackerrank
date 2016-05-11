#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int solve(char *s, int len) {

	int l=0, r=len-1;
	while (l<=r) {
		if (s[l] != s[r]) {
			if (s[l+1] == s[r]
					&& -1 == solve(&s[l+1], r-l)) {
				return l;
			}
			if (s[l] == s[r-1]) {
				return r;
			}
		}
		l++;
		r--;
	}
	return -1;
}

int main() {

	int T;
	char s[200000];

	cin >> T;
	cin.getline(s, sizeof(s));
	do {
		cin.getline(s, sizeof(s));
		cout << solve(s, strlen(s)) << endl;
	} while (--T>0);

    return 0;
}

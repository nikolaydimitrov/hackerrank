#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int solve(string s) {

	int i, res = 0, len = s.length(), chars[26] = {0,};

	for (i=0; i<len; ++i) {
		chars[s[i]-'a'] += i<len/2 ? 1 : -1;
	}
	for (i=0; i<26; ++i) {
		res += abs(chars[i]);
	}
	return res%2 ? -1 : res/2;
}

int main() {

	int T;
	string s;

    cin >> T;
	do {
		cin >> s;
		cout << solve(s) << endl;
	} while (--T);

    return 0;
}

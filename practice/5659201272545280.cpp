#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {

	char *s = "hello world!";
	char *t = "ac";
	int first[256]={0,};
	int last[256]={0,};

	for (int i=0; s[i]; ++i) {
		if (!first[s[i]]) {
			first[s[i]] = 1+i;
		}
		last[s[i]] = 1+i;
	}
	for (int i=0; t[i]; ++i) {
		if (!first[t[i]]) {
			cout << "not possible";
			return 1;
		}
		if (i==0) {
			continue;
		}
		if (last[t[i-1]] > first[t[i]]) {
			cout << "not possible";
			return 2;
		}
	}
	cout << "nice!";

    return 0;
}

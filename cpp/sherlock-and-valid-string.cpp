#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {

	long i, min=1000000, max=-1;
	string s;
	long count[26] = {0,};

    cin >> s;

	for (i=0; i<s.length(); ++i) {
		count[s[i]-'a']++;
	}

	for (i=0; i<26; ++i) {
        if (!count[i]) 
			continue;
		if (min > count[i])
			min = count[i];
		if (max < count[i])
			max = count[i];
	}

	long result = 1, cMin=0, cMax=0;
	for (i=0; i<26; ++i) {
        if (!count[i])
			continue;
        
		if (count[i] == min) {
			cMin++;
		}
		if (count[i] == max) {
			cMax++;
		}
		if (count[i]!=min && count[i]!=max) {
			result=0;
			break;
		}
	}
    if (min!=max && cMin>1 && min==1) {
		result = 0;
	}

	cout << (result ? "YES" : "NO");

    return 0;
}

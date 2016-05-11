#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


int main() {

    string s;
    cin>>s;

    int i, oddNum = 0;
    int chars[26] = {0,};

	for (i=0; i<s.length(); ++i) {
		++chars[s[i]-'a'];
	}
	for (i=0; i<26; ++i) {
		if (chars[i] % 2) {
			oddNum++;
		}
	}

    if(oddNum > 1)
        cout<<"NO";
    else
        cout<<"YES";

    return 0;
}

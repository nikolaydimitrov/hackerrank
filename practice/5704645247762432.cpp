#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

vector<string> test(string pattern, vector<string> in) {

	vector<string> answer;
	int i,j;
	for (i=0; i<in.size(); ++i) {
		char map[256]={0,};
		string &s = in[i];
		if (pattern.length() != s.length()) {
			continue;
		}

		for (j=0; j<pattern.length(); ++j) {
			if (map[pattern[j]] == 0) {
				map[pattern[j]] = s[j];
			}
			if (map[pattern[j]] != s[j]) {
				break;
			}
		}
		if (j == pattern.length()) {
			answer.push_back(s);
		}
	}
	return answer;
}
int main() {

	vector<string> a = test("acc", {"cda", "aaaa", "dff"});
	while (!a.empty()) {
		cout << a.front() << endl;
		a.pop_back();
	}
    return 0;
}

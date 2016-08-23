#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int compare(char *p1, char *p2) {

	int diff = 0;

	while (*p1 || *p2) {

		if (*p1 == *p2) {
			p1++;
			p2++;
		} else if (*p2 && *p1 == *(p2+1)) {
			p2++;
			diff++;
		} else if (*p1 && *(p1+1) == *p2) {
			p1++;
			diff++;
		} else if (*(p1+1) == *(p2+1)) {
			p1++;
			p2++;
			diff++;
		} else {
			diff += 2;
		}
		if (diff > 1) {
			return 1;
		}
	}
	if (*p1 == *p2) {
		return 0;
	}
    return 2;
}

int main() {

	char *s1[]={"1abcd","abcdf"};
	char *s2[]={"2abcd","abcdf2"};

	for (int i=0; i<2; ++i) {
		cout << (compare(s1[i], s2[i])==0 ? "Nice" : "Impossible") << endl;
	}

	return 0;
}

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {

	char buf[200] = "  this is a simple test  here  ";
	int s=0, l,r;

	printf("'%s'\n", buf);

	for (l=0; buf[l]; ++l) {
		if (buf[l] == ' ')
			s++;
	}
	r = l+s*2;

	while (l>=0) {
		if (buf[l] == ' ') {
			buf[r] = '0';
			buf[r-1] = '2';
			buf[r-2] = '%';
			r -= 3;
		} else {
			buf[r--] = buf[l];
		}
		l--;
	}

	printf("'%s'\n", buf);

	// Put it back together
	l=r=0;
	while (buf[r]) {
		if (buf[r]=='%'
			&& buf[r+1]=='2'
			&& buf[r+2]=='0') {

			buf[l++] = ' ';
			r += 3;
		} else {
			buf[l++] = buf[r++];
		}
	}
	buf[l] = 0;
	printf("'%s'", buf);

    return 0;
}

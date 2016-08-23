#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

void strrev(char *s) {
	int len = strlen(s);
	for (int k=0; k<len/2; ++k) {
		char t = s[k];
		s[k] = s[len-1-k];
		s[len-1-k] = t;
	}
}

void mult(char *a, char *b, char *c) {

	int carry, i, j, k;
	for (i=0; a[i]; ++i) {
		carry = 0;
		for (j=0; b[j]; ++j) {
			carry += (a[i]-'0') * (b[j]-'0') + c[j+i];
			c[j+i] = carry%10;
			for (int k=0; k<=i+j; ++k) {
				cout << (char)('0'+c[k]);
			}
			carry /= 10;
			cout << ", carry=" << carry << endl;
		}
		k = j+i-1;
		while (carry) {
			c[k++] = carry%10;
			carry /= 10;
		}
	}

	int len = i+j-1;
	for (int k=0; k<len; ++k) {
		c[k] += '0';
	}
	strrev(c);
}

int main() {

	char a[] = "99";
	char b[] = "99";
	char c[100]={0,};

	strrev(a);
	strrev(b);

	mult(a,b,c);

	cout << ">" << c << "<";

    return 0;
}

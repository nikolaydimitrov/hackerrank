#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

void perm(char *pref, int plen, char *left, int llen) {

	if (llen == 0) {
		puts(pref);
		return;
	}
	for (int i=0; i<llen; ++i) {
		pref[plen] = left[i];
		left[i] = left[llen-1];
		perm(pref,plen+1,left,llen-1);
		left[i] = pref[plen];
	}
}
int main() {

	char buf[10]={0,}, s[]="abcde";
	perm(buf,0,s,5);

    return 0;
}

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

#define n 6
int main() {

	int m[n][n]={{0,1,2,3,4,5},
				 {6,7,8,9,10,11},
				 {12,13,14,15,16,17},
				 {18,19,20,21,22,23},
				 {24,25,26,27,28,29},
				 {30,31,32,33,34,35}};

	int i,j,t;

	for (i=0; i<n/2+1; ++i) {
		for (j=i; j<n-i-1; ++j) {
			t = m[i][j];
			m[i][j] = m[n-1-j][i];
			m[n-1-j][i] = m[n-1-i][n-1-j];
			m[n-1-i][n-1-j] = m[j][n-1-i];
			m[j][n-1-i] = t;
		}
	}

	for (i=0; i<n; ++i) {
		for (j=0; j<n; ++j) {
			cout << m[i][j] << ",";
		}
		cout << endl;
	}

    return 0;
}

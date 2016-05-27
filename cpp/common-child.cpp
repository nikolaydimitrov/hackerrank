#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string a, b;
unsigned short m[5001][5001] = {0,};

int main() {

	cin >> a;
	cin >> b;

    for (int i=0; i<a.length(); ++i) {
		for (int j=0; j<a.length(); ++j) {
			if (a[i] == b[j])
				m[1+i][1+j] = 1 + m[i][j];
			else
				m[1+i][1+j] = max(m[i][1+j], m[1+i][j]);
		}
	}

	cout << m[a.length()][a.length()];

    return 0;
}

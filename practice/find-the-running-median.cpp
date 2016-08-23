#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

class MedianKeeper {

	vector<int> smaller, bigger;

public:

	float put(int x) {

		bigger.push_back(x);
		push_heap(bigger.begin(), bigger.end(), std::greater<int>());

		if (bigger.size()-smaller.size()>1) {
			// move one element from bigger to smaller
			smaller.push_back(bigger[0]);
			push_heap(smaller.begin(), smaller.end());

			pop_heap(bigger.begin(), bigger.end(), std::greater<int>());
			bigger.pop_back();
		}

		if (smaller.empty()) {
			return bigger[0];
		}

		if (bigger[0]<smaller[0]) {
			// swap top elements
			int s1 = smaller[0];
			int b1 = bigger[0];

			pop_heap(smaller.begin(), smaller.end());
			smaller.pop_back();
			pop_heap(bigger.begin(), bigger.end(), std::greater<int>());
			bigger.pop_back();


			smaller.push_back(b1);
			push_heap(smaller.begin(), smaller.end());
			bigger.push_back(s1);
			push_heap(bigger.begin(), bigger.end(), std::greater<int>());
		}

		if (bigger.size() == smaller.size()) {
			return (float)(smaller[0]+bigger[0]) / 2;
		}
		return bigger[0];
	}

	void debug() {

		cout << "Smaller: ";
		for (int i=0;i<smaller.size();++i)
			cout << smaller[i] << ",";
		cout << "\nBigger: ";
		for (int i=0;i<bigger.size();++i)
			cout << bigger[i] << ",";
		cout << endl;
	}
};

int main() {

	MedianKeeper keeper;
	int n, x;

	cin >> n;

	while (n--) {
		cin >> x;
		printf("%.1f\n", keeper.put(x));
		//keeper.debug();
	}

	return 0;
}

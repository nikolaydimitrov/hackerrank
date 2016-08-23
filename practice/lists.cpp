#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

struct Node {
	Node *next;
	int val;
	Node(int v) {
		val = v;
		next = 0;
	}

	void print() {
		cout << val << ",";
		if (next) {
			next->print();
		}
	}

	void revPrint() {
		if (next) {
			next->revPrint();
		}
		cout << val << ",";
	}

	int nth(int n) {
		if (n==1) {
			return val;
		} else if (next) {
			return next->nth(n-1);
		} else {
			return -1;
		}
	}

	int revnth(int n) {
		if (!next) {
			return 1;
		} else {
			int nextCount = 1+next->revnth(n);
			if (nextCount == n) {
				cout << "Found: " << val;
			}
			return nextCount;
		}
	}

	void removeMiddle() {
		val = next->val;
		next = next->next;
	}
};


int main() {

	Node *h = new Node(3);
	h->next = new Node(1);
	h->next->next = new Node(5);


	Node *h2 = new Node(5);
	h2->next = new Node(9);
	h2->next->next = new Node(2);

	Node *t=new Node(0), *r=t;
	int car = 0;

	while (car || h || h2) {
		car += (h ? h->val : 0) + (h2 ? h2->val : 0);
		h && (h=h->next);
		h2 && (h2=h2->next);
		t->val = car%10;
		car /= 10;
		if(car || h || h2) {
			t->next = new Node(0);
			t = t->next;
		}
	}

	r->print();
    return 0;
}

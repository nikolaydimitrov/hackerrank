#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

struct Node {

	Node *left, *right;
	int val;

	Node(int v, Node *l=0, Node *r=0) {
		val = v;
		left = l;
		right = r;
	}

	void print(int l=0) {
		cout << val << endl;

		if (left) {
			for (int i=0; i<l; ++i) cout << "  ";
			cout << "l-";
			left->print(l+1);
		}
		if (right) {
			for (int i=0; i<l; ++i) cout << "  ";
			cout << "r-";
			right->print(l+1);
		}
	}
};

struct TreeBuilder {

	int c;
	int *a;
	int size;
	Node *root;

	int insert(Node *&n, int rightLimit) {

		if (c >= size) return -1;

		if (!n) {
			n = new Node(a[c++]);
			return 1;
		}

		int t=0;
		if (n->val > a[c]) {
			t = insert(n->left, n->val);
		} else if (a[c] < rightLimit) {
			t = insert(n->right, 1000);
		}

		return t;
	}

	TreeBuilder(int *arr, int total) {
		a = arr;
		c = 0;
		size = total;

		root = 0;
		while (insert(root, 1000) >= 0);
	}


};

int main() {

	int a[] = {5, 3, 1, 4, 8, 10};

	Node *root = new Node(5,
		new Node(3, new Node(1), new Node(4)),
		new Node(8, 0, new Node(10))
	);
	root->print();

	cout << "\n\n";

	TreeBuilder builder(a, 6);
	builder.root->print();

	return 0;
}

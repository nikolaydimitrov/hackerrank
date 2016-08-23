#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <climits>
#include <unordered_map>
using namespace std;

struct Node {
	int count;
	std::unordered_map<char, Node*> children;

	Node() {
		count = 1;
	}
	void add(string &s, int pos) {
		if (pos>=s.length()) return;

		auto it = children.find(s[pos]);
		if (it != children.end()) {
			(*it).second->count++;
			(*it).second->add(s, pos+1);
		} else {
			Node *n = new Node();
			n->add(s, pos+1);
			children.insert(std::unordered_map<char, Node*>::value_type(s[pos], n));
		}
	}
};

struct Trie {
	Node top;
	Trie() {
		top.count = 0;
	}

	void add(string &s) {
		top.add(s, 0);
	}

	int find(string &s) {

		int last = 0;
		Node *cur = &top;
		for (int i=0; i<s.length(); ++i) {
			auto it = cur->children.find(s[i]);
			if (it == cur->children.end()) {
				return 0;
			}
			cur = (*it).second;
			last = cur->count;
		}
		return last;
	}
};

int main() {

	Trie trie;
	char buf[100];
	string s;
	int N;

	cin >> N;
	cin.getline(buf, 100);

	while (N--) {
		cin.getline(buf, 100);
		if (buf[0] == 'a') {
			s = string(&buf[4]);
			trie.add(s);
		} else {
			s = string(&buf[5]);
			cout << trie.find(s) << endl;
		}
	}
//	trie.add(s="hack");
//	trie.add(s="hackerrank");
//
//	cout << trie.find(s="hac") << endl;
	return 0;
}

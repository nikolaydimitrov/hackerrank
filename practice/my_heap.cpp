#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

struct Heap {
	int a[100];
	int size;
	Heap() : size(0) {}

	void floatUp(int index) {
		int t;
		while (index>1 && a[index-1]>a[index/2-1]) {
			t = a[index-1];
			a[index-1] = a[index/2-1];
			a[index/2-1] = t;
			index /= 2;
		}
	}
	void sinkDown(int index) {
		int t, newIndex;
		while (index<size) {
			if (a[index-1]>a[index*2-1] && a[index-1]>a[index*2]) {
				break;
			}
			newIndex = a[index*2-1] > a[index*2] ? index*2 : index*2+1;
			t = a[index-1];
			a[index-1] = a[newIndex-1];
			a[newIndex-1] = t;
			index = newIndex;

			for (int i=0; i<size; ++i) {
				//cout << a[i] << ",";
			}
			//cout << endl;
		}
	}

	void put(int x) {
		a[size++] = x;
		floatUp(size);
	}
	int top() {
		return a[0];
	}
	int pop() {
		int r = a[0];
		a[0] = a[--size];
		a[size] = 0;
		sinkDown(1);
		return r;
	}
	bool empty() {
		return size==0;
	}
};

int main() {

	Heap heap;
	heap.put(1);
	heap.put(2);
	heap.put(3);
	heap.put(4);
	heap.put(5);
	heap.put(6);

	for (int i=0; i<heap.size; ++i) {
		cout << heap.a[i] << ",";
	}
	cout << endl;
	while (!heap.empty()) {
		cout << heap.pop() << ",";
		//heap.pop();
	}
    return 0;
}

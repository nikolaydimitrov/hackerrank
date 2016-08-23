#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

struct MaxHeap {
	int a[100];
	int size;
	MaxHeap() : size(0) {}

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

struct MinHeap {
	int a[100];
	int size;
	MinHeap() : size(0) {
		for (int i=0; i<100; ++i) {
			a[i] = 10000;
		}
	}

	void floatUp(int index) {
		int t;
		while (index>1 && a[index-1]<a[index/2-1]) {
			t = a[index-1];
			a[index-1] = a[index/2-1];
			a[index/2-1] = t;
			index /= 2;
		}
	}
	void sinkDown(int index) {
		int t, newIndex;
		while (index<size) {
			if (a[index-1]<a[index*2-1] && a[index-1]<a[index*2]) {
				break;
			}
			newIndex = a[index*2-1] < a[index*2] ? index*2 : index*2+1;
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
		a[size] = 10000;
		sinkDown(1);
		return r;
	}
	bool empty() {
		return size==0;
	}
};

struct MedianKeeper {

	MinHeap biggerNumbers;
	MaxHeap smallerNumbers;

	float put(int x) {
		if (biggerNumbers.empty()) {
			biggerNumbers.put(x);
			return x;
		}
		if (smallerNumbers.empty()) {
			smallerNumbers.put(x);
			return (float)(smallerNumbers.top()+biggerNumbers.top())/2;
		}

		biggerNumbers.put(x);
		if (biggerNumbers.size-smallerNumbers.size>1) {
			smallerNumbers.put(biggerNumbers.pop());
		}

		if (smallerNumbers.top() > biggerNumbers.top()) {
			int t = smallerNumbers.a[0];
			smallerNumbers.a[0] = biggerNumbers.a[0];
			biggerNumbers.a[0] = t;
		}

		if ((smallerNumbers.size+biggerNumbers.size)%2) {
			return biggerNumbers.top();
		} else {
			return (float)(smallerNumbers.top()+biggerNumbers.top())/2;
		}
	}
	void debug() {
		int i;
		cout << "Smaller: ";
		for (i=0; i<smallerNumbers.size; ++i) {
			cout << smallerNumbers.a[i] << ",";
		}
		cout << "\nBigger: ";
		for (i=0; i<biggerNumbers.size; ++i) {
			cout << biggerNumbers.a[i] << ",";
		}
		cout << endl;
	}
};

int main() {

	MedianKeeper keeper;
	cout << keeper.put(3) << endl;keeper.debug();
	cout << keeper.put(4) << endl;keeper.debug();
	cout << keeper.put(5) << endl;keeper.debug();
	cout << keeper.put(1) << endl;keeper.debug();
	cout << keeper.put(2) << endl;keeper.debug();
	cout << keeper.put(6) << endl;keeper.debug();

    return 0;
}

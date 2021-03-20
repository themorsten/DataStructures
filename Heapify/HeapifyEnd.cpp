#include <iostream>
using namespace std;

void SiftDown(int*, int, int);
void HeapifyEnd(int*, int);

int main() {
	int size = 10;
	int* c = new int[size];
	for (int i = 0; i < size; i++) c[i] = rand() % 10;
	HeapifyEnd(c, size);

	for (int i = 0; i < size; i++) cout << c[i]<<" ";
	return 0;
}

void SiftDown(int* A, int i, int size) {
	while (2 * i + 1 < size) {
		int j = i;
		if (A[j] < A[2 * i + 1]) j = 2 * i + 1;
		if (2 * i + 2 < size && A[j] < A[2 * i + 2]) j = 2 * i + 2;
		if (i == j) break;
		else {
			swap(A[i], A[j]);
			i = j;
		}
	}
}

void HeapifyEnd(int* A, int size) {
	for (int i = size - 1; i >= 0; i--) {
		if (2 * i + 1 < size) SiftDown(A,i,size);
	}
}

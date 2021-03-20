#include <iostream>
using namespace std;

void SiftUp(int*, int);
void HeapifyBegin(int*, int);


int main() {
	int size = 10;
	int* c = new int[size];
	for (int i = 0; i < size; i++) c[i] = rand() % 10;
  
	HeapifyBegin(c, size);

	for (int i = 0; i < size; i++) cout << c[i]<<" ";
  
  delete []c;
	return 0;
}

void SiftUp(int* A, int i) {
	while (i && A[i] > A[(i - 1) / 2]) {
		swap(A[i], A[(i - 1) / 2]);
		i = (i - 1) / 2;
	}
}

void HeapifyBegin(int* A, int size) {
	for (int i = 1; i <size; i++) SiftUp(A, i);
}

#include<iostream>
using namespace std;

class HeapMin{
protected:
	int size;
	int MaxSize;
	int* H;

public:
	HeapMin(int i = 0);
	~HeapMin(void);

	int Size() {
		return size;
	}

	void SiftUp(int i) {
		while (i && H[i] < H[(i - 1) / 2]) {
			swap(H[i], H[(i - 1) / 2]);
			i = (i - 1) / 2;
		}
	}

	void SiftDown(int i) {
		while (2 * i + 1 < size) {
			int j = i;
			if (H[j] > H[2 * i + 1]) j = 2 * i + 1;
			if (2*i+2<size && H[j]>H[2*i+2]) j = 2 * i + 2;
			if (i == j) break;
			else {
				swap(H[i], H[j]);
				i = j;
			}
		}
	}

	void Insert(int k) {
		H[size] = k;
		SiftUp(size);
		size++;
	}

	int ExtractMin(void) {
		if (size) {
			int min = H[0];
			size--;
			H[0] = H[size];
			SiftDown(0);
			return min;
		}
		else {
			return NULL;
		}
	}
	
	void Show(void) {
		for (int i = 0; i < size; i++) cout << H[i] << " ";
		cout << endl;
	}
};

HeapMin::HeapMin(int i) : size(0), MaxSize(i), H(new int[MaxSize]) {
	//cout << "HeapMin::HeapMin(int i)\n";
}

HeapMin::~HeapMin() {
	if (MaxSize) delete[]H;
	//cout << "HeapMin::~HeapMin()\n";
}

int main() {
	int size = 15,j;
	HeapMin H(size);
	for (int i = 0; i < size; i++) {
		j = rand() % 10;
		H.Insert(j);
	}
	H.Show();
	// Извлекем минимальный элемент, в итоге получаем отсортированный список
	for (int i = 0; i < size; i++) {
		j = H.ExtractMin();
		cout << j << " ";
	}
	return 0;
}

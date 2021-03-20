#include<iostream>
using namespace std;

class HeapMax {
protected:
	int size;
	int MaxSize;
	int* H;

public:
	HeapMax(int i = 0); // конструктор
	~HeapMax(void); // деструктор

	int Size() {
		return size;
	}

	void SiftUp(int i) {
		while (i && H[i] > H[(i - 1) / 2]) {
			swap(H[i], H[(i - 1) / 2]);
			i = (i - 1) / 2;
		}
	}

	void SiftDown(int i) {
		while (2 * i + 1 < size) {
			int j = i;
			if (H[j] < H[2 * i + 1]) j = 2 * i + 1;
			if (2 * i + 2 < size && H[j] < H[2 * i + 2]) j = 2 * i + 2;
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

	int ExtractMax(void) {
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

// конструктор
HeapMax::HeapMax(int i) : size(0), MaxSize(i), H(new int[MaxSize]) {
	//cout << "HeapMax::HeapMax(int i)\n";
}

//деструктор
HeapMax::~HeapMax() {
	if (MaxSize) delete[]H;
	//cout << "HeapMax::~HeapMax()\n";
}

int main() {
	int size = 15, j;
	HeapMax H(size);
	for (int i = 0; i < size; i++) {
		j = rand() % 10;
		H.Insert(j);
	}
	H.Show();

	// Извлекем максимальный элемент, в итоге получаем реверснутый отсортированный список
	for (int i = 0; i < size; i++) {
		j = H.ExtractMax();
		cout << j << " ";
	}
	return 0;
}

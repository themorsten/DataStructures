#include <iostream>
using namespace std;

class Queue {
protected:
	const int size;		 // размер очереди
	int* Q;
	int csize;           // current size - текущий размер оцереди
	int h;				 // head - первый занятый 
	int t;               // tail - первый свободный


public:
	Queue(int i);

	int Size(void) {
		return csize;
	}
	bool Empty(void) {
		return csize == 0;
	}
	bool Full(void) {
		return csize == size - 1;
	}

	int Front(void) {
		if (size != 0) {
			return Q[h];
		}
		else {
			cout << "Queue is empty" << endl;
			return NULL;
		}
	}

	int Back(void) {
		if (size != 0) {
			int i = t;
			i--;
			i = (i % size + size) % size;
			return Q[i];
		}
		else {
			cout << "Queue is empty" << endl;
			return NULL;
		}

	}

	void Push(int x) {
		if (csize != size) {
			csize++;
			Q[t++] = x;
			t %= size;
		}
		else cout << "Queue overflow" << endl;
		// if (t > size) t = 0;
	}

	int Pop(void) {
		if (size != 0) {
			int pop = Q[h];
			h++;
			h %= size;
			csize--;
			return pop;
		}
		else cout << "Queue is empty" << endl;
		//if (h > size) h = 0;
	}
};


Queue::Queue(int i) : size(i) {
	if (size > 1) {
		Q = new int[size];
		t = h = 0;
	}
	else cout << "Wrong size" << endl;
}

int main() {
	Queue Q(2);
	Q.Push(35);
	Q.Push(21);
	cout << Q.Front() << endl;
	cout << Q.Back() << endl;
	//Q.Push(11);
	cout << Q.Pop() << endl;

	//cout << Q.Empty();

	return 0;
}

#include<iostream>
using namespace std;

class Stack {
protected:
	const int size;
	int* S;
	int top;

public:
	Stack(int i);
	~Stack(void);
	void Push(int x) {
		if (top + 1 != size) {
			top++;
			S[top] = x;
		}
		else cout << "Stack overflow" << endl;
	}

	int Top(void) {
		if (top != -1) return S[top];
		else {
			cout << "Stack is empty" << endl;
			return -1;
		}
	}

	int Pop(void) {
		if (top != -1) return S[top--];
		else {
			cout << "Stack is empty" << endl;
			return -1;
		}
	}

};

Stack::Stack(int i): size(i) {
	if (i <= 0) cout << "Wrong size" << endl;
	else {
		top = -1;
		S = new int[size];
	}
}
Stack::~Stack(void) {
	delete[]S;
}



int main() {
	Stack S(6);

	S.Push(1);
	S.Push(2);
	S.Push(4);
	S.Push(5);
	S.Push(4);
	S.Push(5);

	cout << S.Pop() << endl;
	cout << S.Pop() << endl;
	cout << S.Pop() << endl;
	cout << S.Pop() << endl;
	cout << S.Pop() << endl;
	cout << S.Pop() << endl;

	return 0;
}

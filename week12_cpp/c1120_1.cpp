#include <iostream>
using namespace std;

class Ex {
public:
	char ch;
	int n;
	virtual void prt() = 0;
};

class Ex1 :public Ex {
public:
	Ex1(char ch) {
		this->ch = ch;
		this->n = 10;
	}
	Ex1(char ch, int n) {
		this->ch = ch;
		this->n = n;
	}
	void prt() {
		for (int i = 0; i < n; i++) {
			cout << ch << "  ";
		}
		cout << "(" << n << ")" << endl;
	}
};

int main() {
	Ex1* e1 = new Ex1('#');
	Ex1* e2 = new Ex1('@', 5);

	e1->prt();
	e2->prt();
}
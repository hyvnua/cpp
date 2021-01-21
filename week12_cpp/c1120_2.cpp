#include <iostream>
using namespace std;

class Ex {
public:
	char ch;
	int n;
	virtual void prt() = 0;
};

class Ex2 :public Ex {
public:
	Ex2() {
		cout << "기호를 입력하세요: ";
		cin >> this->ch;
		while (true) {
			try {
				cout << "반복 횟수를 입력하세요. ";
				cin >> n;
				if (n < 0) {
					throw n;
				}
				this->n = n;
				break;

			}
			catch (int x) {
				cout << "반복 횟수로 음수는 입력할 수 없습니다." << endl;
				continue;
			}
		}
		
	}
	void prt() {
		for (int i = 0; i < n; i++) {
			cout << ch << "  ";
		}
		cout << "(" << n << ")" << endl;
	}
};

int main() {
	Ex2* e1 = new Ex2();
	e1->prt();
}
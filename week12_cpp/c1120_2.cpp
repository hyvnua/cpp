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
		cout << "��ȣ�� �Է��ϼ���: ";
		cin >> this->ch;
		while (true) {
			try {
				cout << "�ݺ� Ƚ���� �Է��ϼ���. ";
				cin >> n;
				if (n < 0) {
					throw n;
				}
				this->n = n;
				break;

			}
			catch (int x) {
				cout << "�ݺ� Ƚ���� ������ �Է��� �� �����ϴ�." << endl;
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
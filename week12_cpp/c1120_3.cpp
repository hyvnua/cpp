#include <iostream>
#include <cstring>
using namespace std;

class Ex {
public:
	char ch;
	int n;
	virtual void input() = 0;
	virtual void prt() = 0;
};

class Ex3 :public Ex {
public:
	void input() {
		cout << "��ȣ�� �Է��ϼ���: ";
		cin >> ch;
		try {
			cout << "�ݺ� Ƚ���� �Է��ϼ���. ";
			cin >> n;
			if (n < 0) throw n;
			this->ch = ch;
			this->n = n;
		}
		catch (int n) {
			cout << "�ݺ� Ƚ���� ������ �Է¹��� �� �����ϴ�." << endl;
			cout << "�Է¹��� Ƚ���� �ٽ� �Է��ϼ���. ";
			int x;
			cin >> x;
			input(ch, x);
		}
		
	}
	void input(char ch) {
		this->ch = ch;
		n = 10;
	}
	void input(char ch, int n) {
		try {
			if (n < 0) throw n;
			this->ch = ch;
			this->n = n;
		}
		catch (int n) {
			cout << "�ݺ� Ƚ���� ������ �Է¹��� �� �����ϴ�." << endl;
			cout << "�Է¹��� Ƚ���� �ٽ� �Է��ϼ���. ";
			int x;
			cin >> x;
			input(ch, x);
		}
	}
	void prt() {
		string cnt[] = { "ù","��","��" };
		static int count = 0;
		cout << cnt[count] << "��° ��� ��� : ";
		for (int i = 0; i < n; i++) {
			cout << ch << "  ";
		}
		cout << "(" << n << ")" << endl;
		count++;
	}
};

int main() {
	Ex3* e1 = new Ex3();
	Ex3* e2 = new Ex3();
	Ex3* e3 = new Ex3();

	e1->input();
	e1->prt();

	e2->input('#');
	e2->prt();
	
	e3->input('@', 5);
	e3->prt();

}
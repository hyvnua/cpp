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
		cout << "기호를 입력하세요: ";
		cin >> ch;
		try {
			cout << "반복 횟수를 입력하세요. ";
			cin >> n;
			if (n < 0) throw n;
			this->ch = ch;
			this->n = n;
		}
		catch (int n) {
			cout << "반복 횟수로 음수를 입력받을 수 없습니다." << endl;
			cout << "입력받을 횟수를 다시 입력하세요. ";
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
			cout << "반복 횟수로 음수를 입력받을 수 없습니다." << endl;
			cout << "입력받을 횟수를 다시 입력하세요. ";
			int x;
			cin >> x;
			input(ch, x);
		}
	}
	void prt() {
		string cnt[] = { "첫","두","세" };
		static int count = 0;
		cout << cnt[count] << "번째 출력 결과 : ";
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
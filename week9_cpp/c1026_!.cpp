#include <iostream>
using namespace std;

class cal {
public:
	int cnt = 0;
	int sum = 0;
	
	int f, d, k; //f- first, d- dest, k= 배수
	virtual void input() = 0;
	virtual void proc() = 0;
	virtual void output() = 0;
	virtual void iferror() = 0;
};

class realcal : public cal {
public:
	void input() {
		int temp;
		cout << "초기값, 최종값, 출력하고자 하는 배수를 입력하세요: ";
		cin >> f;
		cin >> d;
		cin >> k;

		if(d < f) {
			temp = d;
			d = f;
			f = temp;
		}


		if (k < 0) {
			cout << "배수는 음수를 사용할 수 없습니다. 양수를 입력하세요: ";
			iferror();
		}
	}

	void iferror() {
		cin >> k;
		if (k < 0) {
			cout << "배수는 음수를 사용할 수 없습니다. 양수를 입력하세요: ";
			iferror();
		}
	}

	void proc() {
		for (int i = f; i <= d; i++) {
			if (i % k == 0) {
				printf("%3d ", i);
				cnt++;
				sum = sum + i;
				if (cnt % 10 == 0) {
					cout << endl;
				}
			}
		}
	}

	void output() {
		cout << endl << k << " 배수의 개수: " << cnt << ", 합: " << sum << endl;
	}
};

int main2() {
	realcal c;
	c.input();
	c.proc();
	c.output();

	return 0;
}
#include <iostream>
using namespace std;

class Calc {
public:
	int num;
	double* a;
	double hap = 0;
	double ave = 0;
	virtual void input() = 0;
	virtual void hapave() = 0;
	virtual void output() = 0;

};

class RealCalc :public Calc {
public:
	void input() {
		while (true) {
			try {

				cout << "정수의 개수를 입력하세요: ";
				cin >> num;
				if (num <= 0) {
					throw "배열의 크기로 음수와 0은 사용할 수 없습니다.";
				}
				a = new double[num];
			}
			catch (const char* s) {
				cout << s << endl;
				continue;
			}
			break;
		}
		while (true) {
			try {
				for (int i = 0; i < num; i++) {
					cout << "점수를 입력하세요: ";
					cin >> a[i];
					if (a[i] < 0) {
						i--;
						throw a[i];
					}

				}
			}
			catch (double x) {
				cout << "점수에는 음수를 입력할 수 없습니다" << endl << "처음부터 다시 ";
				continue;
			}

			break;
		}

	}

	void hapave() {
		for (int i = 0; i < num; i++) {
			hap = hap + a[i];
		}
		ave = hap / num;
	}

	void output() {
		cout << "점수의 총 합은 " << hap << "이고, 평균은 " << ave << "입니다." << endl;
	}
};

int main1() {
	RealCalc c;
	c.input();
	c.hapave();
	c.output();

	return 0;
}
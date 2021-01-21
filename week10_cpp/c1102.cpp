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

				cout << "������ ������ �Է��ϼ���: ";
				cin >> num;
				if (num <= 0) {
					throw "�迭�� ũ��� ������ 0�� ����� �� �����ϴ�.";
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
					cout << "������ �Է��ϼ���: ";
					cin >> a[i];
					if (a[i] < 0) {
						i--;
						throw a[i];
					}

				}
			}
			catch (double x) {
				cout << "�������� ������ �Է��� �� �����ϴ�" << endl << "ó������ �ٽ� ";
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
		cout << "������ �� ���� " << hap << "�̰�, ����� " << ave << "�Դϴ�." << endl;
	}
};

int main1() {
	RealCalc c;
	c.input();
	c.hapave();
	c.output();

	return 0;
}
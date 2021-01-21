#include <iostream>
using namespace std;

class cal {
public:
	int cnt = 0;
	int sum = 0;
	
	int f, d, k; //f- first, d- dest, k= ���
	virtual void input() = 0;
	virtual void proc() = 0;
	virtual void output() = 0;
	virtual void iferror() = 0;
};

class realcal : public cal {
public:
	void input() {
		int temp;
		cout << "�ʱⰪ, ������, ����ϰ��� �ϴ� ����� �Է��ϼ���: ";
		cin >> f;
		cin >> d;
		cin >> k;

		if(d < f) {
			temp = d;
			d = f;
			f = temp;
		}


		if (k < 0) {
			cout << "����� ������ ����� �� �����ϴ�. ����� �Է��ϼ���: ";
			iferror();
		}
	}

	void iferror() {
		cin >> k;
		if (k < 0) {
			cout << "����� ������ ����� �� �����ϴ�. ����� �Է��ϼ���: ";
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
		cout << endl << k << " ����� ����: " << cnt << ", ��: " << sum << endl;
	}
};

int main2() {
	realcal c;
	c.input();
	c.proc();
	c.output();

	return 0;
}
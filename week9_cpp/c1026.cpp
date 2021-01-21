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
};

class realcal : public cal {
public:
	void input() {
		cout << "�ʱⰪ, ������, ����ϰ��� �ϴ� ����� �Է��ϼ���: ";
		cin >> f;
		cin >> d;
		cin >> k;
	}

	void proc() {
		for (int i = f; i <= d; i++) {
			if (i % k == 0) {
				cout << i << " ";
				cnt++;
				sum = sum + i;
				if (cnt % 10 == 0) {
					cout << endl;
				}
			}
		}
	}

	void output() {
		cout << k << " ����� ����: " << cnt << ", ��: " << sum << endl;
	}
};

int main1() {
	realcal c;
	c.input();
	c.proc();
	c.output();

	return 0;
}
#include <iostream>
#include <cstring>
using namespace std;

namespace cityInfo {
	class cityInfo {
	public:
		string* source;
		int num;
		virtual void input() = 0;
		virtual void datainput() = 0;
		virtual void output() = 0;
	};

	class realCityInfo : public cityInfo {
	public:
		void input() {
			cout << "�Է��� ������ ����� �ּ��� : ";
			try {
				cin >> num;
				if (num > 5 || num < 0) throw num;
			}
			catch (int a) {
				cout << "�Է¹��� �� �ִ� �������� ������ �ʰ��߰ų� ������ �Է��߽��ϴ�." << endl;
				input();
			}

			source = new string[num];
		}
		void datainput() {
			for (int i = 0; i < num; i++) {
				cout << "[" << i << "] ������ : ";
				cin >> source[i];
			}
		}
		void output() {
			string data[] = { "����","������ ���","�λ�","�ؾ� ���","��õ","���� �ǰ� ���","��õ","�ױ� ���","���","���� ���" };
			cout << "�� ���ú� Ư��ȭ �����Դϴ�." << endl;
				for (int i = 0; i < num; i++) {
					for (int j = 0; j < 10; j += 2) {
						if (source[i] == data[j]) {
							cout << "[" << data[j] << "]�� " << data[j + 1] << "�� �ߴ޵� �����Դϴ�." << endl;
						}
					}
				}
			cout << "�̻� [" << num << "]�� �����Դϴ�." << endl;
		}
	};
}

int main() {
	cityInfo::realCityInfo a;
	a.input();
	a.datainput();
	a.output();
}
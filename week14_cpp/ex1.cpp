#include <iostream>
#include <fstream>
using namespace std;

int main() {
	ifstream is;
	is.open("score.txt");
	if (!is) {
		cerr << "���� ���¿� �����Ͽ����ϴ�" << endl;
		exit(1);
	}

	char c;
	is.get(c);

	while (!is.eof()) {
		cout << c;
		is.get(c);
	}
	cout << endl;
	is.close();
	return 0;
}
#include <iostream>
#include <fstream>
using namespace std;

int main() {
	ifstream is;
	is.open("score2.txt");
	if (!is) {
		cerr << "���� ���¿� �����Ͽ����ϴ�" << endl;
		exit(1);
	}

	int number;
	char name[30];
	int score;
	is >> number >> name >> score;

	ofstream os;
	os.open("result.txt");
	os << number << "," << name << "," << score << endl;

	is.close();
	os.close();
	return 0;
}
#include <iostream>
#include <fstream>
using namespace std;

int main() {
	ifstream is;
	is.open("score2.txt");
	if (!is) {
		cerr << "파일 오픈에 실패하였습니다" << endl;
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
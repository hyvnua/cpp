#include <iostream>
#include <fstream>
using namespace std;

int main() {
	ifstream is;
	is.open("score.txt");
	if (!is) {
		cerr << "파일 오픈에 실패하였습니다" << endl;
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
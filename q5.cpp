#include <iostream>
#include <fstream>
using namespace std;

int bufmain() {
	ifstream fin("student2.txt");
	if (!fin) {
		cout << "student2.txt 열기 실패" << endl;
		return 0;
	}

	char buf[81];
	while (fin.getline(buf, 81)) {
		cout << buf << endl;
	}

	fin.close();
}
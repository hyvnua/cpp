#include <iostream>
#include <fstream>
using namespace std;

int foutfinmain() {
	const char* firstFile = "student.txt";
	const char* secondFile = "student2.txt";

	fstream fout(firstFile, ios::out | ios::app);
	if (!fout) {
		cout << firstFile << "열기 오류";
		return 0;
	}

	fstream fin(secondFile, ios::in);
	if (!fin) {
		cout << secondFile << "열기 오류";
		return 0;
	}

	int c;
	while ((c = fin.get()) != EOF) {
		fout.put(c);
	}

	fin.close();
	fout.close();
}
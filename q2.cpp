#include <iostream>
#include <fstream>
using namespace std;

int finmain() {
	ifstream fin;
	fin.open("student.txt");
	if (!fin) {
		cout << "������ �� �� ����";
		return 0;
	}
	
	char name[10], dept[20];
	int sid;

	fin >> name;
	fin >> sid;
	fin >> dept;

	cout << name << endl;
	cout << sid << endl;
	cout << dept << endl;

	fin.close();
}
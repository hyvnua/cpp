#include <iostream>
#include <fstream>
using namespace std;

int fin2main() {
	const char* file = "student2.txt";

	ifstream fin(file);
	if (!fin) {
		cout << file << "열기 오류" << endl;
		return 0;
	}
	int count = 0;
	int c;
	while ((c = fin.get()) != EOF) {
		cout << (char)c;
		count++;
	}
	cout << "읽은 바이트 수는 " << count << endl;
	fin.close();
}
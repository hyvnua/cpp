#include <iostream>
#include <fstream>
using namespace std;

int copymain() {
	const char* srcFile = "img1.jpg";
	const char* destFile = "img2.jpg";

	ifstream fsrc(srcFile, ios::in | ios::binary);
	if (!fsrc) {
		cout << srcFile << "열기 오류" << endl;
		return 0;
	}

	ofstream fdest(destFile, ios::out | ios::binary);
	if (!fdest) {
		cout << destFile << "열기 오류" << endl;
		return 0;
	}

	int c;
	while ((c = fsrc.get()) != EOF) {
		fdest.put(c);
	}
	cout << srcFile << "을 " << destFile << "로 복사 완료" << endl;
	fsrc.close();
	fdest.close();
}
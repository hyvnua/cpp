#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char* argv[]) {
	ifstream is;
	ofstream os;
	is.open(argv[1]);
	if (is.fail()) {
		cerr << "파일 오픈 실패" << endl;
		exit(1);
	}
	os.open(argv[2]);
	if (os.fail()) {
		cerr << "파일 오픈 실패" << endl;
		exit(1);
	}

	char c;
	int line_number = 1;
	is.get(c);
	os << line_number << ": ";
	while (!is.eof()) {
		os << c;
		if (c == '\n') {
			line_number++;
			os << line_number << ": ";
		}
		is.get(c);
	}
	is.close();
	os.close();
	return 0;
}
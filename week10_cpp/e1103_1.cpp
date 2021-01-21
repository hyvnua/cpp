#include <iostream>

using namespace std;
extern int ga;
extern void eFunPrint();

int main1103() {
	cout << "ga=" << ++ga << endl;
	eFunPrint();

	return 0;
}
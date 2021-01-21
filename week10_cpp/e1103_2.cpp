#include <iostream>
using namespace std;

class Math {
public:
	int abs(int a) {
		return a > 0 ? a : -a;
	}
	int max(int a, int b) {
		return (a > b) ? a : b;
	}
	int min(int a, int b) {
		return (a > b) ? b : a;
	}
};

int main() {
	Math k;
	
	cout << k.abs(-5) << endl;
	cout << k.max(10, 8) << endl;
	cout << k.min(-3, -8) << endl;

	return 0;
}
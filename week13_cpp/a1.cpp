#include <iostream>
using namespace std;

template <class T>
T biggest(T array[], int size) {
	if (size <= 0)
		return 0;
	T big = array[0];
	for (int i = 1; i < size; i++) {
		if (big < array[i])
			big = array[i];
	}
	return big;
}

int main() {
	int x[] = { 1,10,100,5,4 };
	cout << biggest(x, 5) << endl;
	double y[] = { 6.4, 3.3, -200.6, 7.7, 8.8, 20.3 };
	cout << biggest(y, 6);
}
#include <iostream>
using namespace std;

template <class T>
void reverseArray(T* array, int size) {
	for (int i = 0; i < size / 2; i++) {
		T tmp = array[i];
		array[i] = array[size - 1 - i];
		array[size - 1 - i] = tmp;
	}
	return;
}

int main() {
	int x[] = { 1,10,100,5,4 };
	reverseArray(x, 5);

	for (int i = 0; i < 5; i++)
		cout << x[i] << ' ';
	cout << endl;
}
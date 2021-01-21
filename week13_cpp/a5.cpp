#include <iostream>
using namespace std;

template <class T>
T* concat(T arr1[], int n1, T arr2[], int n2) {
	T* p = new T[n1 + n2];
	for (int i = 0; i < n1; i++) {
		p[i] = arr1[i];
	}
	for (int i = 0; i < n2; i++) {
		p[n1 + i] = arr2[i];
	}
	return p;
}

int main() {
	cout << "두 개의 정수 배열을 합칩니다" << endl;
	int x[] = { 1,2,3 };
	int y[] = { 6,7,8,9 };
	int* p = concat(x, 3, y, 4);
	for (int i = 0; i < 7; i++)
		cout << p[i] << ' ';
	cout << endl;
	delete[] p;

	cout << "두 개의 문자 배열을 합칩니다" << endl;
	char a[] = { 'L','o','v','e' };
	char b[] = { 'C','+','+' };
	char* q = concat(a, 4, b, 3);
	for (int i = 0; i < 7; i++)
		cout << q[i] << ' ';
	cout << endl;
	delete[] q;
}
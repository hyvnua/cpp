#include <iostream>
using namespace std;

template <class T>
bool search(T find, T array[], int size) {
	for (int i = 0; i < size; i++) {
		if (find == array[i]) return true;
	}
	return false;
}

int main() {
	int x[] = { 1,10,100,5,4 };
	if (search(100, x, 5)) cout << "100�� �迭 x�� ���ԵǾ� �ֽ��ϴ�";
	else cout << "100�� �迭 x�� ���ԵǾ� ���� �ʽ��ϴ�";
	cout << endl;

	char c[] = { 'h','e','l','l','o' };
	if (search('e', c, 5)) cout << "e�� �迭 c�� ���ԵǾ� �ֽ��ϴ�";
	else cout << "e�� �迭 c�� ���ԵǾ� ���� �ʽ��ϴ�";
	cout << endl;
}
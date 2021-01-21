#include <iostream>
#include <cstring>
using namespace std;

namespace cityInfo {
	class cityInfo {
	public:
		string* source;
		int num;
		virtual void input() = 0;
		virtual void datainput() = 0;
		virtual void output() = 0;
	};

	class realCityInfo : public cityInfo {
	public:
		void input() {
			cout << "입력할 개수를 등록해 주세요 : ";
			try {
				cin >> num;
				if (num > 5 || num < 0) throw num;
			}
			catch (int a) {
				cout << "입력받을 수 있는 데이터의 개수를 초과했거나 음수를 입력했습니다." << endl;
				input();
			}

			source = new string[num];
		}
		void datainput() {
			for (int i = 0; i < num; i++) {
				cout << "[" << i << "] 지역명 : ";
				cin >> source[i];
			}
		}
		void output() {
			string data[] = { "서울","교육과 상업","부산","해양 산업","춘천","도시 건강 산업","인천","항구 산업","울산","공업 산업" };
			cout << "각 도시별 특성화 내용입니다." << endl;
				for (int i = 0; i < num; i++) {
					for (int j = 0; j < 10; j += 2) {
						if (source[i] == data[j]) {
							cout << "[" << data[j] << "]은 " << data[j + 1] << "이 발달된 도시입니다." << endl;
						}
					}
				}
			cout << "이상 [" << num << "]개 지역입니다." << endl;
		}
	};
}

int main() {
	cityInfo::realCityInfo a;
	a.input();
	a.datainput();
	a.output();
}
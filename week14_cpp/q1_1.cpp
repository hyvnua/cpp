#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

void makeGraph();
char gethakjeom(double ave);
void sort(double ave[]);
int getGrade(double big[], double s);

int main() {
	ifstream is;
	is.open("data.txt");
	if (!is) {
		cerr << "data.txt파일이 없습니다.";
		exit(1);
	}
	ofstream os;
	os.open("result.txt");
	if (!os) {
		cerr << "result.txt파일이 없습니다.";
		exit(1);
	}
	string name[5];
	int score1[5];
	int score2[5];
	int score3[5];
	int total_score[5];
	double average[5];
	char hakjeom[5];
	int grade[5];
	double big[5];
	
	for (int i = 0; i < 5; i++) {
		is >> name[i] >> score1[i] >> score2[i] >> score3[i];
		total_score[i] = score1[i] + score2[i] + score3[i];
		average[i] = total_score[i] / 3.0;
		hakjeom[i] = gethakjeom(average[i]);
		big[i] = average[i];
	}
	
	sort(big);


	for (int i = 0; i < 5; i++) {
		grade[i] = getGrade(big, average[i]);
	}
	os << "┌──┬───┬───┬───┬───┬───┬───┬──┬──┐" << endl;
	os << "│번호│ 성명 │ 점수1 │ 점수2 │ 점수3│  총점 │ 평균 │학점│등수│" << endl;
	for (int i = 0; i < 5; i++) {
		os << "├──┼───┼───┼───┼───┼───┼───┼──┼──┤" << endl;
		os << right << "│" << setw(3) << i + 1 << "  │" << setw(6) << name[i];
		os << right << "│" << setw(6) << score1[i] << " ";
		os << right << "│" << setw(6) << score2[i] << " ";
		os << right << "│" << setw(6) << score3[i] << " ";
		os << fixed;
		os.precision(2);
		os << right << "│ " << setw(6) << total_score[i] << " │" << setw(6) << average[i] << "│" 
			<< setw(3) << hakjeom[i] << " │" << grade[i] << "/ 5 │" << endl;
	}
	os << "└──┴───┴───┴───┴───┴───┴───┴──┴──┘" << endl;

	is.close();
	os.close();
}

char gethakjeom(double ave) {
	char hakjeom;
	if (ave >= 90) hakjeom = 'A';
	else if (ave >= 80 && ave < 90) hakjeom = 'B';
	else if (ave >= 70 && ave < 80) hakjeom = 'C';
	else if (ave >= 60 && ave < 70) hakjeom = 'D';
	else hakjeom = 'F';
	return hakjeom;
}

void sort(double ave[]) {
	double temp;
	for (int i = 0; i < 4; i++) {
		for (int j = 1; j < 5; j++) {
			if (ave[j - 1] < ave[j]) {
				temp = ave[j - 1];
				ave[j - 1] = ave[j];
				ave[j] = temp;
			}
		}
	}
}

int getGrade(double big[], double s) {
	for (int i = 0; i < 5; i++) {
		if (big[i] == s)
			return i + 1;
	}
}
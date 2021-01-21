#include <iostream>
#include <fstream>
using namespace std;

void makeGraph();
char gethakjeon(double ave);
void sort(double ave[]);
int getGrade(double big[], double s);

int main() {
	ifstream is;
	ofstream os;
	is.open("data.txt");
	if (is.fail()) {
		cerr << "data.txt 파일이 없습니다" << endl;
		exit(1);
	}
	os.open("result.txt");
	if (os.fail()) {
		cerr << "result.txt 파일이 없습니다" << endl;
		exit(1);
	}

	char name[30][5];
	int score1[5];
	int score2[5];
	int score3[5];
	int total_score[5];
	double average[5];
	char hakjeom[5];
	int grade[5];
	double big[5];
	int s;

	char c;
	int line_number = 1;
	int count=0;
	
	is >> name[count] >> score1[count] >> score2[count] >> score3[count];
	total_score[count] = score1[count] + score2[count] + score3[count];
	average[count] = total_score[count] / 3.0;
	hakjeom[count] = gethakjeon(average[count]);
	big[count] = average[count];
	//sort(big);
	grade[count] = getGrade(big, average[count]);
	os << line_number << ": ";
	os << name[count] << "," << score1[count] << "," << score2[count] << "," << score3[count] << "," << total_score[count] << "," << average[count] << "," << hakjeom[count] << "," << grade[count] << endl;
	count++;
	line_number++;


	is.get(c);
	while(!is.eof()){
		is >> name[count] >> score1[count] >> score2[count] >> score3[count];
		total_score[count]=score1[count] + score2[count] + score3[count];
		average[count] = total_score[count] / 3.0;
		hakjeom[count] = gethakjeon(average[count]);
		big[count] = average[count];
		//sort(big);
		grade[count] = getGrade(big, average[count]);

		if (c == '\n') {
			os << line_number << ": ";
			os << name[count] << "," << score1[count] << "," << score2[count] << "," << score3[count] << "," << total_score[count] << "," << average[count] << "," << hakjeom[count] << "," << grade[count] << endl;
			line_number++;
			count++;
		}
		//is.get(c);
	}
	

	
	/*os << line_number << ": ";
	is.get(c);
	while (!is.eof()) {
		os << c;
		if (c == '\n') {
			line_number++;
			os << line_number << ": ";
		}
		is.get(c);
	}
	*/
	
	is.close();
	os.close();

	return 0;
}

void makeGraph() {
	
}

char gethakjeon(double ave) {
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
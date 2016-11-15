/*
년과 월을 입력 받아 해당하는 달의 달력을 파일로 저장
*/
#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;
int months[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
int main() {
	int year, month;
	cout << "input year" << endl;
	cin >> year;
	cout << "input month" << endl;
	cin >> month;
	int day = 0;
	day = (year - 1) * 365 + (year - 1) / 400 + (year - 1) / 4 - (year - 1) / 100;
	if (year%400==0 || ((year%100!=0 && year%4==0))) {
		day += 1;
	}
	for (int i = 1; i < month;i++) {
		day += months[i];
	}
	day = day % 7 + 1;
	ofstream calendar("output.txt");
	calendar << "<" << year << "-" << setw(2) << setfill('0') << month << ">" << endl;
	calendar << setfill(' ');
	calendar << setw(4) << " 일" << setw(4) << "월" << setw(4) << "화" << setw(4) << "수" << setw(4) << "목" << setw(4) << "금" << setw(4) << "토" << endl;
	calendar << setw((day + 1) * 4);
	for (int i = 1; i <= months[month]; i++) {
		calendar << i << setw(4);
		if (day % 7 == 6) {
			calendar << endl;
			day = 0;
		}
		else {
			day++;
		}
	}
	calendar << endl;
	calendar.close();
		/*
	cout << "<" << year << "-" << setw(2) << setfill('0') << month << ">" << endl;
	cout << setfill(' ');
	cout << setw(4) << " 일" << setw(4) << "월" << setw(4) << "화" << setw(4) << "수" << setw(4) << "목" << setw(4) << "금" <<setw(4)<< "토" << endl;
	cout << setw((day+1) * 4);
	for (int i = 1; i <= months[month];i++) {
		cout << i << setw(4);
		if (day%7==6) {
			cout << endl;
			day = 0;
		}
		else {
			day++;
		}
	}
	cout << endl;
	*/
	return 0;
}
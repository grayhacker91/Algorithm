#include<iostream>
#include<string>

using namespace std;

string m[8] = {"000","001","010","011","100","101","110","111"};

int main() {
	string binary;
	cin >> binary;
	int start = 0;
	if (binary.length()%3!=0) {
		start = 3 - binary.length() % 3;
	}
	for (int i = 0; i < start;i++) {
		binary.insert(0,"0");
	}
	string result = "";
	for (int i = 0; i < binary.length() + start; i+=3) {
		for (int j = 0; j < 8;j++) {
			if (binary.substr(i,3).compare(m[j])==0) {
				result.push_back(j + 48);
			}
		}
	}
	cout << result << endl;
	return 0;
}
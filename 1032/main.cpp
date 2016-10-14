#include<iostream>
#include<string>

using namespace std;

string arr[50];
int pattern[50][50];

int main() {
	for (int i = 0; i < 50;i++) {
		pattern[0][i] = 1;
	}
	int cnt;
	cin >> cnt;
	for (int i = 0; i < cnt;i++) {
		cin >> arr[i];
		if (i>0) {
			for (int j = 0; j < arr[i - 1].size();j++) {
				if (arr[i-1][j]==arr[i][j]) {
					pattern[i][j] = 1;
				}
			}
		}
	}
	string result = "";
	for (int i = 0; i < arr[0].size(); i++) {
		int c = 1;
		for (int j = 0; j < cnt; j++) {
			c = c&pattern[j][i];
		}
		if (c==1) {
			result += arr[0][i];
		}
		else {
			result += '?';
		}
	}
	cout << result << endl;
	return 0;
}
#include<iostream>
#include<string>

using namespace std;

int main() {
	int count = 0;
	for (int i = 0; i < 8;i++) {
		string s;
		cin >> s;
		for (int j = 0; j < 8;j++) {
			if (i % 2 == 0) {
				if (j % 2 == 0 && s[j] == 'F') {
					count++;
				}
			}
			else {
				if (j % 2 == 1 && s[j] == 'F') {
					count++;
				}
			}
		}
	}
	cout << count << endl;
	return 0;
}
#include<iostream>
#include<string>

using namespace std;

int main() {
	string str;
	cin >> str;
	for (int i = 0; i < str.size();i++) {
		if (str[i] - 3>=65) {
			char a = str[i] - 3;
			cout << a;
		}
		else {
			char a = str[i] + 23;
			cout << a;
		}
	}
	return 0;
}
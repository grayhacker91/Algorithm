#include<iostream>
#include<string>

using namespace std;

int main() {
	int alpabet[26];
	for (int i = 0; i < 26; i++) {
		alpabet[i] = -1;
	}
	string str;
	cin >> str;
	for (int i = 0; i < str.size();i++) {
		if (alpabet[str[i] - 97]==-1) {
			alpabet[str[i] - 97] = i;
		}
	}
	for (int i = 0; i < 26; i++) {
		cout << alpabet[i] << " ";
	}
	return 0;
}
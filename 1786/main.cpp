#include<iostream>
#include<string>
#include<vector>

using namespace std;

vector<int> arr;
int cnt = 0;

void kmp(string str, string pattern) {
	int *p = new int[pattern.length() + 1];
	p[0] = -1;
	int j = -1;
	for (int i = 0; i<pattern.length();) {
		if (j == -1 || pattern[i] == pattern[j]) {
			j++;
			i++;
			p[i] = j;
		}
		else {
			j = p[j];
		}
	}
	j = 0;
	for (int i = 0; i<str.length();) {
		if (j == -1 || str[i] == pattern[j]) {
			j++;
			i++;
		}
		else {
			j = p[j];
		}
		if (j == pattern.length()) {
			cnt++;
			arr.push_back(i - pattern.length() + 1);
			j = p[j];
		}
	}
}

int main() {
	string str, p;
	getline(cin,str);
	getline(cin, p);
	kmp(str, p);
	cout<<cnt<<endl;
	for (int i = 0; i<arr.size(); i++) {
		cout<<arr[i]<<endl;
	}
	return 0;
}
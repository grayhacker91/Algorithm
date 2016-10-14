#include<iostream>
#include<string>

using namespace std;

string reverse(string::iterator &it) {
	char head = *it;
	it++;
	if (head == 'b' || head == 'w') {
		return string(1, head);
	}
	string upperLeft = reverse(it);
	string upperRight = reverse(it);
	string lowerLeft = reverse(it);
	string lowerRight = reverse(it);
	return string("x") + lowerLeft + lowerRight + upperLeft + upperRight;
}

int main() {
	int testcase;
	cin >> testcase;
	for (int i = 0; i < testcase;i++) {
		string str;
		cin >> str;
		string result;
		for (string::iterator it = str.begin(); it != str.end(); ) {
			result += reverse(it);
		}
		cout << result << endl;
	}
	return 0;
}
#include<iostream>

using namespace std;

int main() {
	int testcase;
	cin >> testcase;
	for (int i = 0; i < testcase;i++) {
		int a, b;
		cin >> a >> b;
		int result = 1;
		for (int j = 0; j < b;j++) {
			if (a%10==0) {
				result = 10;
				break;
			}
			result *= a;
			result %= 10;
		}
		cout << result << endl;
	}
	return 0;
}
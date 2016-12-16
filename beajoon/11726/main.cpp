#include<iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	int val1 = 1;
	int val2 = 2;
	for (int i = 2; i < n;i++) {
		int temp = (val1%10007 + val2%10007)%10007;
		val1 = val2;
		val2 = temp;
	}
	if (n==1) {
		cout << val1 << endl;
	}
	else {
		cout << val2 << endl;
	}
	return 0;
}
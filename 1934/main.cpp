#include<iostream>

using namespace std;

int euclidean(int a, int b) {
	if (b%a == 0) {
		return a;
	}
	else {
		return euclidean(b%a, a);
	}
}

int main() {
	int testcase;
	cin >> testcase;
	for (int i = 0; i < testcase;i++) {
		int a, b;
		cin >> a >> b;
		if (a>b) {
			int temp = a;
			a = b;
			b = temp;
		}
		cout << a*b/euclidean(a, b) << endl;
	}
	return 0;
}
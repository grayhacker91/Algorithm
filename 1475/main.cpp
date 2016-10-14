#include<iostream>

using namespace std;

int number[10];

int main() {
	int val;
	cin >> val;
	int mok = val;
	while(true) {
		int r = mok % 10;
		mok = mok / 10;
		if (r == 9) {
			r = 6;
		}
		number[r]++;
		if (mok == 0) {
			if (number[6] % 2 == 0) {
				number[6] = number[6] / 2;
			}
			else {
				number[6] = number[6] / 2 + 1;
			}
			break;
		}
	}
	int max = 0;
	for (int i = 0; i < 9;i++) {
		if (max<number[i]) {
			max = number[i];
		}
	}
	cout << max << endl;
	return 0;
}
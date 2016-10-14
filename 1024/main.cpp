#include<iostream>

using namespace std;

int main() {
	int n, l;
	cin >> n >> l;
	for (int i = l; i <= 100;i++) {
		int end = n / i + i;
		int start = n / i - i;
		for (int j = end; j >= start;j--) {
			if (j-i+1<0) {
				continue;
			}
			long long int sum = (j*(j+1)-(j-i+1)*(j-i))/2;
			if (sum>n) {
				continue;
			}
			if (sum==n) {
				for (int k = j - i+1; k <= j; k++) {
					cout << k << " ";
				}
				return 0;
			}
		}
	}
	cout << -1 << endl;
	return 0;
}
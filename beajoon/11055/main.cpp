#include<iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	int A[1000] = { 0, };
	int sum[1000] = { 0, };;
	for (int i = 0; i < n; i++) {
		cin >> A[i];
		sum[i] = A[i];
	}
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (A[i]>A[j] && sum[i] < sum[j]+A[i]) {
				sum[i] = sum[j] + A[i];
			}
		}
	}
	int max = 0;
	for (int i = 0; i < n; i++) {
		if (sum[i]>max) {
			max = sum[i];
		}
	}
	cout << max << endl;
	return 0;
}
#include<iostream>

using namespace std;

int A[101];
int D[2][10001];

int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n;i++) {
		cin >> A[i];
	}
	for (int i = 1; i <= n;i++) {
		for (int j = 0; j <= k;j++) {
			if (i == 1 && j*A[i] <= k) {
				D[0][j*A[i]] = 1;
				D[1][j*A[i]] = 1;
			}
			else if (j>=A[i]) {
				D[1][j] = D[0][j] + D[1][j - A[i]];
			}
		}
		for (int j = 1; i !=1 && j <= k;j++) {
			D[0][j] = D[1][j];
		}
	}
	cout << D[0][k] << endl;
	return 0;
}
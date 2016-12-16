#include<iostream>
#include<algorithm>

using namespace std;

int A[101] = {10001,};
int D[10001];

int main() {
	int n, k;
	cin >> n >> k;
	int m = 0;
	for (int i = 1; i <= n;i++) {
		cin >> A[i];
		if (A[m] > A[i]) {
			m = i;
		}
	}
	for (int i = 1; i <= k;i++) {
		if (D[i]==0) {
			D[i] = 10001;
		}
		for (int j = 1; j <= n;j++) {
			if (i >= A[j]) {
				D[i] = min(D[i],min(D[i - A[j]] + 1, D[i - A[m]] + 1));
			}
		}
	}
	if (D[k]==10001) {
		D[k] = -1;
	}
	cout << D[k] << endl;
	return 0;
}
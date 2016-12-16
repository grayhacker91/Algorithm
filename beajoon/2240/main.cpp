#include<iostream>
#include<algorithm>

using namespace std;

int D[1001][30];
int A[1001];

int main() {
	int t, w;
	cin >> t >> w;
	for (int i = 1; i <= t;i++) {
		cin >> A[i];
	}
	if (A[1]==1) {
		D[1][0] = 1;
	}
	else {
		D[1][1] = 1;
	}
	for (int i = 2; i <= t;i++) {
		for (int j = 0; j <= w && j<i ;j++) {
			if (A[i]==1) {
				if (j%2==0) {
					D[i][j] = max(D[i][j],D[i - 1][j] + 1);
				}
				else {
					D[i][j] = max(D[i][j],D[i - 1][j]);
					if (j+1<=w) {
						D[i][j + 1] = max(D[i][j + 1], D[i - 1][j] + 1);
					}
				}
			}
			else {
				if(j%2==1) {
					D[i][j] = max(D[i][j],D[i - 1][j] + 1);
				}
				else {
					D[i][j] = max(D[i][j],D[i - 1][j]);
					if (j + 1 <= w) {
						D[i][j + 1] = max(D[i][j + 1], D[i - 1][j] + 1);
					}
				}
			}
		}
	}
	int m = 0;
	for (int i = 0; i <= w;i++) {
		if (m<D[t][i]) {
			m = D[t][i];
		}
	}
	cout << m << endl;
	return 0;
}
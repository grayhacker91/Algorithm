#include<iostream>

using namespace std;

int D[16][16];

void dp(int si,int sj, int ei,int ej) {
	for (int i = si; i <= ei;i++) {
		for (int j = sj; j <= ej;j++) {
			D[i][j] = D[i - 1][j] + D[i][j - 1];
		}
	}
}

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	D[1][0] = 1;
	int result = 0;
	if (k==0) {
		dp(1, 1, n, m);
	}
	else {
		int i, j;
		if (k%m==0) {
			i = k / m;
			j = m;
		}
		else {
			i = k / m + 1;
			j = k%m;
		}
		dp(1,1,i,j);
		dp(i,j,n,m);
	}
	cout << D[n][m] << endl;
	return 0;
}
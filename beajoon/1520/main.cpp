#include <iostream>
using namespace std;

int map[501][501];
int dp[501][501];
int di[] = { 0, 0, 1, -1 };
int dj[] = { 1, -1, 0, 0 };

int dy(int r, int c,int R,int C) {
	if (r == R&&c == C) {
		return 1;
	}
	if (dp[r][c]) {
		return dp[r][c];
	}
	for (int i = 0; i < 4; i++) {
		int ni = r - di[i];
		int nj = c - dj[i];
		if (ni > R || ni<1 || nj>C || nj < 1) {
			continue;
		}
		if (map[ni][nj] < map[r][c]) {
			dp[r][c] += (dy(ni, nj,R,C));
		}
	}
	return dp[r][c];
}

int main() {
	int m, n;
	cin >> m >> n;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) 
			cin >> map[i][j];
	}
	cout << dy(1, 1,m,n) << endl;
	return 0;
}
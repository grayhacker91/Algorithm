#include<iostream>
#include<algorithm>

using namespace std;

int dp[2][10000];
int wine[10000] = { 0, };

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n;i++) {
		cin >> wine[i];
	}
	dp[0][0] = wine[0];
	dp[0][1] = wine[1];
	dp[1][1] = wine[0] + wine[1];
	int m = max(dp[0][0],dp[1][1]);
	for (int i = 2; i < n;i++) {
		dp[0][i] = wine[i]+max(dp[0][i-2],max(dp[1][i-2], dp[1][i - 3]));
		dp[1][i] = wine[i]+dp[0][i-1];
		m = max(m, max(dp[0][i], dp[1][i]));
	}
	cout << m << endl;
	return 0;
}
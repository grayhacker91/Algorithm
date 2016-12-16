#include<iostream>

using namespace std;

int dp[31];

int main() {
	int n;
	cin >> n;
	dp[0] = 1;
	dp[2] = 3;
	for (int i = 4; i <= n; i+=2) {
		dp[i] = 3 * dp[i - 2];
		for (int j = 4; j <= i;j+=2) {
			dp[i] += 2 * dp[i - j];
		}
	}
	cout << dp[n] << endl;
	return 0;
}
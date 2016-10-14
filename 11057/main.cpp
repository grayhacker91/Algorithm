#include<iostream>

using namespace std;

int dp[1000][10]{ {1,1,1,1,1,1,1,1,1,1}, };

int main() {
	int n;
	cin >> n;
	for (int i = 1; i < n;i++) {
		int s = 0;
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k <= j;k++) {
				dp[i][j] = (dp[i][j]%10007 + dp[i - 1][k] % 10007)%10007;
			}
		}
	}
	int sum = 0;
	for (int i = 0; i < 10;i++) {
		sum += dp[n - 1][i];
		sum %= 10007;
	}
	cout << sum << endl;
	return 0;
}
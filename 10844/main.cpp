#include<iostream>

using namespace std;

long long int dp[100][10] = { {0,1,1,1,1,1,1,1,1,1}, };

int main() {
	int n;
	cin >> n;
	for (int i = 1; i < n;i++) {
		for (int j = 0; j < 10;j++) {
			if (j - 1 < 0) {
				dp[i][j] = dp[i - 1][j + 1]%1000000000;
			}
			else if (j + 1 > 9) {
				dp[i][j] = dp[i - 1][j - 1] % 1000000000;
			}
			else {
				dp[i][j] = (dp[i - 1][j - 1] % 1000000000 + dp[i - 1][j + 1] % 1000000000)%1000000000;
			}
		}
	}
	long long int sum = 0;
	for (int i = 0; i < 10;i++) {
		sum += dp[n - 1][i];
		sum %= 1000000000;
	}
	cout << sum << endl;
	return 0;
}
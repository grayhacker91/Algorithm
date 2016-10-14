#include<iostream>
#include<algorithm>

using namespace std;

int P[1001];
int dp[1001];

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n;i++) {
		cin >> P[i];
	}
	for (int i = 1; i <= n;i++) {
		for (int j = 1; j <= i;j++) {
			dp[i] = max(dp[i],P[j] + dp[i - j]);
		}
	}
	cout << dp[n] << endl;
	return 0;
}
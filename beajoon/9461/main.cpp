#include<iostream>

using namespace std;

long long int dp[101] = {0,1,1,1,2,};

int main() {
	int testcase;
	cin >> testcase;
	for (int i = 0; i < testcase;i++) {
		int n;
		cin >> n;
		for (int i = 5; i <= n;i++) {
			dp[i] = dp[i - 1] + dp[i - 5];
		}
		cout << dp[n] << endl;
	}
	return 0;
}
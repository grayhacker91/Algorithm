#include<iostream>
//http://dyngina.tistory.com/16
using namespace std;
//���1 �ܼ� n^2 �ڵ�
/*
int main() {
	int n;
	cin >> n;
	int A[1000] = { 0, };
	int dp[1000];
	for (int i = 0; i < n;i++) {
		cin >> A[i];
		dp[i] = 1;
	}
	for (int i = 1; i < n;i++) {
		for (int j = 0; j < i;j++) {
			if (A[i]>A[j] && dp[i]<dp[j]+1) {
				dp[i] = dp[j] + 1;
			}
		}
	}
	int max = 0;
	for (int i = 0; i < n;i++) {
		if (dp[i]>max) {
			max = dp[i];
		}
	}
	cout << max << endl;
	return 0;
}
*/
//���2 Lower Bound���(��� �������� �ϱ� ���ؼ��� �迭���� �Űܰ��� ���� �����迭�� ��������)
int main() {
	int n;
	cin >> n;
	int A[1000] = { 0, };
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	int lb[1000] = { 0, };
	int size = 1;
	lb[0] = A[0];
	for (int i = 1; i < n;i++) {
		bool ch = true;
		for (int j = 0; j < size; j++) {
			if (A[i]<=lb[j]) {
				lb[j] = A[i];
				ch = false;
				break;
			}	
		}
		if (ch) {
			lb[size++] = A[i];
		}
	}
	cout << size << endl;
	return 0;
}
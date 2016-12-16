#include<iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	long long int A[90] = { 1,1, };
	for (int i = 2; i < n;i++) {
		A[i] = A[i - 2] + A[i - 1];
	}
	cout << A[n-1] << endl;
	return 0;
}
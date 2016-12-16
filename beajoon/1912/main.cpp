#include<iostream>
#include<algorithm>

using namespace std;

int A[100001];
int D[100001] = { -1001, };

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n;i++) {
		cin >> A[i];
	}
	for (int i = 1; i <= n; i++) {
		D[i] = max(D[i - 1] + A[i],A[i]);
	}
	int m = -1001;
	for (int i = 1; i <= n;i++) {
		m = max(m, D[i]);
	}
	cout << m << endl;
	return 0;
}
#include<iostream>

using namespace std;

int A[10];

int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n;i++) {
		cin >> A[i];
	}
	int cnt = 0, i = n-1;
	while (k!=0) {

		cnt += k / A[i];
		k = k%A[i];
		i--;
	}
	cout << cnt << endl;
	return 0;
}
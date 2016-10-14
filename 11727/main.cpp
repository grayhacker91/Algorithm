#include<iostream>

using namespace std;

int D[1000];

int main() {
	int n;
	cin >> n;
	D[0] = 1;
	D[1] = 3;
	for (int i = 2; i < n;i++) {
		D[i] = (D[i - 1]%10007 + 2 * D[i - 2]%10007)%10007;
	}
	cout << D[n - 1] << endl;
	return 0;
}
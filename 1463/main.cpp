#include<iostream>

using namespace std;

int a[10000001];

int min(int a, int b) {
	if (a>=b) {
		return b;
	}
	else {
		return a;
	}
}

int main() {
	int x;
	cin >> x;
	for (int i = 2; i <= x;i++) {
		a[i] = 10000000;
	}
	a[1] = 0;
	for (int i = 1; i <= x;i++) {
		a[i + 1] = min(a[i+1],a[i] + 1);
		a[i*2] = min(a[i*2], a[i] + 1);
		a[i*3] = min(a[i*3], a[i] + 1);
	}
	cout << a[x] << endl;
	return 0;
}
#include<iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	long long int val1 = 1;
	long long int val2 = 2;
	for (int i = 2; i < n;i++) {
		long long int temp = (val1 % 15746 + val2 % 15746) % 15746;
		val1 = val2;
		val2 = temp;
	}
	cout << val2 << endl;
	return 0;
}
#include<iostream>

using namespace std;

int number[1001];

int main() {
	int n;
	cin >> n;
	int max = 0;
	for (int i = 1; i <= n;i++) {
		int a;
		cin >> a;
		if (a>max) {
			max = a;
		}
		number[a]++;
	}
	for (int i = 2; i*i <= max;i++) {
		for (int j = i*2; j <= max;j+=i) {
			if (number[j]!=0){
				number[j] = 0;
			}
		}
	}
	int result = 0;
	for (int i = 2; i <= max;i++) {
		result += number[i];
	}
	cout << result << endl;
	return 0;
}
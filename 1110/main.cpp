#include<iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	int cnt = 0;
	int newNumber = n;
	while(true){
		int q = newNumber / 10;
		int r = newNumber % 10;
		newNumber = (q + r) % 10 + r * 10;
		cnt++;
		if (newNumber == n) {
			break;
		}
	}
	cout << cnt << endl;
	return 0;
}
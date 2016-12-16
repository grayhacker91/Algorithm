#include<iostream>

using namespace std;

int child[201];
int lis[201];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n;i++) {
		cin >> child[i];
	}
	int size = 1;
	lis[0] = child[0];
	for (int i = 1; i < n;i++) {
		bool flag = true;
		for (int j = 0; j < size; j++) {
			if (child[i]<lis[j]) {
				lis[j] = child[i];
				flag = false;
				break;
			}
		}
		if (flag) {
			lis[size++] = child[i];
		}
	}
	cout << n - size << endl;
	return 0;
}
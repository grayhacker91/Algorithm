#include<iostream>

using namespace std;

int arr[50];
int tmp[50];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i<n; i++) {
		cin >> arr[i];
		for (int j = 0; j<i; j++) {
			if (arr[j] > arr[i]) {
				tmp[j]++;
			}
			else if (arr[j] <= arr[i]) {
				tmp[i]++;
			}
		}
	}
	for (int i = 0; i<n; i++) {
		cout << tmp[i] << " ";
	}
	return 0;
}
#include<iostream>
#define MAX 10
using namespace std;

int result[MAX];    //��� ��
int numCount[10];   //�� �ڸ����� ��
int val[11];    //�� �ڸ����� 10^(n-1) ��(0�� �迭�� ����)

int main() {
	int n;
	cin >> n;
	int cnt = 0;
	bool isNine = true;
	for (int i = n; ; i = i / 10) {
		int temp = i % 10;
		if (i == 0 && temp == 0) {
			break;
		}

		int res = 1;
		for (int j = 0; j < cnt; j++) {
			res *= 10;
		}
		val[cnt + 1] = res;

		numCount[cnt] = temp;
		cnt++;
	}

	bool isup = true;
	if (numCount[cnt - 2]<5) {
		numCount[cnt - 1] = numCount[cnt - 1] - 1;
		isup = false;
	}
	for (int i = 0; i < cnt - 1; i++) {
		numCount[i] = 9;
	}

	//�� �ڸ��� ���
	for (int i = 0; i < cnt; i++) {
		int calc = numCount[i] * i*val[i];
		for (int j = 0; j < MAX; j++) {
			if (j == 0 || j > numCount[i]) {
				result[j] += calc;
			}
			else {
				result[j] += calc + val[i + 1];
			}
		}
	}

	if (!isup) {
		for (int i = (numCount[cnt - 1] + 1) * val[cnt]; i <= n; i++) {
			for (int j = i; ; j = j / 10) {
				int temp = j % 10;
				if (j == 0 && temp == 0) {
					break;
				}
				result[temp]++;
			}
		}
	}
	else {
		for (int i = (numCount[cnt - 1] + 1) * val[cnt] - 1; i > n; i--) {
			for (int j = i; ; j = j / 10) {
				int temp = j % 10;
				if (j == 0 && temp == 0) {
					break;
				}
				result[temp]--;
			}
		}
	}

	for (int i = 0; i < MAX; i++) {
		cout << result[i] << " ";
	}
	return 0;
}
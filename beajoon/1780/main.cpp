#include<iostream>

using namespace std;

int map[3000][3000];
int cnt[3];

void paper(int x,int y,int size) {
	int current = map[x][y];
	bool flag = true;
	for (int i = x; i < x + size && flag;i++) {
		for (int j = y; j < y + size && flag;j++) {
			if (current!=map[i][j]) {
				flag = false;
			}
		}
	}
	if (flag) {
		cnt[current + 1]++;
	}
	else {
		paper(x, y, size / 3);
		paper(x, y + size / 3, size / 3);
		paper(x, y + (size / 3)*2, size / 3);
		paper(x + size / 3, y, size / 3);
		paper(x + size / 3, y + size / 3, size / 3);
		paper(x + size / 3, y + (size / 3) * 2, size / 3);
		paper(x + (size / 3)*2, y, size / 3);
		paper(x + (size / 3) * 2, y + size / 3, size / 3);
		paper(x + (size / 3) * 2, y + (size / 3) * 2, size / 3);
	}
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n;i++) {
		for (int j = 0; j < n;j++) {
			cin >> map[i][j];
		}
	}
	paper(0, 0, n);
	for (int i = 0; i < 3;i++) {
		cout << cnt[i] << endl;
	}
	return 0;
}
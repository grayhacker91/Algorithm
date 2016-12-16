#include<iostream>
#include<string>

using namespace std;

int map[64][64];
string str;

void quadTree(int x, int y, int size) {
	int current = map[x][y];
	bool ch = true;
	for (int i = x; i < x + size && ch;i++) {
		for (int j = y; j < y + size && ch; j++) {
			if (current!=map[i][j]) {
				ch = false;
			}
		}
	}
	if (ch) {
		str += current + 48;
	}
	else {
		str += "(";
		quadTree(x, y, size / 2);
		quadTree(x, y + size / 2, size / 2);
		quadTree(x + size / 2, y, size / 2);
		quadTree(x + size / 2, y + size / 2, size / 2);
		str += ")";
	}
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n;i++) {
		string temp;
		cin >> temp;
		for (int j = 0; j < n;j++) {
			map[i][j] = temp.at(j)-48;
		}
	}
	quadTree(0,0,n);
	cout << str << endl;
	return 0;
}
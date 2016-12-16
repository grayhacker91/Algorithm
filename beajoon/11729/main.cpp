#include<iostream>
#include<vector>

using namespace std;

int cnt = 0;
vector<pair<int, int>> v;

void move(int from, int to) {
	cnt++;
	v.push_back(make_pair(from, to));
}

void hanoi(int n, int from, int by, int to) {
	if (n==1) {
		move(from, to);
	}
	else {
		hanoi(n - 1, from, to, by);
		move(from, to);
		hanoi(n - 1, by, from, to);
	}
}

int main() {
	int n;
	cin >> n;
	hanoi(n, 1, 2, 3);
	cout << cnt << endl;
	for (int i = 0; i < v.size();i++) {
		printf("%d %d\n", v[i].first, v[i].second);
	}
	return 0;
}
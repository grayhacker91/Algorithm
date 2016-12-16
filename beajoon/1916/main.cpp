#include<iostream>
#define INFINIT 100000000
using namespace std;

int path[1000][1000];
int visited[1000];
int dist[1000];

int min(int a, int b) {
	if (a >= b) {
		return b;
	}
	else {
		return a;
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			path[i][j] = INFINIT;
		}
	}
	for (int i = 0; i < n; i++) {
		dist[i] = INFINIT;
	}
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		path[a - 1][b - 1] = min(path[a - 1][b - 1], c);
	}
	int start, dest;
	cin >> start >> dest;
	dist[start - 1] = 0;
	for (int i = start - 1; ; ) {
		visited[i] = 1;
		for (int j = 0; j < n; j++) {
			if (path[i][j] != INFINIT) {
				dist[j] = min(dist[j], dist[i] + path[i][j]);
			}
		}
		int k = INFINIT;
		for (int j = 0; j < n; j++) {
			if (visited[j] == 0 && k>dist[j]) {
				k = dist[j];
				i = j;
			}
		}
		if (k == INFINIT) {
			break;
		}
	}
	cout << dist[dest - 1] << endl;
	return 0;
}
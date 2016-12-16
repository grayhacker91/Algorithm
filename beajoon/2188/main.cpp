#include<iostream>
#include<queue>

using namespace std;

int map[410][410];

bool bfs(int start,int end) {
	queue<int> q;
	int visited[410] = { 0, };
	int parent[410] = { 0, };

	q.push(start);
	parent[start] = 0;
	bool check=false;
	while (!q.empty()) {
		int vertex = q.front();
		visited[vertex] = 1;
		q.pop();
		if (end==vertex) {
			check = true;
			for (int i = end; i != parent[i]; i = parent[i]) {
				map[parent[i]][i] = 0;
				map[i][parent[i]] = 1;
			}
			break;
		}
		for (int i = 0; i <= end;i++) {
			if (map[vertex][i] != 0  && visited[i]==0) {
				q.push(i);
				parent[i] = vertex;
			}
		}
	}
	return check;
}

int fordfulkerson(int start, int end) {
	bool b = true;
	int result = 0;
	while (b) {
		b = bfs(start, end);
		if (b) {
			result++;
		}
	}
	return result;
}

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		map[0][i] = 1;
		map[i+n][n + m + 1] = 1;
	}
	for (int i = 1; i <= n;i++) {
		int cnt;
		cin >> cnt;
		for (int j = 0; j < cnt;j++) {
			int tmp;
			cin >> tmp;
			map[i][tmp+n] = 1;
		}
	}
	cout << fordfulkerson(0, n + m + 1) << endl;
	return 0;
}
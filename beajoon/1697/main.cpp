#include<iostream>
#include<queue>

using namespace std;

int move(int i, int d) {
	switch (i) {
	case 0:
		return d * 2;
	case 1:
		return d - 1;
	case 2:
		return d + 1;
	}
}

int bfs(int s,int e) {
	if (s==e) {
		return 0;
	}
	queue<int> q;
	bool visited[100001] = { false, };
	int parent[100001] = { 0, };

	q.push(s);
	visited[s] = true;
	parent[s] = s;
	bool flag = true;
	while (!q.empty() && flag) {
		int next = q.front();
		q.pop();
		for (int i = 0; i < 3 && flag;i++) {
			int d = move(i, next);
			if (d >= 0 && d <= 100000 && !visited[d]) {
				q.push(d);
				visited[d] = true;
				parent[d] = next;
				if (d == e) {
					flag = false;
				}
			}
		}
	}
	int cnt = 1;
	for (int i = parent[e]; i != parent[s];i=parent[i]) {
		cnt++;
	}
	return cnt;
}

int main() {
	int start, end;
	cin >> start >> end;
	cout << bfs(start, end) << endl;
	return 0;
}
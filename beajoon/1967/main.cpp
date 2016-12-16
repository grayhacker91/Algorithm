#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<utility>

using namespace std;

vector<vector<pair<int, int>>> tree;

int leafNode[10001] = { 1, };
int parent[10001];
int maxValue = 0;

void bfs(int start) {
	//bfs실시
	queue<int> q;
	bool visited[10001] = { 0, };
	fill(parent, parent + 10001, 0);
	q.push(start);
	parent[start] = start;
	visited[start] = true;
	for (int j = start; ; ) {
		for (vector<pair<int, int>>::iterator it = tree[j].begin(); it != tree[j].end(); it++) {
			if (!visited[(*it).first]) {
				q.push((*it).first);
				visited[(*it).first] = true;
				parent[(*it).first] = j;
			}
		}
		q.pop();
		if (!q.empty()) {
			j = q.front();
		}
		else {
			break;
		}
	}
}

int calcWeight(int cnt) {
	//가중치 계산
	int edge = 1;
	for (int j = 1; j <= cnt; j++) {
		if (leafNode[j] == 0) {
			int weight = 0;
			for (int k = j; parent[k] != k; k = parent[k]) {
				int w = 0;
				for (vector<pair<int, int>>::iterator it = tree[k].begin(); it != tree[k].end(); it++) {
					if (parent[k] == (*it).first) {
						w = (*it).second;
						break;
					}
				}
				weight += w;
			}
			if (maxValue <= weight) {
				edge = j;
				maxValue = weight;
			}
		}
	}
	return edge;
}

int main() {
	int cnt;
	cin >> cnt;
	tree.resize(cnt + 1, vector<pair<int, int>>());
	for (int i = 0; i < cnt-1;i++) {
		int a, b, c;
		cin >> a >> b >> c;
		tree[a].push_back(make_pair(b, c));
		tree[b].push_back(make_pair(a, c));
		leafNode[a] = 1;
	}
	bfs(1);
	int e = calcWeight(cnt);
	bfs(e);
	e = calcWeight(cnt);
	cout << maxValue << endl;
	return 0;
}
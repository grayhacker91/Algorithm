#include<iostream>
#include<algorithm>

using namespace std;

int A[301][301];

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n;i++) {
		for (int j = 1; j <= m;j++) {
			cin >> A[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			A[i][j] = A[i][j] + A[i - 1][j] + A[i][j - 1] - A[i - 1][j - 1];
		}
	}
	int k;
	cin >> k;
	for (int i = 0; i < k;i++) {
		int a, b, x, y;
		cin >> a >> b >> x >> y;
		cout << A[x][y]-(A[x][b-1]+A[a-1][y])+A[min(x,a-1)][min(y,b-1)]<< endl;
	}
	return 0;
}
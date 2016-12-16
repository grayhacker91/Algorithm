#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int p[1000];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n;i++) {
		cin >> p[i];
	}
	vector<int> v(p, p + n);
	sort(v.begin(), v.end());
	int result = 0;
	vector<int>::iterator it = v.begin();
	for (int i = v.size(); i > 0;i--) {
		result = result + (*it)*i;
		it++;
	}
	cout << result << endl;
	return 0;
}
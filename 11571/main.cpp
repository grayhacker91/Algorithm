#include<stdio.h>
#include<string>

using namespace std;

int main() {
	int testcase;
	scanf_s("%d", &testcase);
	for (int i = 0; i < testcase;i++) {
		int a, b;
		scanf_s("%d %d", &a, &b);
		int visited[1025];
		char temp[6];
		fill(visited, visited + 1025, -1);
		string result = "";
		int mok = a / b;
		int r = a%b;
		sprintf_s(temp, "%d", mok);
		result.append(temp);
		result.push_back('.');
		int position = result.size();
		while (true) {
			mok = r * 10 / b;
			r = r * 10 % b;
			sprintf_s(temp, "%d", mok);
			if (visited[r]<0) {
				visited[r] = position;
				if (r==0 && mok>0) {
					result.append(temp);
					result.append("(0)");
					break;
				}
				else if(r == 0 && mok==0){
					result.append("(0)");
					break;
				}
				else {
					result.push_back(temp[0]);
					//result.append(temp);
				}
			}
			else {
				if (result[visited[r]]==mok+48) {
					result.insert(visited[r], "(");
					result.push_back(')');
					break;
				}
				result.push_back(temp[0]);
				//result.append(temp);
			}
			position++;
		}
		printf("%s\n", result.c_str());
	}
	return 0;
}
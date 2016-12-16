#include<iostream>
#include<stack>
 
using namespace std;
 
int N[1100];
int sort[1100];
 
int select(int *a,int size) {
    for (int i = 1; i <= size;i++) {
        if (a[i]==0) {
            a[i]--;
            return i;
        }
    }
}
 
int search(int *a,int size,int *visited) {
    for (int i = 1; i <= size;i++) {
        if (a[i]==1 && visited[i]==0) {
            return i;
        }
    }
    return -1;
}
 
int max(int (*a)[1100],int p,int size, int *time) {
    int m = 0;
    for (int i = 1; i <= size;i++) {
        if (a[i][p] == 1) {
            int temp = time[i];
            if (temp >= m) {
                m = temp;
            }
        }
    }
    return m;
}
 
int main(){
    int testcase;
    cin >> testcase;
    for (int i = 0; i < testcase;i++) {
        int n, k;
        cin >> n >> k;
 
        int time[1100] = { 0, };
        int visited[1100] = { 0, };
        int graph[1100][1100] = { 0, };
        int edge[1100] = { 0, };
 
        for (int j = 1; j <= n;j++) {
            cin >> N[j];
        }
        int x, y;
        for (int j=0; j < k;j++) {
            cin >> x >> y;
            graph[x][y] = 1;
            edge[y]++;
        }
 
        stack<int> s;
        int count = 0;
        for (int j = select(edge, n);  ; ) {
            if (visited[j]==0) {
                s.push(j);
                visited[j] = 1;
            }
            int k = search(graph[j], n,visited);
            if (k==-1) {
                sort[count++] = j;
                s.pop();
                if (s.size() == 0) {
                    if (count==n) {
                        break;
                    }
                    else {
                        j = select(edge, n);
                        continue;
                    }
                }
                j = s.top();
            }
            else {
                j = k;
            }
        }
 
        for (int j = count-1; j >= 0;j--) {
            time[sort[j]] = N[sort[j]] + max(graph, sort[j], n, time);
        }
             
        int w;
        cin >> w;
        cout << time[w] << endl;
    }
    return 0;
}
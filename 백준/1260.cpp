#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <queue>
#include <cstring>
using namespace std;

#define pb push_back

vector<vector<int> > v(1005);
int check[1005];

void dfs(int vtx){
    check[vtx] = 1;
    printf("%d ",vtx);

    for(int i=0; i<v[vtx].size(); i++){
        int next = v[vtx][i];
        if(!check[next]) dfs(next);
    }
}

void bfs(int start){
    queue<int> q;
    memset(check,0,sizeof(check));
    //fill(check,check+1005,0);

    q.push(start);
    check[start] = 1;

    while(!q.empty()){
        int vtx = q.front();
        q.pop();

        printf("%d ",vtx);

        for(int i=0; i<v[vtx].size(); i++){
            int next = v[vtx][i];
            if(!check[next]){
                q.push(next);
                check[next] = 1;
            }
        }
    }
}

int main(){
    int n, m, start;
    cin >> n >> m >> start;

    for(int i=0; i<m; i++){
        int a, b;
        scanf("%d%d",&a,&b);

        v[a].pb(b);
        v[b].pb(a);
    }

    for(int i=1; i<=n; i++){
        sort(v[i].begin(), v[i].end());
    }

    dfs(start);
    printf("\n");
    bfs(start);
}

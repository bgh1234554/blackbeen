#include <iostream>
#include <stdio.h>
#include <queue>
#include <utility>
using namespace std;

int visit[505][505],dist[505][505], n, m, arr[505][505];

bool safe(int y, int x){
    return y >= 1 && y <= n && x >= 1 && x <= m;
}

int bfs(int y, int x){
    queue<pair<int,int> > q;
    q.push(make_pair(y,x));
    visit[y][x] = 1;
    dist[y][x] = 1;

    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        if(y == n && x == m) return dist[y][x];

        int d[4][2] ={{1,0},{0,1},{-1,0},{0,-1}};
        for(int i=0; i<4; i++){
            int ny = y + d[i][0];
            int nx = x + d[i][1];
            if(safe(ny,nx) && arr[ny][nx] == 1 && !visit[ny][nx]){
                q.push(make_pair(ny,nx));
                visit[ny][nx] = 1;
                dist[ny][nx] = dist[y][x] + 1;
            }
        }
    }
}


int main(){
    cin >> n >> m;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            scanf("%1d",&arr[i][j]);
        }
    }

    cout << bfs(1,1);
}

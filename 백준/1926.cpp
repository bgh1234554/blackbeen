#include <iostream>
#include <stdio.h>
using namespace std;

int visit[505][505], n, m, arr[505][505], vc;

bool safe(int y, int x){
    return y >= 1 && y <= n && x >= 1 && x <= m;
}

void dfs(int y, int x){
    visit[y][x] = 1;
    vc++;

    int d[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
    for(int i=0; i<4; i++){
        int ny = y + d[i][0];
        int nx = x + d[i][1];
        if(safe(ny,nx) && arr[ny][nx] == 1 && !visit[ny][nx])
            dfs(ny,nx);
    }
}


int main(){
    cin >> n >> m;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            scanf("%d",&arr[i][j]);
        }
    }

    int cnt = 0, ans = 0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(arr[i][j] == 1 && !visit[i][j]){
                vc = 0;
                dfs(i,j);
                cnt++;
                ans = max(ans, vc);
            }
        }
    }

    cout << cnt << '\n' << ans;
}

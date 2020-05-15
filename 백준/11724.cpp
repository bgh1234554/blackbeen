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
    for(int i=0; i<v[vtx].size(); i++){
        int next = v[vtx][i];
        if(!check[next]) dfs(next);
    }
}

int main(){
	int n,m;
	cin >> n >> m;
	
    for(int i=0; i<m; i++){
        int a, b;
        scanf("%d%d",&a,&b);

        v[a].pb(b);
        v[b].pb(a);
    }
    int ans = 0;
	for(int i=1;i<=n;i++){
		if(!check[i]){
			ans++;
			dfs(i);
		}
	}
	cout << ans;	
}

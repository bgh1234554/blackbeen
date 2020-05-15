#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int visit[27][27], N, arr[27][27], area[27], size;

bool safe(int y, int x){
    return y >= 1 && y <= N && x >= 1 && x <= N;
}

void dfs(int y, int x){
    visit[y][x] = 1;
    size++;
    int d[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
    for(int i=0; i<4; i++){
        int ny = y + d[i][0];
        int nx = x + d[i][1];
        if(safe(ny,nx) && arr[ny][nx] == 1 && !visit[ny][nx])
            dfs(ny,nx);
    }
    
}

vector<int> v;

int main(){
	cin >> N;
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			scanf("%1d", &arr[i][j]);
		}
	}
	
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			if(!visit[i][j] && arr[i][j]==1){
				dfs(i,j);
				v.push_back(size);
				size=0;
			}
		}
	}
	
	cout << v.size() << "\n";
	sort(v.begin(),v.end());
	for(int i=0;i<v.size();i++){
		cout << v[i] << "\n";
	}
}

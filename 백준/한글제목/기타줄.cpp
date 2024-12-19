#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

vector <int> pack;
vector <int> each;

int main(){
	int n,m; cin >> n >> m;
	for(int i=0;i<m;i++){
		int tmp1,tmp2; scanf("%d%d",&tmp1,&tmp2);
		pack.push_back(tmp1); each.push_back(tmp2);
	}
	sort(pack.begin(),pack.end()); sort(each.begin(),each.end());
	printf("%d\n",min((n/6)*pack[0]+(n-(n/6)*pack[0])*each[0],min(n*each[0],((n/6)+1)*pack[0])));
}

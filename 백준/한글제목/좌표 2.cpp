#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector < pair<int,int> > v;

int main(){
	int n; cin >> n;
	for(int i=0;i<n;i++){
		int x,y;
		cin >> x >> y;
		v.push_back(make_pair(y,x));
	}
	sort(v.begin(), v.end());
	for(int j=0; j<v.size(); j++){
	//	cout << v[i].first << ' ' << v.second << '\n';
	printf("%d %d\n", v[j].second, v[j].first);
	}
}

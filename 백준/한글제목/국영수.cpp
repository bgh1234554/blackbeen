#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	int N;
	cin >> N;
	vector<pair< pair<int,int>,pair<int,string> > > v;
	pair<int,int> p;
	pair<int,string> q;
	for(int i=0;i<N;i++){
		int kor,eng,math;
		string name;
		cin >> name >> kor >> eng >> math;
		p = make_pair(kor,eng);
		q = make_pair(math,name);
		v.push_back(make_pair(p,q));
	}
	for(int i=0;i<N;i++){
		v[i].first.first *= -1;
		v[i].second.first *= -1;
	}	
	sort(v.begin(),v.end());
	for(int i=0;i<N;i++){
		cout << v[i].second.second << "\n";
	}
}

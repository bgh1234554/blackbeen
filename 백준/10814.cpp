#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

int main(){
	int N;
	vector< pair<pair<int,int>,string> > v;
	int age;
	string name;
	cin >> N;
	int count = 1;
	while(N--){
		cin >> age >> name;
		v.push_back(make_pair(make_pair(age,count),name));
		count += 1;
	}
	sort(v.begin(),v.end());
	for(int i=0;i<v.size();i++){
		cout << v[i].first.first << " " << v[i].second << "\n";
	}
}

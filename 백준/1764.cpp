//5397¹ø
#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	int N,M;
	vector<string> d,db;
	cin >> N >> M;
	int X = N+M;
	while(X--){
		string name;
		cin >> name;
		d.push_back(name);
	}
	sort(d.begin(),d.end());
	int count = 0;
	for(int i=0;i<d.size()-1;i++){
		if(d[i]==d[i+1]){
			count+=1;
			db.push_back(d[i]);
		}
	}
	cout << count << "\n";
	for(int i=0;i<db.size();i++){
		cout << db[i] << "\n";
	}
}

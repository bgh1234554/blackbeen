#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
	string w;
	vector<string> v;
	cin >> w;
	int count=1;
	for(int i=0;i<w.size();i++){
		string s = w.substr(i,w.size()-i);
		v.push_back(s);
	}
	sort(v.begin(),v.end());
	for(int i=0;i<v.size();i++){
		cout << v[i] << "\n";
	}
} 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool compare(string x, string y){
	if(x.size() != y.size()){
		return x.size() < y.size();
	}
	else{
		int sumx = 0;
		int sumy = 0;
		for(int i=0;i<x.size();i++){
			if('0'<=x[i]&&x[i]<='9') sumx+=x[i]-'0';
			if('0'<=y[i]&&y[i]<='9') sumy+=y[i]-'0';			
		}
		if(sumx!=sumy) return sumx < sumy;
		else{
			return x < y;
		}
	}
}

int main(){
	vector< string > v;
	int N; cin >> N;
	for(int i=0;i<N;i++){
		string name;		
		cin >> name;
		v.push_back(name);
	}
	sort(v.begin(),v.end(),compare);
	for(int j=0;j<N;j++){
		cout << v[j] << "\n";
	}
} 

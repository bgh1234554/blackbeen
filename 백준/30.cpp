#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main(){
	string str; cin >> str;
	sort(str.begin(),str.end());
	int sum = 0;
	for(int i=1;i<str.size();i++){
		sum+=str[i]-'0';
	}
	if(str[0]!='0' || sum%3!=0){
		printf("-1\n");
	}
	else{
		for(int i=str.size()-1;i>=0;i--){
			cout<<str[i];
		}
	}
}

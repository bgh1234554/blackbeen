#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

stack <char> st;

int main(){
	int T; cin >> T;
	while(T--){
		int cnt = 0;
		string inp;
		cin >> inp;
		for(int i=0;i<inp.size();i++){
			if(inp[i]=='('||st.empty()) st.push(inp[i]);
			else if(st.top()=='(') st.pop();
		}
		if(st.empty()){
			printf("YES\n");
		}
		else{
			printf("NO\n");
		}
		while(!st.empty()) st.pop();
	}
} 

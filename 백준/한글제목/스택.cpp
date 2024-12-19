#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

stack <int> st;
	
int main(){
	int n; cin >> n;
	while(n--){
		string cmd; cin >> cmd;
		if(cmd == "push"){
			int inp; cin >> inp;
			st.push(inp);
		}
		else if(cmd == "pop"){
			if(st.empty()){
				cout << "-1\n";
			}
			else{
				cout << st.top() << "\n";
				st.pop();
			}
		}
		else if(cmd == "size"){
			cout << st.size() << "\n";
		}
		else if(cmd == "empty"){
			cout << st.empty() << "\n";
		}
		else if(cmd == "top"){
			if(st.empty()){
				cout << "-1\n";
			}
			else{
				cout << st.top() << "\n";
			}			
		}								
	}
}

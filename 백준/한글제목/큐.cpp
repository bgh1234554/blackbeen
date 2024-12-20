#include <iostream>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

queue <int> q;
	
int main(){
	int n; cin >> n;
	while(n--){
		string cmd; cin >> cmd;
		if(cmd == "push"){
			int inp; cin >> inp;
			q.push(inp);
		}
		else if(cmd == "pop"){
			if(q.empty()){
				cout << "-1\n";
			}
			else{
				cout << q.front() << "\n";
				q.pop();
			}
		}
		else if(cmd == "size"){
			cout << q.size() << "\n";
		}
		else if(cmd == "empty"){
			cout << q.empty() << "\n";
		}
		else if(cmd == "front"){
			if(q.empty()){
				cout << "-1\n";
			}
			else{
				cout << q.front() << "\n";
			}			
		}
		else if(cmd == "back"){
			if(q.empty()){
				cout << "-1\n";
			}
			else{
				cout << q.back() << "\n";
			}			
		}								
	}
}

#include <iostream>
#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main(){
	queue<int> q;
	int N;
	cin >> N;
	while(true){
		int x;
		cin >> x;
		if(x==-1){
			break;
		}
		if(x==0){
			q.pop();
		}
		else{
			if(q.size()<N){
				q.push(x);
			}
		}	
	}
	while(!q.empty()){
		cout << q.front();
		q.pop();
		printf("\n");
	}
}

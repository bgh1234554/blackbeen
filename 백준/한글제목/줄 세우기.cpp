#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	char names[21][13] = {};
	char copied[21][13] = {};
	for(int i=0;i<n;i++){
		scanf("%s", names[i]);
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<13;j++){
		copied[i][j] = names[i][j];
		}
	}
	sort(copied,copied+n);
	int dec = 0;
	int inc = 0;
	for(int i=0;i<n;i++){
		if(names[i] == copied[i]){
			inc += 1;
		}
		else if(names[i] == copied[n-i]){
			dec += 1;
		}
	}
	if(inc == n){
		printf("INCREASING");
	}
	else if(dec == n){
		printf("DECREASING");
	}
	else{
		printf("NEITHER");
	}
}

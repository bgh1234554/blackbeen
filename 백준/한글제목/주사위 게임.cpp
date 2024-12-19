#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int a,b,c;
	int big = 0;
	int x;
	int n;
	scanf("%d", &n);	
	for(int i=0;i<n;i++){
	scanf("%d", &a);
	scanf("%d", &b);
	scanf("%d", &c);
	if(a == b && b == c){
		x = 10000+a*1000;
		}
	else if(a == b){
		x = 1000 + a*100;
		}
	else if(b == c){
		x = 1000 + b*100;
		}
	else if(a == c){
		x = 1000 + c*100;
		}
	else{
		x = max(a,max(b,c))*100;
		}
	if(x>=big){
		big = x;
		}			
	}
	printf("%d", big);
}

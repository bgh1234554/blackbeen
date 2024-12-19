#include<stdio.h>

int main(){
	int count = 0;
	int n;
	int x = 1; 
	scanf("%d", &n);
	while(3>2){
		if(n==0){
			break;
		}
		else{
			if(n<x){
				x = 1;
			}
			else{
				n -= x;
				count += 1;
				x += 1;
			}
		}
	}
	printf("%d", count);
}

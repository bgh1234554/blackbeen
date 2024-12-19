#include <stdio.h>

int main(){
	int x;
	int stick = 0;
	int count = 0;
	scanf("%d", &x);
	for(int i=64;i>0;i/=2){
		if(i>x){
			continue;
		}
		else if(i==x){
			stick += 1;
			break;
		}
		if(count + i<=x){
			count += i;
			stick += 1;
		}
	}
	printf("%d", stick);
}

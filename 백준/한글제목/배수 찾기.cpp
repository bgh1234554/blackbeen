#include <stdio.h>

int main(){
	int n;
	scanf("%d",&n);
	int p;
	while(true){
		scanf("%d",&p);
		if(p==0){
			break;
		}
		if(p%n==0){
			printf("%d is a multiple of %d.\n",p,n);
		}
		else{
			printf("%d is NOT a multiple of %d.\n",p,n);
		}
	}
}

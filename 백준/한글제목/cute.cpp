#include <stdio.h>

int main(){
	int a; /*몇명인지*/ 
	int b=0; /*not  cute*/
	int c=0;
	int d;
	scanf("%d", &a);
	for(int i = 0; i<a; i++){
		scanf("%d",&d);
		if (d==0){
			b=b+1;
		}
		else if (d==1){
			c=c+1;
		}
	}
	if (b>c){
		printf("Junhee is not cute!");
	}
	else if (b<c){
		printf("Junhee is cute!");
	}
}

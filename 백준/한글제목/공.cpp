#include <stdio.h>

int main(){
	int n;
	scanf("%d", &n);
	int x,y;
	int ball = 1;
	for(int i=0;i<n;i++){
		scanf("%d", &x);
		scanf("%d", &y);
		if(x == ball && y !=ball){
			ball = y;
		}
		else if(y == ball && x !=ball){
			ball = x;
		}
	}
	printf("%d",ball);
}

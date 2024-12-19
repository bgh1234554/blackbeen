#include <stdio.h>

int main(){
	int counta = 1;
	int countb = 0;
	int a = 1;
	int b = 0;
	int k;
	scanf("%d", &k);
	for(int i=0;i<k;i++){
		counta -= a;
		countb += a;
		counta += b;
		a = counta;
		b = countb;
	}
	printf("%d %d",counta,countb);
} 

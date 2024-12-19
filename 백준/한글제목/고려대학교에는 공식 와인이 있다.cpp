#include <stdio.h>

int main(){
	int c,k,p;
	int count =0;
	scanf("%d",&c);
	scanf("%d",&k);
	scanf("%d",&p);
	for(int i=1;i<=c;i++){
		count += k*i+p*i*i;
	}
	printf("%d",count);
}

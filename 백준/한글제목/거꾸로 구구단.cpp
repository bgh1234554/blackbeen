#include <stdio.h>
#include <cstdlib>
#include <string.h>

int main(){
	char num[8] = {};
	char clone[8] = {};
	int max = 0; 
	int n,k;
	int x,y;
	scanf("%d %d",&n,&k);
	for(int i=1;i<=k;i++){
		x = n*i;
		sprintf(num,"%d",x);
		for(int j=0;j<strlen(num);j++){
			clone[j] = num[strlen(num)-j-1];
		}
		y = atoi(clone);
		if(y>max){
			max=y;
		}
	}
	printf("%d", max);
}

#include <stdio.h>

int main(){
	int a[6][5] = {};
	int max=0;
	int count=0;
	int n;
	for(int i=0;i<5;i++){
		for(int j=0;j<4;j++){
			scanf("%d", &a[i][j]);
			count += a[i][j];
		}
		if(count>max){
			max = count;
			n = i+1;
		}
		count = 0;
	}
	printf("%d %d",n,max);
}

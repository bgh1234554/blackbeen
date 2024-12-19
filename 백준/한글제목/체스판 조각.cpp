#include <stdio.h>

int main(){
	int n;
	scanf("%d", &n);
	int j,x;
	int max = 0;
	for(int i=1;i<n;i++){
		j=n-i;
		x=(i+1)*(j+1);
		if(x>max){
			max = x;
		}
	}
	printf("%d",max);
}

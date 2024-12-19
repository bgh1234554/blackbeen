#include <stdio.h>

int main(){
	int n;
	scanf("%d", &n);
	int b[101] = {};	
	for(int i=0;i<n;i++){
		scanf("%d", &b[i]);
	}
	int a[101] = {};
	a[0] = b[0];
	int count = a[0];
	for(int j=1;j<n;j++){
			a[j] = b[j]*(j+1)-count;
			count += a[j];
	}
	for(int k=0;k<n;k++){
		printf("%d ",a[k]);
	} 
}

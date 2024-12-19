#include <stdio.h>

int main(){
	int n,m;
	int bag[101] = {};
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		bag[i] = i+1;
	}
	scanf("%d", &m);
	int i,j,k;
	for(int j=0;j<m;j++){
		scanf("%d %d %d", &i,&j,&k);
	}
} 

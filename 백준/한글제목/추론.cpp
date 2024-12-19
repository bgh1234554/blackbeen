#include<stdio.h>

int main(){
	int n;
	scanf("%d", &n);
	int arr[51] = {};
	for(int i=0; i<n; i++){
		scanf("%d", &arr[i]);
	}
	if(arr[2]-arr[1] == arr[1] - arr[0]){
		int d = arr[1] - arr[0];
		int y = arr[n-1] + d;
		printf("%d", y);
	}
	else{
		int r = arr[1]/arr[0];
		int x = arr[n-1]*r;
		printf("%d", x);
	}
}

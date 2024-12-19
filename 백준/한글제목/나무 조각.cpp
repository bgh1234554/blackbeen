#include <stdio.h>

int main(){
	int a[6] = {};
	int t;
	for(int k=0;k<5;k++){
		scanf("%d", &a[k]);
	}
	while(true){
		if(a[0]==1 && a[1]==2 && a[2]==3 && a[3]==4 && a[4]==5){
			break;
		}
		else{
		for(int i=0;i<4;i++){
		if(a[i]>a[i+1]){
			t = a[i];
			a[i] = a[i+1];
			a[i+1] = t;
		for(int j=0;j<5;j++){
			printf("%d ", a[j]);
		}
		printf("\n");
			}	
		}
	}
}
}

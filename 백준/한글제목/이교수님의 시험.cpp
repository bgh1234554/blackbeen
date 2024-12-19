#include <stdio.h>
#include <string.h>

int main(){
	int n;
	scanf("%d", &n);
	int a[101][11] = {};
	int b[101] = {};
	for(int j=0; j<100;j++){
		b[j] = 0; 
	}
	for(int i=0; i<n;i++){
		for(int k=0; k<10;k++){
			scanf("%d", &a[i][k]);
		}
	}
	for(int m=0; m<101;m++){
		if(a[m][0] == 1 && a[m][1] == 2 && a[m][2] == 3 && a[m][3] == 4 && a[m][4] == 5 && a[m][5] == 1 && a[m][6] == 2 && a[m][7] == 3 && a[m][8] == 4 && a[m][9] == 5){
			b[m+1] = 1;
		}
	}
	for(int x=0; x<101; x++){
		if(b[x] == 1){
			printf("%d\n",x);
		}
	}
}

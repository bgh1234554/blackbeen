#include <stdio.h>

int main(){
	int a[10][10] = {};
	int big = 1;
	int h = 0;
	int y = 0;
	for(int i=0; i<9; i++){
		for(int j=0; j<9; j++){
			scanf("%d", &a[i]);
		}
	}
	for(int k=0; k<9; k++){
		for(int m=0; m<9; m++){
			if(a[k][m] > big){
				big = a[k][m];
				h = k+1;
				y = m+1;
			}
		}
	}
	printf("%d\n", big);
	printf("%d %d",h,y);
}

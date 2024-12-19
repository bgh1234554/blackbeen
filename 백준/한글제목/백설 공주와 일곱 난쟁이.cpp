#include <stdio.h>

int main(){
	int count = 0;
	int a[10] = {};
	for(int i=0;i<9;i++){
		scanf("%d", &a[i]);
		count += a[i];
	}
	int gap = count - 100;
	int x,y;
	for(int i=0;i<9;i++){
		for(int j=i+1;j<9;j++){
			if(a[i]+a[j]==gap){
				x=i;
				y=j;
			}
		}
	}
	for(int i=0;i<9;i++){
		if(i!=x && i!=y){
			printf("%d\n", a[i]);
		}
	}
}

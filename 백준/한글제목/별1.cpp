#include <stdio.h>

int main(){
	int a;
	scanf("%d",&a);
	for(int i=0; i<a; i++){
		for(int j=0; j<i; j++){
			printf(" ");
		}
		for(int k=0; k<2*a-(2*(i+1)-1); k++){
			printf("*");
		}
		printf("\n");
	}
			for(int x=0; x<a-1; x++){
		for(int y=0; y<a-2-x; y++){
			printf(" ");
		}
		for(int z=0; z<2*x+3; z++){
			printf("*");
		}
		printf("\n");
	}
}


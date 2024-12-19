#include <stdio.h>

int main(){
	int zero = 0;
	int arr[5] = {};
	for(int k=0;k<3;k++){
	for(int i = 0; i<4; i++){
		scanf("%d", &arr[i]);
		if(arr[i] == 0){
			zero+=1;
		}
	}
	if(zero == 0){
		printf("E\n");
	}
	if(zero == 1){
		printf("A\n");
	}
	if(zero == 2){
		printf("B\n");
	}
	if(zero == 3){
		printf("C\n");
	}
	if(zero == 4){
		printf("D\n");
	}
	zero = 0;			
}
}

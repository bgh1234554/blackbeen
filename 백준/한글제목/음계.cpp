#include <stdio.h>

int main(){
	int a[9] = {};
	int b;
	int ascend = 0;
	int descend = 0;
	for(int i=0; i<8; i++){
		scanf("%d", &b);
		a[i] = b;
	}
	for(int j = 0; j<7; j++){
		if (a[j+1] - a[j] == 1){
			ascend = ascend + 1;
		}
		else if (a[j+1] - a[j] == -1){
			descend = descend + 1;
		}
	}
	if (ascend == 7){
		printf("ascending");
	}
	else{
		if (descend == 7){
			printf("descending");
		}
		else{
			printf("mixed");
		}
}
}

#include <stdio.h>

int main(){
	int a[5] = {};
	int sum = 0;
	for(int i = 0; i<5; i++){
		scanf("%d", &a[i]);
		if (a[i] < 40) {
			a[i] = 40;
		}
		sum = sum + a[i];
	}
	printf("%d", sum/5);
		}
	





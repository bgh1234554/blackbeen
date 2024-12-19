#include <stdio.h>

int main(){
	int a[11] = {}; /*input number array*/ 
	int b;
	int c[43] = {}; /*나머지 담아두는 배열*/ 
	int count = 0;
	for(int i = 0; i<10; i++){
		scanf("%d", &b);
		a[i] = b;
	}
	for(int k = 0; k<43; k++){
		c[k] = 0;
	}
	for(int j = 0; j<10; j++){
		int d = a[j] % 42;
		c[d] = c[d] + 1;
	}
	for(int m = 0; m<43; m++){
		if (c[m] > 0){
			count = count + 1;
		}
	}
	printf("%d", count);
}

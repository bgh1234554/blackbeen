#include <stdio.h>

int main(){
	int a [101] = {};
	int b;
	int c;
	int count = 0;
	scanf("%d", &b);
	for(int k = 0; k<100; k++){
		a[k] = 0;
	}
	for(int i = 0; i<b; i++){
		scanf("%d", &c);
		a[c] = a[c] + 1;
		if (a[c] > 1){
			count = count + 1;
		}
	}
	printf("%d", count);
}

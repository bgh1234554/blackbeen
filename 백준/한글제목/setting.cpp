#include <stdio.h>
#include <string.h>

int main(){
	char a[101] = {};
	scanf("%s", &a);
	int b[123] = {};
	for(int i=97; i<123; i++){
		b[i] = 0;
	}
	for(int j=0; j<strlen(a); j++){
		b[a[j]] = b[a[j]] + 1;
	}
	for(int k=97; k<123; k++){
	printf("%d ", b[k]);
	}
}

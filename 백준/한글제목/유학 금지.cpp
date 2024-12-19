#include <stdio.h>
#include <string.h>

int main(){
	char a[101] = {};
	scanf("%s", a);
	for(int i=0;i<strlen(a);i++){
		if(a[i]!='A' && a[i]!='C' && a[i]!='M' && a[i]!='B' && a[i]!='R' && a[i]!='I' && a[i]!='D' && a[i]!='G' && a[i]!='E'){
			printf("%c", a[i]);
		}
	}
}

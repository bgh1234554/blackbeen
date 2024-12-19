#include <stdio.h>

int main(){
	int a;
	int b=0;
	int c=100;
	for(int i=1; i<=7; i++){
		scanf("%d", &a);
		if (a % 2 == 1) {
			b = a+b;
			if (a<c) {
				c=a;
			}
		}
	}
	if (b==0)  {
	printf("-1");}
	else printf("%d\n%d", b, c);
}



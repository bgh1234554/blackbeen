#include <stdio.h>
#include <math.h>

int main(){
	int a,b,c,d,e,f;
	scanf("%d", &a);
	scanf("%d", &b);
	scanf("%d", &c);
	scanf("%d", &d);
	scanf("%d", &e);
	f = pow(a,2)+pow(b,2)+pow(c,2)+pow(d,2)+pow(e,2);
	int g = f % 10;
	printf("%d", g);
}

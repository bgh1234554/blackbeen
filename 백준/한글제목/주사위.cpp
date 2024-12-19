#include <stdio.h>

int main(){
int a;
int b;
int c;
scanf("%d%d%d", &a, &b, &c);
if (a==b && b==c) printf("%d", 10000+a*1000);
else if (a==b) {
	if (b==c) printf("%d", 10000+a*1000);
	else printf("%d", a*100+1000);
}
else if (a==c) {
	if (b==c) printf("%d", 10000+a*1000);
	else printf("%d", a*100+1000);
}
else if (b==c) {
	if (a==c) printf("%d", 10000+a*1000);
	else printf("%d", b*100+1000);
}
else {
	if (a>=b) {
		if (a>=c) printf("%d", a*100);
		else printf("%d", c*100);
	}
	else {
		if(b>=c) printf("%d", b*100);
		else printf("%d", c*100);
	}
}
}


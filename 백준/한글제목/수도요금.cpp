#include <stdio.h>

int main(){
	int a,b,c,d,p;
	int x,y,ans;
	scanf("%d",&a);
	scanf("%d",&b);
	scanf("%d",&c);
	scanf("%d",&d);
	scanf("%d",&p);
	x = a*p;
	if(p>c){
		y = b + d*(p-c);
	}
	else{
		y = b;
	}
	if(x>y){
		ans = y;
	}
	else{
		ans = x;
	}
	printf("%d", ans);
} 

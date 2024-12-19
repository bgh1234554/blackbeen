#include <stdio.h>

int main(){
	int t;
	int n,m;
	int x,y;
	scanf("%d", &t);
	for(int i=0;i<t;i++){
		scanf("%d",&n);
		scanf("%d",&m);
		x = 2*m-n;
		y = m-x;
		printf("%d %d\n",x,y);
	}
}

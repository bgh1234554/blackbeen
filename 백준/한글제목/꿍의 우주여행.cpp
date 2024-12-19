#include <stdio.h>

int main(){
	int t;
	scanf("%d", &t);
	int n,d;
	int v,f,c;
	float x;
	int count = 0;
	for(int i=0;i<t;i++){
		scanf("%d", &n);
		scanf("%d", &d);
		for(int j=0;j<n;j++){
			scanf("%d", &v);
			scanf("%d", &f);
			scanf("%d", &c);
			x = v*f/c;
			if(x>=d){
				count += 1;
			}						
		}
		printf("%d\n", count);
		count = 0;
	}
}

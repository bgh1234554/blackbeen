#include <stdio.h>
#include <math.h>

int main(){
	int t;
	scanf("%d", &t);
	int n,m;
	float x;
	int count = 0;
	for(int i=0;i<t;i++){
		scanf("%d", &n);
		scanf("%d", &m);
		for(int b=1;b<n;b++){
			for(int a=1;a<b;a++){
				x = (pow(a,2)+pow(b,2)+m)/(a*b);
				if(x == int(x)){
					count +=1;
				}
			}
		}
		printf("%d\n",count);
		count = 0;
	}
}

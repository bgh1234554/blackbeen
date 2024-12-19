#include <stdio.h>

int main(){
	int n;
	int r,e,c;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&r);
		scanf("%d",&e);
		scanf("%d",&c);
		if(e-c==r){
			printf("does not matter\n");
		}
		else if(e-c>r){
			printf("advertise\n");
		}
		else{
			printf("do not advertise\n");
		}
	}
}

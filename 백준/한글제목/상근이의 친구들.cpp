#include <stdio.h>

int main(){
	int m,f;
	int t;
	while(true){
		scanf("%d",&m);
		scanf("%d",&f);
		if(m==0 && f==0){
			break;
		}
		else{
		t = m+f;
		printf("%d\n",t);
		}
	}
}

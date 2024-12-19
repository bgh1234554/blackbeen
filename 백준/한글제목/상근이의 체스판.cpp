#include <stdio.h>

int main(){
	int r,c,a,b;
	scanf("%d %d",&c,&r);
	scanf("%d %d",&a,&b);
	for(int i=1;i<c+1;i++){
		if(i%2==1){
			for(int j=1;j<a+1;j++){
				for(int k=1;k<r+1;k++){
					if(k%2==1){
						for(int l=1;l<b+1;l++){
							printf("X");
						}
					}
					else{
						for(int l=1;l<b+1;l++){
							printf(".");
						}
					}
				}
				printf("\n");
			}
		}
		else{
			for(int j=1;j<a+1;j++){
				for(int k=1;k<r+1;k++){
					if(k%2==1){
						for(int l=1;l<b+1;l++){
							printf(".");
						}
					}
					else{
						for(int l=1;l<b+1;l++){
							printf("X");
						}
					}
				}
				printf("\n");
			}			
		}
	}
}

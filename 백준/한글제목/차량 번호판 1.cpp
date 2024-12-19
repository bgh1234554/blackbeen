#include <stdio.h>
#include <string.h>

int main(){
	int ans=1;
	char u[5] = {};
	scanf("%s", u);
	for(int i=0;i<strlen(u);i++){
		if(u[i] == 'c'){
			if(i=0){
				ans=ans*26;
			}
			else{
				if(u[i-1] = 'c'){
					ans=ans*25;
				}
				else{
					ans=ans*26;
				}
			}
		}
		else{
			if(i=0){
				ans=ans*10;
			}
			else{
				if(u[i-1] = 'd'){
					ans = ans*9;
				}
				else{
					ans = ans*10;
				}
			}			
		}
	}
	printf("%d", ans);
}

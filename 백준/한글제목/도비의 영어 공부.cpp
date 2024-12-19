#include <stdio.h>
#include <string.h>

int main(){
	char x;
	char a[251] = {};
	int count = 0;
	while(true){
		scanf("%c",&x);
		if(x == '#'){
			break;
		}
		else{
			fgets(a,sizeof(a),stdin);
			for(int i=0;i<strlen(a);i++){
				if(a[i]<97){
					if(a[i]+32==x){
						count += 1;
					}
				}
				else{
					if(a[i] == x){
						count += 1;
					}
				}
			}
			printf("%c %d\n",x,count);
			count = 0;
		}		
	}
}

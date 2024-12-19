#include <stdio.h>
#include <string.h>

int main(){
	int n;
	scanf("%d",&n);
	char sen[101] = {};
	int count = 0;
	int x;
	for(int z=0;z<n;z++){
		fgets(sen,sizeof(sen),stdin);
		while(count !=2){	
			for(int i=0;i<strlen(sen);i++){
				if(count == 2){
					x = i;
					break;
				}
				if(sen[i] == ' '){
					count += 1;
				}
			}
		}
		for(int j=x+1; j<strlen(sen);j++){
			printf("%c", sen[j]);
		}
		printf(" ");
		for(int k=0; k<=x; k++){
			printf("%c", sen[k]);
		}
		printf("\n");
	}
}

#include <stdio.h>
#include <string.h>

int main(){
	char sen[256] = {};
	int smile = 0;
	int sad = 0;
	fgets(sen,sizeof(sen),stdin);
	for(int i=0;i<strlen(sen)-2;i++){
		if(sen[i] == ':' && sen[i+1] == '-' && sen[i+2] == ')'){
			smile += 1;
		}
		else if(sen[i] == ':' && sen[i+1] == '-' && sen[i+2] == '('){
			sad += 1;
		}
	}
	if (smile == 0 && sad == 0){
		printf("none");
	}
	else if(smile == sad){
		printf("unsure");
	}
	else if(smile > sad){
		printf("happy");
	}
	else if(smile < sad){
		printf("sad");
	}
}

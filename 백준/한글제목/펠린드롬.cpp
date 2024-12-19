#include<stdio.h>
#include<string.h>

int main(){
	char x[6] = {};
	while(true){
	scanf("%s", x);
	if(x[0] == '0'){
		break;
	}
	int i = 0;
	while(true){
		if(x[i] == '\0'){
			break;
		}
		i += 1;
	}
	int count = 0;
	for(int j=0; j<i; j++){
		if(x[j] == x[i-1-j]){
			count += 1;
		}
	}
	if(count == i){
		printf("yes\n");
	}
	else{
		printf("no\n");
	}
}
}

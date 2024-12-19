#include <stdio.h>
#include <string.h>
#include <math.h>

int main(){
	char x[100] = {};
	int y;
	while(true){
	scanf("%s", x);
	if(x[0] == '#'){
		break;
		}
	else{
	int i = strlen(x);
	int count = 0;
	for(int j=0; j<strlen(x); j++){
		if(x[j] == '-'){
		y = 0*pow(8,i-1);
		}
		if(x[j] == '\\'){
		y = 1*pow(8,i-1);
		}
		if(x[j] == '('){
		y = 2*pow(8,i-1);
		}
		if(x[j] == '@'){
		y = 3*pow(8,i-1);
		}
		if(x[j] == '?'){
		y = 4*pow(8,i-1);
		}
		if(x[j] == '>'){
		y = 5*pow(8,i-1);
		}
		if(x[j] == '&'){
		y = 6*pow(8,i-1);
		}
		if(x[j] == '%'){
		y = 7*pow(8,i-1);
		}
		if(x[j] == '/'){
		y = (-1)*pow(8,i-1);
		}
		count += y;
		i-=1;														
	}
	printf("%d\n", count);
}
}
}

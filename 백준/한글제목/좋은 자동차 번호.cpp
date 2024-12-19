#include <stdio.h>
#include <math.h>

int main(){
	int n;
	scanf("%d", &n);
	char num[101][9] = {};
	int count = 0;
	int countt = 0;
	for(int i=0;i<n;i++){
		scanf("%s", num[i]);
		for(int j=0;j<3;j++){
			count += (num[i][j]-65)*pow(26,2-j);			
		}
		for(int j=4;j<8;j++){
			countt += (num[i][j]-48)*pow(10,7-j);
		}
		if(abs(count-countt)<=100){
			printf("nice\n");
		}
		else{
			printf("not nice\n");
		}
		count = 0;
		countt = 0;
	}
}

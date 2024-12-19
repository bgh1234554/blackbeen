#include <stdio.h>

int main(){
	int n;
	scanf("%d", &n);
	int max=0;
	int p;
	int price[101] = {};
	char player[101][21] = {};
	char highest[2][21] = {};
	for(int i=0;i<n;i++){
		scanf("%d", &p);
		for(int j=0; j<p; j++){
			scanf("%d", &price[j]);
			scanf("%s", player[j]);
		}
		for(int k=0;k<p;k++){
			if(price[k]>max){
				max = price[k];
				for(int x=0;x<21;x++){
				highest[0][x] = player[k][x];
				}
			}
		}
		printf("%s\n", highest[0]);
		max = 0;
	}
}

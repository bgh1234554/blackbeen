#include <stdio.h>

int main(){
	int n;
	scanf("%d", &n);
	char m[101][101] = {};
	for(int i=0;i<n;i++){
		scanf("%s", &m[i]);
	}
	int f;
	scanf("%d",&f);
	if(f==1){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
			printf("%c", m[i][j]);
			}
		printf("\n");
		}
	}
	else if(f==3){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				printf("%c", m[n-i-1][j]);
			}
			printf("\n");
		}
	}
	else if(f==2){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				printf("%c", m[i][n-j-1]);
			}
			printf("\n");			
		}
	}
}

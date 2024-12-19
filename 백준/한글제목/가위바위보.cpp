#include <stdio.h>

int main(){
	int t;
	scanf("%d", &t);
	int p=0;
	int pp=0;
	char dual[3] = {};
	int n;
	for(int i=0;i<t;i++){
		scanf("%d", &n);
		for(int k=0;k<n;k++){
			for(int j=0;j<2;j++){
			scanf("%s", &dual[j]);
			}
			if(dual[0] == 'R' && dual[1] == 'S'){
				p += 1;
			}
			else if(dual[0] == 'R' && dual[1] == 'P'){
				pp += 1;
			}
			else if(dual[0] == 'S' && dual[1] == 'P'){
				p += 1;
			}
			else if(dual[0] == 'S' && dual[1] == 'R'){
				pp += 1;
			}
			else if(dual[0] == 'P' && dual[1] == 'S'){
				pp += 1;
			}
			else if(dual[0] == 'P' && dual[1] == 'R'){
				p += 1;
			}
		}
		if(p == pp){
			printf("TIE\n");
		}
		else if(p>pp){
			printf("Player 1\n");
		}
		else{
			printf("Player 2\n");
		}		
		p=0;
		pp=0;
	}
}

#include <stdio.h>

int main(){
	int t;
	scanf("%d", &t);
	int gan[7] = {};
	int sou[8] = {};
	int ganscore;
	int souscore;
	int x;
	for(int i=0;i<t;i++){
		for(int j=0;j<6;j++){
			scanf("%d", &gan[j]);
		}
		for(int j=0; j<7; j++){
			scanf("%d", &sou[j]);
		}
		ganscore = 1*gan[0]+2*gan[1]+3*(gan[2]+gan[3])+4*gan[4]+10*gan[5];
		souscore = 1*sou[0]+2*(sou[1]+sou[2]+sou[3])+3*sou[4]+5*sou[5]+10*sou[6];
		x = i+1;
		if(ganscore == souscore){
			printf("Battle %d: No victor on this battle field\n", x);
		}
		else if(ganscore > souscore){
			printf("Battle %d: Good triumphs over Evil\n",x);
		}
		else{
			printf("Battle %d: Evil eradicates all trace of Good\n",x);
		}
	}
}

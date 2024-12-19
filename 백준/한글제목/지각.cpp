#include <stdio.h>
#include <math.h>

int main(){
	int n;
	scanf("%d", &n);
	int delay=0;
	int teach;
	int possible = 0;
	for(int i=0;i<n;i++){
		scanf("%d", &teach);
		while(true){
			if(delay+pow(delay,2)<=teach){
				possible = delay;
				delay += 1;
			}
			else{
				break;
			} 
		}
		printf("%d\n",possible);
		delay = 0;
	}
}

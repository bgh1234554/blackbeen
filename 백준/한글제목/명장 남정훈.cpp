#include <stdio.h>

int main(){
	int l,r,a;
	scanf("%d %d %d", &l,&r,&a);
	int x;
	while(true){
		if(l==r && a==1){
			printf("%d", l*2);
			break;
		}
		else if(a==0){
			if(l==r){
				printf("%d", l*2);
				break;
			}
			else if(l>r){
				printf("%d", r*2);
				break;
			}
			else{
				printf("%d", l*2);
				break;
			}
		}
		else{
			if(l>r){
				a-=1;
				r+=1;
			}
			else if(l<r){
				a-=1;
				l+=1;
			}
			else{
				if(a%2==0){
					x = a/2;
					a = 0;
					l+=x;
					r+=x;
				}
				else{
					x = a/2;
					a = 1;
					l+=x;
					r+=x;
				}
			} 
		}
	}
}

#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int t,n;
	scanf("%d",&t);
	int shop[21] = {};
	int min = 100;
	int max = 0;
	for(int i=0;i<t;i++){
		scanf("%d",&n);
		for(int j=0;j<n;j++){
			scanf("%d", &shop[j]);
			if(shop[j]>max){
				max = shop[j];
			}
			if(shop[j]<min){
				min = shop[j];
			}
		}
		printf("%d\n", (max-min)*2);
		max = 0;
		min = 100;
	}
}

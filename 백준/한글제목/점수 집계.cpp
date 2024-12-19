#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int t;
	scanf("%d", &t);
	int score[6] = {};
	int max, min;
	int count = 0;
	for(int i=0; i<t; i++){
		for(int j=0;j<5;j++){
			scanf("%d", &score[j]);
			count += score[j];
		}
		sort(score,score+5);
		min = score[0];
		max = score[4];
		if(score[3]-score[1]>=4){
			printf("KIN\n");
		}
		else{
			count = count - min - max;
			printf("%d\n", count);
		}
		count = 0; 
	}
}

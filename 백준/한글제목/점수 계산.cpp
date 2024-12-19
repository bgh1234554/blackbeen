#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int a[9] = {};
	int b[9] = {};
	for(int i=0;i<8;i++){
		scanf("%d",&a[i]);
	}
	for(int j=0;j<8;j++){
		b[j] = a[j];
	}
	sort(b,b+8);
	int score =0;
	score = b[3] + b[4] + b[5] + b[6] + b[7];
	printf("%d\n", score);
	int c[9] = {};
	for(int i=0;i<9;i++){
		c[i] = 0;
	}
	for(int x=3;x<8;x++){
		for(int i=0;i<8;i++){
			if(a[i] == b[x]){
				c[i] += 1;
			}
		}
	}
	int ans;
	for(int i=0;i<8;i++){
		if(c[i] == 1){
			ans = i+1;
			printf("%d\n", ans);
		}
	}
}

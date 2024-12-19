#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int n,l;
	int h[10001] = {};
	scanf("%d",&n);
	scanf("%d", &l);
	for(int i=0;i<n;i++){
		scanf("%d", &h[i]);
	}
	sort(h,h+n);
	for(int j=0;j<n;j++){
		if(h[j]<=l){
			l+=1;
		}
	}
	printf("%d",l);
} 

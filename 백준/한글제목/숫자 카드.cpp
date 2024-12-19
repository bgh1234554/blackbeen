#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	int a[500001] = {};
	for(int i=0;i<n;i++){
		scanf("%d", &a[i]);
	}
	sort(a,a+n);
	int m;
	scanf("%d", &m);
	while(m--){
		int target; scanf("%d", &target);
	    int left = 0, right = n-1, mid = (left+right)/2;
	    while(left <= right){
		    mid = (left+right)/2;
	    	if(target>a[mid]) left = mid+1;
	    	else if(target<a[mid]) right = mid-1;
	    	else break;
	    }
	    if(left <= right) printf("1\n");
	    else printf("0\n");
	}
}

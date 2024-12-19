#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int music[1000001];

bool decision(int mid, int N, int M){
	int cnt = 1, size = mid;
	for(int i=0;i<N;i++){
		if(mid >= song[i]){
			size -= song[i];
		}
		else{
			cnt++;
			size = mid-song[i];
		}
	}
	return cnt >= M;
}

int main(){
	int N,M,Max=0; cin >> N >> M;
	for(int i=0;i<N;i++){
		scanf("%d", &music[i]);
		Max = max(Max,music[i]);
	}
	int left = Max-1, right = 100001, mid;
	while(left+1<right){
		mid = (left+right)/2;
		if(decision(mid,N,M)){
			left = mid;
		}
		else{
			right = mid;
		}
	}
	printf("%d\n", left);
}

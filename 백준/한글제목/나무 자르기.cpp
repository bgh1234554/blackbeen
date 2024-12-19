#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int tree[1000001];

bool decision(int h,int N,int M){
	long long sum = 0;
	for(int i = 0; i < N; i++){
		sum += min(N, tree[i]-h);
	}
	return sum >= M;
}

int main(){
	int N, M; cin >> N >> M;
	for(int i = 0; i < N; i++){
		scanf("%d", &tree[i]);
	}
	int left = 0, right = 1000000000, mid;
	while(left+1 < right) {
		mid = (left+right)/2;
		if(decision(mid, N,M)){
			left = mid;
		}
		else {
			right = mid;
		}
	}
	printf("%d\n", left);
}

#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int area[1000001];

bool decision(int mid,int N, int M){
	long long sum = 0;
	for(int i = 0; i < N; i++){
		sum += min(mid,area[i]);
	}
	return sum <= M;
}

int main(){
	int N, M; cin >> N;
	int Max = 0;
	for(int i = 0; i < N; i++){
		scanf("%d", &area[i]);
		Max = max(Max,area[i]);
	}
	cin >> M;
	int left = 0, right = Max+1, mid;
	while(left+1 < right) {
		mid = (left+right)/2;
		if(decision(mid, N, M)){
			left = mid;
		}
		else {
			right = mid;
		}
	}
	printf("%d\n", left);
}

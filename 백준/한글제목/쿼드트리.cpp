#include <iostream> 

using namespace std;

int video[100][100];

int check(int y, int x, int size){
	int tmp = video[y][x];
	for(int i = y; i < y+size; i++){
		for(int j = x; j< x+size; j++){
			if(tmp != video[i][j]) return -1;
		}
	}
	return tmp;
}

void dq(int y, int x, int size){
	int zip = check(y, x, size);
	if(zip != -1){
		printf("%d", zip);
		return;
	}
	printf("(");
	dq(y, x, size/2);
	dq(y, x+size/2, size/2);
	dq(y+size/2, x, size/2);
	dq(y+size/2, x+size/2, size/2);
	printf(")");
}

int main(){
	int N; cin >> N;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			scanf("%1d", &video[i][j]);
		}
	}
	dq(0, 0, N);
}

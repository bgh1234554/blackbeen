#include <iostream>

using namespace std;

int blue,white,red;
int paper[3000][3000];

int check(int y, int x, int size){
	int tmp = paper[y][x];
	for(int i=y; i<y+size; i++){
		for(int j=x; j<x+size; j++){
			if(paper[i][j] != tmp){
				return -2;
			}
		}
	}
	if(tmp == 1) blue++;
	if(tmp == 0) white++;
	if(tmp == -1) red++;
	return tmp;
}

void dq(int y,int x, int size){
	if(check(y,x,size) != -2){
		return;
	}
	int q = size/3;
	dq(y,x,q);
	dq(y,x+q,q);
	dq(y,x+2*q,q);
	dq(y+q,x,q);
	dq(y+q,x+q,q);
	dq(y+q,x+2*q,q);
	dq(y+2*q,x,q);
	dq(y+2*q,x+q,q);
	dq(y+2*q,x+2*q,q);
	return;
}

int main(){
	int N; cin >> N;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cin >> paper[i][j];
		}
	}
	dq(0,0,N);
	cout << red << "\n";
	cout << white << "\n";
	cout << blue << "\n";
}

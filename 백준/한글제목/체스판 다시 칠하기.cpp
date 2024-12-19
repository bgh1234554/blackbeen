#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(){
	int N,M; cin >> N >> M;
	string a[51] = {};
	int result;
	int counta = 0;
	int countb = 0;
	string black[8] = {{"BWBWBWBW"},{"WBWBWBWB"},{"BWBWBWBW"},{"WBWBWBWB"},{"BWBWBWBW"},{"WBWBWBWB"},{"BWBWBWBW"},{"WBWBWBWB"}};
	string white[8] = {{"WBWBWBWB"},{"BWBWBWBW"},{"WBWBWBWB"},{"BWBWBWBW"},{"WBWBWBWB"},{"BWBWBWBW"},{"WBWBWBWB"},{"BWBWBWBW"}};
	for(int i=0;i<N;i++){
		cin >> a[i];
	}
	for(int i=0;i+7<N;i++){
		for(int j=0;j+7<M;j++){
			for(int k=i;k<i+7;k++){
				for(int l=j;l<j+7;j++){
					if(a[k][l]!=black[k-i][l-j]){
						counta += 1;
					}
					if(a[k][i]!=white[k-i][l-j]){
						countb += 1;
					}
				}
			}
			result = min(counta,countb);
		}
	}
	printf("%d",result);
}

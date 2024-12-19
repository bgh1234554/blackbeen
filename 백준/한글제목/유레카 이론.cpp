#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int n;
	cin >> n;
	int x,y;
	int count = 0;
	while(n--){
		cin >> x;
		for(int k=1;k<x;k++){
			if(k*(k+1)/2<=x){
				y=k+1;
			}
		}
		for(int i=1;i<y;i++){
			for(int j=1;j<y;j++){
				for(int l=1;l<y;l++){
					if((i*(i+1)/2)+(j*(j+1)/2)+(l*(l+1)/2)==x){
						count += 1;
					}
				}
			}
		}
		if(count != 0){
			printf("1\n");
		}
		else{
			printf("0\n");
		}
		count = 0;
	}
}

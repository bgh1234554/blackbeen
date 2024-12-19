#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int a[10] = {};
	int count = 0; 
	for(int i=0;i<9;i++){
		scanf("%d",&a[i]);
		count += a[i];
	}
	int n,m;
	for(int j=0;j<9;j++){
		for(int k=0;k<9;k++){
			if(j!=k && count-a[j]-a[k] == 100){
				n = j;
				m = k;
			}
		}
	}
	a[n] = -1;
	a[m] = -1;
	sort(a,a+9);
	for(int i=2;i<9;i++){
		printf("%d\n",a[i]);
	}
}

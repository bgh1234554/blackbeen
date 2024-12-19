#include <iostream>
#include <string>
using namespace std;

int main(){
	string x;
	string y;
	cin >> x;
	int n;
	scanf("%d", &n);
	int f;
	int count = 0;
	for(int i=0;i<n;i++){
		cin >> y;
		f = y.find(x);
		if(f != -1){
			count += 1;
		}
	}
	printf("%d", count);
}

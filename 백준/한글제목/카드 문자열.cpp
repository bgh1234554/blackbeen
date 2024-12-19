#include <iostream>
#include <string>

using namespace std;

int main(){
	int t,n;
	cin >> t;
	for(int i=0;i<t;i++){
		cin >> n;
		string ans;
		for(int j=0;j<n;j++){
			string tmp;
			cin >> tmp;
			if(ans+tmp>tmp+ans){
				ans = tmp + ans;
			}
			else{
				ans = ans + tmp;
			}
		}
		cout << ans << '\n';
	}
}

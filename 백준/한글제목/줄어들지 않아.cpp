#include <iostream>

using namespace std;

long long dp[65][10];


int main(){
    for(int i = 0; i < 10; i++){
        dp[1][i] = 1;
    }
    for(int i = 1; i <= 64; i++){
        for(int j = 0; j < 10; j++){
            for(int k = 0; k <= j; k++){
                dp[i][j] += dp[i-1][k];
            }
        }
    }
    int t; cin >> t;
    while(t--){
        long long ans = 0;
        int n; cin >> n;
        for(int i = 0; i < 10; i++){
            ans += dp[n][i];
        }
        printf("%lld\n", ans);
    }
}

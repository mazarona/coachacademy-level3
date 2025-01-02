#include <bits/stdc++.h>
using namespace std;

int arr[5] = {1, 5, 10, 25, 50};




// hmw(i, t) = hwm(i, t-arr[i]) + hwm(i+1, t);
int main(){
    int n;
    while(cin >> n){
        int dp[5][7490];
        memset(dp, 0, sizeof dp);

        // base case
        for(int i = 0; i < 5; i++) dp[i][0] = 1;

        for(int i = 5; i >= 0; i--){
            for(int j = 1; j <= n; j++){

                if(i+1 < 5) dp[i][j] = dp[i+1][j];
                if(j-arr[i] >= 0) dp[i][j] += dp[i][j-arr[i]];


            }
        }

        cout << dp[0][n] << endl;
    }
    return 0;
}

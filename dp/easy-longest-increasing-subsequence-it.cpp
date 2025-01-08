#include <bits/stdc++.h>

using namespace std;


// lis(i, maxSoFar) = max(lis(i+1, maxSoFar), lis(i+1, vec[i]));

int main(){
    int n; cin >> n;
    vector<int> vec(n);
    for(auto &x: vec) cin >> x;


    int dp[10][21];
    memset(dp, 0, sizeof dp);
    // base case
    for(int m = 0; m <= 20; m++) dp[n-1][m] = (m < vec[n-1]);

    for(int i = n-2; i >= 0; i--){
        for(int m = 0; m <= 20; m++){
            int op1 = 0, op2 = 0;

            // Do not take option.
            op1 = dp[i+1][m];

            // Take option.
            if(vec[i] > m) op2 = dp[i+1][vec[i]] + 1;

            dp[i][m] = max(op1, op2);
        }
    }

    cout << dp[0][0] << endl;
    return 0;
}

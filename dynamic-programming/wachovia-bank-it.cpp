#include <bits/stdc++.h>

using namespace std;

int k, m;
vector<int> val;
vector<int> weight;

int main(){
    int t; cin >> t;
    while(t--){
        cin >> k >> m;
        val.resize(m);
        weight.resize(m);
        for(int i = 0; i < m; i++) cin >> weight[i] >> val[i];
        int dp[50][10001];
        memset(dp, 0, sizeof dp);
        // base case (GREEDY)
        for(int i = k; i >= weight[m-1]; i--) dp[m-1][i] = val[m-1];

        for(int i = m-2; i >= 0;i--){
            for(int j = 0; j <= k; j++){
                int op1 = 0, op2 = 0;

                // Do not take option
                op1 = dp[i+1][j];

                // take if possible. 
                if(j-weight[i] >= 0) 
                    op2 = dp[i+1][j-weight[i]] + val[i];

                // find the max between the two.
                dp[i][j] = max(op1, op2);
            }
        }
        cout << "Hey stupid robber, you can get " << dp[0][k] << "." << endl;
    }
    return 0;
}

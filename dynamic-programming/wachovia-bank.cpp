#include <bits/stdc++.h>

using namespace std;

int k, m;
vector<int> weight;
vector<int> value;
int dp[50][10001];

int sol(int i, int rem){
    if(i == m) return 0;
    if(dp[i][rem] != -1) return dp[i][rem];

    int op1 = (rem - weight[i] >= 0)? value[i] + sol(i+1, rem-weight[i]) : 0;
    int op2 = sol(i+1, rem);

    return dp[i][rem] = max(op1, op2);
}

int main(){
    int N; cin >> N;
    while(N--){
        cin >> k >> m;
        weight.resize(m);
        value.resize(m);
        memset(dp, -1, sizeof dp);
        for(int i = 0; i < m; i++){
            cin >> weight[i];
            cin >> value[i];
        }
        cout << "Hey stupid robber, you can get " << sol(0, k) << "." << endl;
    }

    return 0;
}

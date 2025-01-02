#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int n;
vector<ll> dp;
vector<int> val;
ll sol(int i){
    if(i >= n) return 0;
    if(dp[i] != -1) return dp[i];

    ll op1 = val[i] + sol(i+2);
    ll op2 = sol(i+1);

    return dp[i] = max(op1, op2);
}

int main(){
    int t; cin >> t;
    int cn = 1;
    while(t--){
        cin >> n;
        dp.resize(n);
        val.resize(n);
        fill(dp.begin(), dp.end(), -1);
        for(auto &x: val) cin >> x;
        cout << "Case  " << cn++ << ": " << sol(0) << endl;
    }
    return 0;
}
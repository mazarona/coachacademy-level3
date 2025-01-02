#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int n, k;
const int M = 1e9 + 7;
ll dp[2000][2001];
ll sol(int i, int ch){
    if(i == k) return 1;

    if(dp[i][ch] != -1) return dp[i][ch];
    ll ans = 0;
    for(int j = ch; j <= n; j += ch){
        ans += sol(i + 1, j) % M;
    }
    return dp[i][ch] = ans % M;
}

int main(){
    cin >> n >> k;
    memset(dp, -1, sizeof dp);
    cout << sol(0, 1) << endl;
    return 0;
}

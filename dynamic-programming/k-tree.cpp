#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int n, k, d;
ll dp[101][101];
const int M = 1e9 + 7;
ll sol(int s, int mx){
    if(s > n) return 0;
    if(s == n && mx >= d) return 1;

    if(dp[s][mx] != -1) return dp[s][mx];

    ll ans = 0;
    for(int i = 1; i <= k; i++){
        ans += sol(s+i, max(mx, i)) % M;
    }
    return dp[s][mx] = ans % M;
}

int main(){
    cin >> n >> k >> d;
    memset(dp, -1, sizeof dp);
    cout << sol(0, 0) << endl;
    return 0;
}
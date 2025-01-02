#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll dp[5][30001];
int coins[5] = {1, 5, 10, 25, 50};
ll sol(int i, int rem){
    if(i == 5) return 0;
    if(rem == 0) return 1;
    if(dp[i][rem] != -1) return dp[i][rem];

    ll op1 = (coins[i] <= rem)? sol(i, rem-coins[i]) : 0;
    ll op2 = sol(i+1, rem);

    return dp[i][rem] = op1 + op2;
}

int main(){
    int n;
    memset(dp, -1, sizeof dp);
    while(cin >> n){
        ll res = sol(0, n);
        if(res == 1){
            cout << "There is only 1 way to produce " << n << " cents change." << endl;
        }
        else{
            cout << "There are " << res << " ways to produce " << n << " cents change." << endl;
        }
    }
    return 0;
}
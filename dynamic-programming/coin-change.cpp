#include <bits/stdc++.h>
using namespace std;

int dp[7490][7490];
int coins[5] = {50, 25, 10, 5, 1};
int sol(int i, int rem){
    if(i == 5) return 0;
    if(rem == 0) return 1;
    if(dp[i][rem] != -1) return dp[i][rem];

    int op1 = (coins[i] <= rem)? sol(i, rem-coins[i]) : 0;
    int op2 = sol(i+1, rem);

    return dp[i][rem] = op1 + op2;
}

int main(){
    int n;
    memset(dp, -1, sizeof dp);
    while(cin >> n){
        cout << sol(0, n) << endl;
    }
    return 0;
}
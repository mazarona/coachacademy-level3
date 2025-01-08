#include<bits/stdc++.h>

using namespace std;

int n;
string s1, s2;
int dp[1000][1000];
int sol(int i, int k){
    if(i == s1.size() || k == s2.size()) return 0;
    if(dp[i][k] != -1) return dp[i][k];
    if(s1[i] == s2[k]) return 1 + sol(i+1, k+1);

    int op1 = sol(i, k+1);
    int op2 = sol(i+1, k);

    return dp[i][k] = max(op1, op2);
}

int main(){
    while(getline(cin, s1)){
        getline(cin, s2);
        memset(dp, -1, sizeof dp);
        cout << sol(0, 0) << "\n";
    }
    return 0;
}

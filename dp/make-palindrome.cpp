#include <bits/stdc++.h>
using namespace std;
string s;

int dp[1000][1000];
int sol(int l, int r){
    if(l >= r) return 0; // only one or no elment left.
    if(dp[l][r] != -1) return dp[l][r];

    if(s[l] == s[r]) return dp[l][r] = sol(l+1, r-1);
    int op1 = 1 + sol(l+1, r); // take the left char
    int op2 = 1 + sol(l, r-1); // take the right char

    return dp[l][r] = min(op1, op2);
}

string ans;
void print(int l, int r){
    if(l >= r) return; // only one or no elment left.

    if(s[l] == s[r]){
        ans = s[l] + ans;
        ans += s[r];
        print(l+1, r-1);
        return;
    } 

    int ret = sol(l, r);
    int op1 = sol(l+1, r);
    if(ret == op1) {
        print(l+1, r);
        return;
    }
    print(l, r+1);

}

int main(){
    while(getline(cin, s)){
        ans = "";
        memset(dp, -1, sizeof dp);
        cout << sol(0, s.size()-1) << endl;
        print(0, s.size()-1);
        cout << ans << endl;
    }
    return 0;
}
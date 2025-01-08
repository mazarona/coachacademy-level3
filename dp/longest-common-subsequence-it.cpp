#include <bits/stdc++.h>

using namespace std;

// lcs(i, j) = max(lcs(i+1, j+1) + 1, lcs(i+1, j), lcs(i, j+1));
int main(){
    string s1, s2;
    while(getline(cin, s1)){
        getline(cin, s2);

        int dp[1001][1001];
        memset(dp, 0, sizeof dp);

        int sz1 = s1.size(); 
        int sz2 = s2.size();

        for(int i = sz1-1; i >= 0; i--){
            for(int j = sz2-1; j >= 0; j--){
                if(s1[i] == s2[j]) dp[i][j] = dp[i+1][j+1] + 1;
                else dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
            }
        }

        cout << dp[0][0] << endl;
    }
    return 0;
}

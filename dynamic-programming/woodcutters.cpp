#include <bits/stdc++.h>
using namespace std;

int n;
vector<pair<int, int>> trees;
const int N = 1e5;
int dp[N][2];

int sol(int i, bool lc){
    if(i >= n) return 0;
    if(dp[i][lc] != -1) return dp[i][lc];

    int op1 = 0, op2 = 0, op3 = 0;
    // check if I can cut to the left.
    if(i == 0 || (lc && trees[i].first - trees[i].second > trees[i-1].first + trees[i-1].second) || (!lc && trees[i].first - trees[i].second > trees[i-1].first)){
        op1 = 1 + sol(i+1, false);
    }
    // check if I can cut to the right.
    if(i == n-1 || (trees[i].first + trees[i].second < trees[i+1].first))
        op2 = 1 + sol(i+1, true);
    // Do not cut tree at i
    op3 = sol(i+1, false);

   int mx = 0;
   mx = max(mx, op1);
   mx = max(mx, op2);
   mx = max(mx, op3);

    return dp[i][lc] = mx;
}

int main(){
    cin >> n;
    memset(dp, -1, sizeof dp);
    trees.resize(n);
    for(auto &x: trees){
        cin >> x.first;
        cin >> x.second;
    }
    cout << sol(0, false) << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> vec;
vector<int> dp;

int sol(int i){
    if(i >= n) return 0;
    if(dp[i] != -1) return dp[i];

    if(vec[i] == -1 || vec[i] == -2) return sol(i + 1);

    for(int j = i+1; j < n; j++){
        if(vec[j] == vec[i] + 1) vec[j] = -1;
        if(vec[j] == vec[i] - 1) vec[j] = -2;
    }

    int op1 = vec[i] + sol(i+1);
    
    for(int j = i+1; j < n; j++){
        if(vec[j] == -1) vec[j] = vec[i] + 1;
        if(vec[j] == -2) vec[j] = vec[i] - 1;
    }

    int op2 = sol(i+1);

    return dp[i] = max(op1, op2);

}

int main(){
    cin >> n;
    vec.resize(n);
    dp.resize(n);
    fill(dp.begin(), dp.end(), -1);
    for(auto &x: vec) cin >> x;
    cout << sol(0) << endl;

    return 0;
}
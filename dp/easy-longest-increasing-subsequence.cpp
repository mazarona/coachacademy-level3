#include<bits/stdc++.h>

using namespace std;

int n;
string s;
int sol(int i, int maxSoFar){
    if(i == n) return 0;
    return max((s[i] > maxSoFar)? 1 + sol(i+1, s[i]) : 0, sol(i+1, maxSoFar));
}

int main(){
    cin >> s;
    n = s.size();
    cout << sol(0, 0) << endl;
    return 0;
}
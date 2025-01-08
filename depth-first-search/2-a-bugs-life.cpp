
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
typedef long long ll;


const int N = 1e5;
vector<int> adj[N];
int color[N];

bool dfs(int p){
  bool ans = true;
  for(auto c: adj[p]){
    if(!color[c]){
      color[c] = (color[p]==1)? 2:1;
      ans &= dfs(c);
    }
    else if(color[c] == color[p]){
      return false;
    }
  }
  return ans;
}

int main(){
  IO;
  int s; cin >> s;
  for(int i = 0; i < s; i++){
    // take input
    int n, m; cin >> n >> m;
    // clear adjacency matrix
    for(int j = 1; j <= n; j++){
      adj[j].clear();
      color[j] = 0;
    }

    // take edges
    for(int j = 0; j < m; j++){
      int u, v;cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    // check if is partite
    bool isPartite = true;
    for(int j = 1; j <= n; j++){
      if(!color[j]) {
        color[j] = 1;
        isPartite &= dfs(j);
      }
    }
    // Output result
    cout << "Scenario #" << i+1 << ":\n";
    if (isPartite) {
      cout << "No suspicious bugs found!\n";
    } else {
      cout << "Suspicious bugs found!\n";
    }



  }
  return 0;
}


// problem link: https://codeforces.com/problemset/problem/445/B

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define IO                          \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL);                    \
  cout.tie(NULL);
typedef long long ll;

const int N = 1e6 + 1;
vector<int> adj[N];
bool vis[N];

// each state returns 1 + number of nodes of its subtree
void dfs(int u)
{
  vis[u] = true;

  for (auto &v : adj[u])
  {
    if (!vis[v])
      dfs(v);
  }
}

int main()
{
  IO;
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++)
  {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  int cnt = 0;
  for (int i = 1; i <= n; i++)
  {
    if (!vis[i])
    {
      cnt++;
      dfs(i);
    }
  }

  cout << (1 << (n - cnt)) << endl;

  return 0;
}

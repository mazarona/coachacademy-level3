// problem link: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1549

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
int dfs(int u)
{
  vis[u] = true;
  int cnt = 1;

  for (auto &v : adj[u])
  {
    if (!vis[v])
      cnt += dfs(v);
  }

  return cnt;
}

int main()
{
  IO;
  int t;
  cin >> t;
  while (t--)
  {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
      adj[i].clear();
    }
    memset(vis, 0, n + 1);

    for (int i = 0; i < m; i++)
    {
      int u, v;
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    int ans = 0;

    for (int i = 1; i <= n; i++)
    {
      if (!vis[i])
        ans = max(ans, dfs(i));
    }

    cout << ans << endl;
  }

  return 0;
}

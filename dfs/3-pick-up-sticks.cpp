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
bool visited[N];

// does it have a cycle
vector<int> path;
bool dfs(int u, int parent)
{
  bool hasCycle = false;
  visited[u] = true;
  for (auto v : adj[u])
  {
    if (!visited[v])
    {
      path.push_back(v);
      hasCycle |= dfs(v, u);
    }
    else if (v != parent)
    {
      hasCycle = true;
    }
  }
  return hasCycle;
}

int main()
{
  IO;
  while (1)
  {
    int n, m;
    cin >> n >> m;
    if (n == 0)
      break;

    // clear
    for (int i = 1; i <= n; i++)
    {
      adj[i].clear();
      visited[i] = false;
    }

    for (int i = 0; i < m; i++)
    {
      int u, v;
      cin >> u >> v;
      adj[u].push_back(v);
    }

    bool hasCycle = false;
    for (int i = 1; i <= n; i++)
    {
      if (!visited[i])
      {
        path.clear();
        path.push_back(i);
        hasCycle |= dfs(i, 0);
      }
    }

    if (hasCycle)
      cout << "IMPOSSIBLE" << endl;
    else
    {
      for (auto x : path)
        cout << x << endl;
    }
  }

  return 0;
}

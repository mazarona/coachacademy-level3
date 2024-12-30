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

stack<int> ts;
vector<int> path;

// does it have a cycle
bool dfs(int p)
{
  bool hasCycle = false;
  visited[p] = true;
  for (auto c : adj[p])
  {
    if (!visited[c])
    {
      path.push_back(c);
      hasCycle |= dfs(c);
      path.pop_back();
    }
    else
    {
      if (find(path.begin(), path.end(), c) != path.end())
        hasCycle = true;
    }
  }
  ts.push(p);
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
    path.clear();
    while (!ts.empty())
      ts.pop();

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
        path.push_back(i);
        hasCycle |= dfs(i);
      }
    }

    if (hasCycle)
      cout << "IMPOSSIBLE" << endl;
    else
    {
      while (!ts.empty())
      {
        cout << ts.top() << endl;
        ts.pop();
      }
    }
  }

  return 0;
}

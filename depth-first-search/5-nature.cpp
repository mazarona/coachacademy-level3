// problem link: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1626

#include <iostream>
#include <bits/stdc++.h>
const int N = 1e5 + 10, mod = 998244353;
using namespace std;
map<string, vector<string>> adj;
map<string, int> visited;
vector<string> nature;

int DFS(string source)
{
  int cnt = 1;
  visited[source] = 1;
  for (auto node : adj[source])
  {
    if (!visited[node])
    {
      cnt += DFS(node);
    }
  }
  return cnt;
}

int main()
{
  int t, n, m, a, b;
  string s1, s2;
  while (1)
  {
    cin >> n >> m;
    if (n == 0 && m == 0)
      break;

    for (int i = 0; i < n; i++)
    {
      cin >> s1;
      nature.push_back(s1);
    }

    for (int i = 0; i < m; i++)
    {
      cin >> s1 >> s2;
      adj[s1].push_back(s2);
      adj[s2].push_back(s1);
    }
    int counter = 0, ans = 0;
    for (int i = 0; i < n; i++)
    {
      if (!visited[nature[i]])
      {
        int counter = DFS(nature[i]);
        ans = max(ans, counter);
      }
    }
    cout << ans << "\n";
    visited.clear();
    adj.clear();

    for (auto x : adj)
      x.second.clear();
    nature.clear();
  }
}
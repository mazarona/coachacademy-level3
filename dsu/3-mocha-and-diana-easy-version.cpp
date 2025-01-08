// problem link: https://codeforces.com/problemset/problem/1559/D1
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Dsu
{
  vector<int> sz;
  vector<int> p;

public:
  Dsu(int n)
  {
    sz.resize(n);
    p.resize(n);
    for (int i = 0; i < n; i++)
    {
      p[i] = i;
      sz[i] = 1;
    }
  }

  int find(int u)
  {
    if (u == p[u])
      return u;
    return p[u] = find(p[u]);
  }

  bool same(int u, int v)
  {
    return (find(u) == find(v));
  }

  void uni(int u, int v)
  {
    u = find(u);
    v = find(v);

    if (u != v)
    {
      if (sz[u] > sz[v])
        swap(u, v);
      p[u] = v;
      sz[v] += sz[u];
    }
  }
};

int main()
{
  int n, m1, m2;
  cin >> n >> m1 >> m2;

  Dsu s1(n + 1);
  Dsu s2(n + 1);
  for (int i = 0; i < m1; i++)
  {
    int u, v;
    cin >> u >> v;
    s1.uni(u, v);
  }
  for (int i = 0; i < m2; i++)
  {
    int u, v;
    cin >> u >> v;
    s2.uni(u, v);
  }

  vector<pair<int, int>> ans;
  for (int i = 1; i <= n; i++)
  {
    int u = i;
    for (int j = i + 1; j <= n; j++)
    {
      int v = j;
      if (s1.same(u, v) || s2.same(u, v))
        continue;
      else
      {
        s1.uni(u, v);
        s2.uni(u, v);
        ans.push_back({u, v});
      }
    }
  }
  cout << ans.size() << endl;
  for (auto x : ans)
  {
    cout << x.first << " " << x.second << endl;
  }

  return 0;
}
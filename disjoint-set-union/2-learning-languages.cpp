// problem link: https://codeforces.com/problemset/problem/277/A
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int p[200];
int sz[200];
const int eoff = 100;

void make_set(int u)
{
  p[u] = u;
  sz[u] = 1;
}

int find_set(int u)
{
  if (u == p[u])
    return u;
  return p[u] = find_set(p[u]);
}

void union_sets(int u, int v)
{
  u = find_set(u);
  v = find_set(v);
  if (u != v)
  {
    if (sz[u] > sz[v])
      swap(u, v);
    p[u] = v;
    sz[v] += sz[u];
  }
}

int main()
{
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    make_set(i + eoff);

  for (int i = 0; i < m; i++)
    make_set(i);

  for (int i = 0; i < n; i++)
  {
    int k;
    cin >> k;
    for (int j = 0; j < k; j++)
    {
      int l;
      cin >> l;
      l--;
      union_sets(i + eoff, l);
    }
  }
  int mx = 0;
  int ml = 0;
  for (int i = 0; i < m; i++)
  {
    if (sz[find_set(i)] >= mx)
    {
      mx = sz[find_set(i)];
      ml = i;
    }
  }

  ml = find_set(ml);

  int cnt = 0;
  for (int i = 0; i < n; i++)
  {
    if (find_set(i + eoff) != find_set(ml))
    {
      union_sets(i + eoff, ml);
      cnt++;
    }
  }

  cout << cnt << endl;
  return 0;
}
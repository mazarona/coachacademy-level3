#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int p[26];
int sz[26];

vector<pair<char, char>> ans;

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
    ans.push_back({u + 'a', v + 'a'});
  }
}

int main()
{
  int n;
  cin >> n;
  string s1, s2;
  cin >> s1 >> s2;
  // start by making all different isolated single node sets
  for (int i = 0; i < 26; i++)
    make_set(i);

  for (int i = 0; i < n; i++)
    union_sets(s1[i] - 'a', s2[i] - 'a');

  cout << ans.size() << endl;
  for (auto x : ans)
    cout << x.first << " " << x.second << endl;

  return 0;
}
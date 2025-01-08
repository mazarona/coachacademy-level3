// problem link: https://www.spoj.com/problems/PT07Y/en/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define IO                          \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL);                    \
  cout.tie(NULL);
typedef long long ll;

const int N = 1e5;
vector<int> adj[N];
bool visited[N];

// returns the number of nodes it will visit + itself
int dfs(int p)
{
  visited[p] = true;
  int cnt = 1;
  for (auto c : adj[p])
  {
    if (!visited[c])
      cnt += dfs(c);
  }

  return cnt;
}

int main()
{
  IO int n, m;
  cin >> n >> m;
  if (n - m != 1)
  {
    cout << "NO" << endl;
    return 0;
  }

  for (int i = 0; i < m; i++)
  {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  if (dfs(1) != n)
    cout << "NO" << endl;
  else
    cout << "YES" << endl;

  return 0;
}

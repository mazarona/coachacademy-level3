// problem link: https://codeforces.com/problemset/problem/520/B
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define N 1e4 + 1
#define INF 1e9

int n, m;
bool is_valid(int u)
{
	return (u >= 0 && u <= N);
}

int main()
{
	cin >> n >> m;
	vector<int> dis(N, INF);

	queue<int> q;
	q.push(n);
	dis[n] = 0;

	while (!q.empty())
	{
		int u = q.front();
		q.pop();

		int v1 = u * 2;
		if (is_valid(v1) && dis[v1] == INF)
		{
			dis[v1] = dis[u] + 1;
			if (v1 == m)
			{
				cout << dis[v1] << endl;
				return 0;
			}
			q.push(v1);
		}

		int v2 = u - 1;
		if (is_valid(v2) && dis[v2] == INF)
		{
			dis[v2] = dis[u] + 1;
			if (v2 == m)
			{
				cout << dis[v2] << endl;
				return 0;
			}
			q.push(v2);
		}
	}

	cout << dis[m] << endl;
}

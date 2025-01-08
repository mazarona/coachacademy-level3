// problem link: https://codeforces.com/problemset/problem/35/C
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define N 1e4 + 1
#define INF 1e9

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int n, m;
bool is_valid(int x, int y)
{
	return (x >= 1 && x <= n && y >= 1 && y <= m);
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	cin >> n >> m;
	vector<vector<int>> dis(n + 1, vector<int>(m + 1, INF));
	queue<pair<int, int>> q;
	int k;
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		int x, y;
		cin >> x >> y;
		dis[x][y] = 0;
		q.push({x, y});
	}

	int mx = 0;
	int ansx = 0;
	int ansy = 0;
	while (!q.empty())
	{
		auto u = q.front();
		int x = u.first;
		int y = u.second;
		q.pop();

		if (dis[x][y] >= mx)
		{
			mx = dis[x][y];
			ansx = x;
			ansy = y;
		}

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (is_valid(nx, ny) && dis[nx][ny] == INF)
			{
				dis[nx][ny] = dis[x][y] + 1;
				q.push({nx, ny});
			}
		}
	}
	cout << ansx << " " << ansy << endl;
	return 0;
}

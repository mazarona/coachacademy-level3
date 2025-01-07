#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define N 1000

int dx[8] = {1, 1, -1, -1, 2, 2, -2, -2};
int dy[8] = {2, -2, 2, -2, 1, -1, 1, -1};

bool is_valid(int x, int y){
	return (x >= 1 && x <= 8 && y >= 1 && y <= 8);
}

int main(){
	string s1, s2;
	while(cin >> s1 >> s2){
		pair<int, int> src = {s1[1]-'1' + 1, s1[0]-'a'+1};
		pair<int, int> target = {s2[1]-'1' + 1, s2[0]-'a'+1};

		int dis[9][9];
		for(int i = 1; i <= 8; i++) for(int j = 1; j <= 8; j++) dis[i][j] = N;

		queue<pair<int, int>> q;
		q.push(src);
		dis[src.first][src.second] = 0;

		while(!q.empty()){
			auto u = q.front();
			q.pop();
			int x = u.first;
			int y = u.second;
			for(int i = 0; i < 8; i++){
				int nx = x + dx[i];
				int ny = y + dy[i];
				if(is_valid(nx, ny) && dis[nx][ny] == N){
					q.push({nx, ny});
					dis[nx][ny] = dis[x][y] + 1;
				}
			}
		}


		printf("To get from %s to %s takes %d knight moves.\n", s1.c_str(), s2.c_str(), dis[target.first][target.second]);

	}
	return 0;
}

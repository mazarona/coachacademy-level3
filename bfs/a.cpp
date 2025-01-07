#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main(){
	int n , m; cin >> n >> m;
	if(n - m != 1) {
		cout << "NO" << '\n';
		return 0;
	}


	vector<vector<int>> adj(n+1);
	for(int i = 0; i < m; i++){
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	queue<int> q;
	vector<bool> vis(n+1, false);

	q.push(1);
	while(!q.empty()){
		int u = q.front();
		q.pop();
		vis[u] = true;
		for(auto v: adj[u]) if(!vis[v]) q.push(v);
	}

	bool f = true;
	for(int i = 1; i <= n; i++) {
		if(!vis[i]){
			f = false;
			  break;
		}
	}
	
	if(f) cout << "YES" << '\n';
	else cout << "NO" << '\n';


	return 0;
}

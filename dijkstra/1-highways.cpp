// problem link: https://www.spoj.com/problems/HIGHWAYS/en/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
const int OO = 1e9;
const int N = 1e5+1;

int n, m, s, t;
vector<pair<int, int>> adj[N];

vector<int> dijkstra(int s){
    vector<int> d(n+1, OO);
    d[s] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, s});
    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        for(auto &c: adj[u]){
            int w = c.first;
            int v = c.second;
            if(d[v] > d[u] + w){
                d[v] = d[u] + w;
                pq.push({d[v], v});
            }
        }
    }

    return d;
}

void solve(){
    cin >> n >> m >> s >> t;
    for(int i = 0; i < m; i++){
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }
    int ans = dijkstra(s)[t];
    if(ans == OO) cout << "NONE" << '\n';
    else cout << ans << '\n'; 
}


int main(){
    IO;
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
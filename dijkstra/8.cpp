// problem link: https://codeforces.com/problemset/problem/1433/G
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define pll pair<ll, ll>
typedef long long ll;
const ll OO = 1e12;
const ll N = 1e3+1;

vector<pll> adj[N];
ll p[N];
ll n, m, k;

vector<ll> dijkstra(ll s){
    vector<ll> d(n+1, OO);
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({0, s});
    d[s] = 0;
    p[s] = s;
    while(!pq.empty()){
        ll u = pq.top().second;
        pq.pop();
        for(auto c: adj[u]){
            ll w = c.first;
            ll v = c.second;
            if(d[v] > d[u] + w){
                d[v] = d[u] + w;
                p[v] = u;
                pq.push({d[v], v});
            }
        }
    }
    return d;
}

void solve(){
    cin >> n >> m >> k;

    vector<vector<ll>> contrib(n+1, vector<ll>(n+1, 0));
    vector<vector<ll>> weights(n+1, vector<ll>(n+1, 0));

    for(ll i = 1; i <= n; i++) adj[i].clear();

    for(ll i = 0; i < m; i++){
        ll u, v, w; cin >> u >> v >> w;
        weights[u][v] = w;
        weights[v][u] = w;
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }

    ll result = 0;
    map<string, ll> freq;
    // knlogm
    for(ll i = 0; i < k; i++){
        ll s, t; cin >> s >> t;
        result += dijkstra(s)[t];

        // get the path
        vector<ll> path;
        while(t != p[t]){
            path.push_back(t);
            t = p[t];
        }
        path.push_back(s);
        reverse(path.begin(), path.end());

        // calculate the contribution of each road in the path
        ll sz = path.size();
        for(ll i = 0; i< sz - 1; i++){
            ll u = path[i];
            ll v = path[i+1];
            contrib[u][v] += weights[u][v];
            contrib[v][u] += weights[u][v];
        }
    }
    ll mx = 0;
    for(ll i = 1; i <= n; i++){
        for(ll j = 1; j <= n; j++){
            mx = max(mx, contrib[i][j]);
        }
    }
    cout << mx << '\n';

}


int main(){
    IO;
    ll t; 
    t = 1;
    //cin >> t;
    for(ll i = 1; i <= t; i++){
        solve();
    }
    return 0;
}
// problem link: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1927
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define pll pair<ll, ll>
typedef long long ll;
const ll OO = 1e12;
const ll N = 1e5+1;

vector<pll> adj[N];
ll cost[N];
ll n, m, s, t;

vector<ll> dijkstra(ll s){
    vector<ll> d(n+1, OO);
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({0, s});
    d[s] = 0;
    while(!pq.empty()){
        ll u = pq.top().second;
        pq.pop();
        for(auto c: adj[u]){
            ll w = c.first;
            ll v = c.second;
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

    for(int i = 0; i < n; i++) adj[i].clear();
    for(int i = 0; i < m; i++){
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }

    auto ans = dijkstra(s)[t];
    if(ans == OO) cout << "unreachable" << '\n';
    else cout << ans << '\n';

}


int main(){
    IO;
    ll t; 
    //t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++){
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}
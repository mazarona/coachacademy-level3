// problem link: https://codeforces.com/problemset/problem/20/C
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define pii pair<ll, ll>
typedef long long ll;
const ll OO = 1e12;
const ll N = 1e5+1;

ll n, m;
vector<pii> adj[N];
ll p[N];

vector<ll> dijkstra(ll s){
    vector<ll> d(n+1, OO);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    d[s] = 0;
    p[s] = s;
    pq.push({0, s});
    while(!pq.empty()){
        ll u = pq.top().second;
        pq.pop();
        for(pii c: adj[u]){
            ll w = c.first; 
            ll v = c.second;
            if(d[v] > d[u] + w){
                p[v] = u;
                d[v] = d[u] + w;
                pq.push({d[v], v});
            }
        }
    }
    return d;
}

void solve(){
    cin >> n >> m;
    for(ll i = 0; i < m; i++){
        ll u, v, w; cin >> u >> v >> w;
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }
    ll ans = dijkstra(1)[n];
    if(ans == OO) cout << -1 << '\n';
    else{
        ll x = n;
        vector<ll> vec;
        while(n != p[n]){
            vec.push_back(n);
            n = p[n];
        }
        vec.push_back(1);
        reverse(vec.begin(), vec.end());
        for(auto x: vec) cout << x << " ";
        cout << '\n';
   }
}


int main(){
    IO;
    ll t; 
    t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
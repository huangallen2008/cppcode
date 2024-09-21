#include<bits/stdc++.h>
using namespace std;
#define int long long
#define REP(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define Graph vector<vector<int>>
const int mod=1e9+9;
const int maxn=5;
const int inf=(1ll<<50);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
const int AL=666666;
int f(Graph &g,int u,int fa) {
    int ret=AL;
    for(int v:g[u]) {
        if(v==fa) continue;
        ret=ret*(AL+f(g,v,u))%mod;
    }
    return ret;
}
signed main() {
    int T;
    cin>>T;
    while(T--) {
        int n;
        cin>>n;
        Graph g1(n);
        REP(i,n-1) {
            int u,v;
            cin>>u>>v,u--,v--;  
            g1[u].pb(v);
            g1[v].pb(u);
        }
        Graph g2(n);
        REP(i,n-1) {
            int u,v;
            cin>>u>>v,u--,v--;  
            g2[u].pb(v);
            g2[v].pb(u);
        }
        if(f(g1,0,-1)==f(g2,0,-1)) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}
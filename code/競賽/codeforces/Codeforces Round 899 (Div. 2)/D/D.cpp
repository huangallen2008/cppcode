#include<bits/stdc++.h>
using namespace std;
#define int long long
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,n) FOR(i,0,n)
#define REP1(i,n) FOR(i,1,(n)+1)
#define RREP(i,n) for(int i=(n)-1;i>=0;i--)
#define f first
#define s second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)(x.size())
#define SQ(x) (x)*(x)
#define pii pair<int,int>
#define Graph vector<vector<int>>
#define IOS() cin.sync_with_stdio(0),cin.tie(0),cout.tie(0)
const int inf=(1ll<<63)-1;
const int maxn=2e5+5;
const int mod=998244353;
vector<int> a,sz,m;
vector<bool> vis;
Graph g;
int n;
void build_sz(int u) {
    vis[u]=1;
    sz[u]=1;
    for(int v:g[u]) {
        if(vis[v]) continue;
        build_sz(v);
        sz[u]+=sz[v];
    }
}
int cal_m0(int u) {
    vis[u]=1;
    int r=0;
    for(int v:g[u]) {
        if(vis[v]) continue;
        r+=cal_m0(v)+(a[u]^a[v])*sz[v];
    }
    return r;
}
void cal_m(int u) {
    vis[u]=1;
    for(int v:g[u]) {
        if(vis[v]) continue;
        m[v]=m[u]+(a[u]^a[v])*(n-sz[v]*2);
        cal_m(v);
    }
}
void solve() {
    cin>>n;
    a=vector<int>(n);
    m=vector<int>(n);
    sz=vector<int>(n);
    vis=vector<bool>(n);
    g=Graph(n);
    REP(i,n) cin>>a[i];
    REP(i,n-1) {
        int x,y;
        cin>>x>>y;
        x--,y--;
        g[x].pb(y);
        g[y].pb(x);
    }
    vis=vector<bool>(n);
    build_sz(0);
    vis=vector<bool>(n);
    m[0]=cal_m0(0);
    vis=vector<bool>(n);
    cal_m(0);
    REP(i,n) cout<<m[i]<<" ";
    cout<<"\n";
}
signed main() {
    IOS();
    int T;
    cin>>T;
    while(T--) {
        solve();
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops,fast-math")
// #pragma GCC target("avx2,bmi,popcnt")
#define int long long
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,n) for(int i=1;i<=(n);i++)
#define RREP(i,n) for(int i=(n)-1;i>=0;i--)
#define RREP1(i,n) for(int i=(n);i>=1;i--)
#define f first
#define s second
#define pb push_back
#define ALL(x) (x).begin(),(x).end()
#define SZ(x) (int)((x).size())
#define SQ(x) (x)*(x)
#define pii pair<int,int>
#define pipii pair<int,pii>
#define Graph vector<vector<int>>
#define Graphw vector<vector<pii>>
#define IOS() ios::sync_with_stdio(0),cin.tie(0)
#define md(x) (((x)%(mod)+(mod))%(mod))
#define MD(x,M) (((x)%(M)+(M))%(M))
#define ld long double
#define pdd pair<ld,ld>
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)
#define addmod(x,y) x=((x+(y))%mod)
#ifdef LOCAL
#define op(x) cout<<(#x)<<"="<<(x)<<", ";
#define ope(x) cout<<(#x)<<"="<<(x)<<endl;
#define oparr(x) cout<<(#x)<<":";for(auto &allen:(x)) cout<<allen<<" ";cout<<" size="<<(x).size()<<endl;
#define entr cout<<endl;
#else
#define op(x) ;
#define ope(x) ;
#define oparr(x) ;
#define entr ;
#endif
const int mod=1e9+7;
const int maxn=20+5;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
Graphw g;
int n,k,t;
bitset<maxn> vis;
int cnt=0;
void dfs(int u,int x) {
    if(u>=n||cnt>=t) return;
    dfs(u+1,x);
    for(auto [v,w]:g[u]) {
        if(vis[v]) continue;
        if(x<w) continue;
        cnt++;
        vis[v]=1;
        dfs(u+1,x-w);
        vis[v]=0;
    }
}
signed main() {
    IOS();
    cin>>n>>k>>t;
    g=Graphw(n);
    REP(i,k) {
        int u,v,w;
        cin>>u>>v>>w;
        u--,v--;
        g[u].pb({v,w});
    }
    int l=0,r=20005,m;
    while(l<r) {
        m=l+r>>1;
        dfs(0,m);
        if(cnt>=t) r=m;
        else l=m+1;
    }
    cout<<l<<'\n';
    return 0;
}
/*
2 4 4
1 1 1
1 2 2
2 1 3
2 2 7

*/
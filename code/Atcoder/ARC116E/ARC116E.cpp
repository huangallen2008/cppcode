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
const int maxn=2e5+5;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
Graph g;
int n,k;
vector<int> lu,hc;
int dfs(int u,int p,int k) {
    int an=0;
    for(auto v:g[u]) {
        if(v==p) continue;
        an+=dfs(v,u,k);
        chmax(lu[u],lu[v]+1);
        chmin(hc[u],hc[v]+1);
    }
    if(lu[u]<=k-hc[u]) lu[u]=hc[u]-k-1;
    else {
        if(lu[u]==k) {
            an++;
            hc[u]=0,lu[u]=-k-1;
        }
    } 
    if(p==-1&&lu[u]>=0) an++;
    return an;
}
int mds(int k) {
    lu=vector<int>(n);
    hc=vector<int>(n,inf);
    return dfs(0,-1,k);
}
signed main() {
    IOS();
    cin>>n>>k;
    g=Graph(n);
    REP(i,n-1) {
        int u,v;
        cin>>u>>v;
        u--,v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    int l=1,r=n,m;
    while(l<r) {//first m that mds(m)<=k
        m=l+r>>1;
        int ret=mds(m);
        if(ret<=k) r=m;
        else l=m+1;
    }
    cout<<l<<'\n';
    return 0;
}

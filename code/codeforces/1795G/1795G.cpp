#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops,fast-math")
#pragma GCC target("avx2,popcnt")
// #define int long long
#define ll long long
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
#define RREP(i,n) for(int i=(n)-1;i>=0;i--)
#define RREP1(i,n) for(int i=(n);i>=1;i--)
#define f first
#define s second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)(x.size())
#define SQ(x) (x)*(x)
#define pii pair<int,int>
#define pipii pair<int,pii>
#define Graph vector<vector<int>>
#define IOS() ios::sync_with_stdio(0),cin.tie(0)
#define md(x) (((x)%(mod)+(mod))%(mod))
#define MD(x,M) (((x)%(M)+(M))%(M))
#define ld long double
#define pdd pair<ld,ld>
#ifdef LOCAL
#define op(x) cout<<(#x)<<"="<<(x)<<", ";
#define ope(x) cout<<(#x)<<"="<<(x)<<endl;
#define oparr(x) cout<<(#x)<<":";REP(allen,(x).size()) cout<<x[allen]<<" ";cout<<" size="<<(x).size()<<endl;
#define entr cout<<endl;
#else
#define op(x) ;
#define ope(x) ;
#define oparr(x) ;
#define entr ;
#endif
const int mod=1e9+7;
const int maxn=1e5+5;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
const int maxn2=1024;
bitset<maxn2> cg[maxn]; 
int a[maxn],deg[maxn],tps[maxn],tpsid=0;;
vector<int> g[maxn],ng[maxn];
queue<int> q;
void solve() {
    int n,m;
    cin>>n>>m;
    REP(i,n) g[i].clear();
    REP(i,n) ng[i].clear();
    memset(a,0,sizeof(a));
    memset(deg,0,sizeof(deg));
    memset(tps,0,sizeof(tps));
    REP(i,n) cin>>a[i];
    REP(i,m) {
        int u,v;
        cin>>u>>v;
        u--,v--;
        g[u].pb(v);
        g[v].pb(u);
        deg[u]++,deg[v]++;
    }
    REP(i,n) if(deg[i]==a[i]) q.push(i);
    tpsid=0;
    while(q.size()) {
        int u=q.front();
        q.pop();
        tps[tpsid++]=u;
        for(int &v:g[u]) {
            deg[v]--;
            if(deg[v]>=a[v])ng[u].pb(v);
            if(deg[v]==a[v]) q.push(v);
        }
    }
    ll an=0;
    for(int t=0;t<n;t+=maxn2) {
        REP(i,n) cg[i].reset();
        for(int i=t;i<t+maxn2&&i<n;i++) cg[i][i-t]=1;
        RREP(i,n) {
            int u=tps[i];
            for(int &v:ng[u]) {
                cg[u]|=cg[v];
            }
        }
        REP(i,n) an+=cg[i].count();
    }
    an=((ll)n*(n+1)>>1)-an;
    cout<<an<<'\n';
}
signed main() {
    IOS();
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}
/*
1
3 2
1 0 1
2 3
1 2
*/
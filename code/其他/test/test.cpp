#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops,fast-math")
// #pragma GCC target("avx2,sse4,bmi,popcnt")
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
#define oparr(x) cout<<(#x)<<":";for(auto &mken:(x)) cout<<mken<<" ";cout<<" size="<<(x).size()<<endl;
#define entr cout<<endl;
#else
#define op(x) ;
#define ope(x) ;
#define oparr(x) ;
#define entr ;
#endif
const int mod=1e9+7;
const int maxn=5;
const int inf=(1ll<<50);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
Graphw g;
vector<int> va;
int dfs(int u,int pa) {
    int mx=0;
    for(auto [v,w]:g[u]) {
        if(v==pa) continue;
        int r=dfs(u,v)+w;
        if(r>mx) {
            if(mx!=-1) va.pb(mx);
            mx=r;
        }
        else va.pb(r);
    }
    return mx;
}
signed main() {
    IOS();
    int n;
    cin>>n;
    g=Graphw(n);
    REP(i,n-1) {
        int u,v,w;
        cin>>u>>v>>w,u--,v--;
        g[u].pb({v,w});
        g[v].pb({v,w});
    }
    dfs(0,-1);
    sort(ALL(va),greater<int>());
    vector<int> an(n+1);
    REP1(i,n) {
        if(i>va.size()) an[i]=an[i-1];
        else an[i]=an[i-1]+va[i-1];
    }
    REP1(i,n) cout<<an[i]*2<<' ';
    cout<<'\n';
    return 0;
}
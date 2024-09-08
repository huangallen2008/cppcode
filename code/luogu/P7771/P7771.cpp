#include<bits/stdc++.h>
using namespace std;
// #pragma GCC optimize("O3,unroll-loops,fast-math")
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
#define Vi vector<int>
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
const int mod=998244353;
const int maxn=1e5+5;
const int maxm=2e5+5;
const int inf=(1ll<<50);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
Graph g;
int n,m;
vector<int> cur;
Vi an;
bitset<maxm> vis;
void dfs(int u) {
    for(;cur[u]<g[u].size();) {
        dfs(g[u][cur[u]++]);
    }
    an.pb(u);
}
signed main() {
    IOS();
    cin>>n>>m;
    g=Graph(n);
    cur=Vi(n);
    vis.reset();
    Vi ind(n);
    REP(i,m) {
        int u,v;
        cin>>u>>v,u--,v--;
        g[u].pb(v);
        ind[v]++;
    }
    bool ok=1;
    int cnt[2]={0,0};
    REP(i,n) {
        int dif=SZ(g[i])-ind[i];
        if(dif>1||dif<-1) {ok=0;break;}
        if(dif==1) cnt[1]++;
        if(dif==-1) cnt[0]++;
    }
    if(cnt[0]!=cnt[1]||cnt[0]>1) ok=0;
    if(!ok) {
        cout<<"No\n";
        return 0;
    }
    REP(i,n) sort(ALL(g[i]));
    dfs(0);
    reverse(ALL(an));
    for(auto &x:an) cout<<x+1<<' ';
    cout<<'\n';
    return 0;
}
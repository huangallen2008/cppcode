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
const int mod=1e9+7;
const int maxn=1e5+1;
const int maxb=17;
const int inf=(1ll<<50);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
int n,m;
Graph g;
vector<bool> col;
Vi sq;
const int sn=900;
Vi dp[2],cnt[2],an[2];
int cnt0,cnt1;
void dfs(int u,int fa) {
    for(int v:g[u]) {
        if(v==fa) continue;
        dfs(v,u);
        dp[0][u]+=dp[0][v]+cnt[0][v];
        cnt[0][u]+=cnt[0][v];
        dp[1][u]+=dp[1][v]+cnt[1][v];
        cnt[1][u]+=cnt[1][v];
    }
    cnt[col[u]][u]++;
}
void dfs2(int u,int fa) {
    if(fa==-1) {
        an[0][u]=dp[0][u];
        an[1][u]=dp[1][u];
    }
    else {
        an[0][u]=an[0][fa]+cnt0-cnt[0][u]-cnt[0][u];
        an[1][u]=an[1][fa]+cnt1-cnt[1][u]-cnt[1][u];
    }
    for(int v:g[u]) {
        if(v==fa) continue;
        dfs2(v,u);
    }
}
int st[maxb][maxn];
Vi dfn,dep,in;
void dfs0(int u,int fa) {
    in[u]=dfn.size();
    dfn.pb(u);
    for(int v:g[u]) {
        if(v==fa) continue;
        dep[v]=dep[u]+1;
        dfs0(v,u);
        dfn.pb(u);
    }
}
int N;
void init() {
    N=dfn.size();
    REP(i,N) {
        int u=dfn[i];
        st[0][i]=dep[u];
        // op(dep[u])
    }
    // entr
    REP1(i,maxb-1) {
        REP(j,N) {
            st[i][j]=min(st[i-1][j],st[i-1][min(N-1,j+(1<<i-1))]);
        }
    }
}
int qu(int l,int r) {
    int dd=__lg(r-l+1);
    return min(st[dd][l],st[dd][r-(1<<dd)+1]);
}
int lca_dep(int u,int v) {
    if(in[u]>in[v]) swap(u,v);
    return qu(in[u],in[v]);
}
int dis(int a,int b) {
    // op(a)op(b)op(in[a])op(in[b])ope(lca_dep(a,b))
    return dep[a]+dep[b]-(lca_dep(a,b)<<1);
}
signed main() {
    IOS(); 
    cin>>n>>m;
    sq=Vi(m);
    REP(i,m) sq[i]=i/sn;
    g=Graph(n);
    col=vector<bool>(n);
    REP(i,n) {
        int x;
        cin>>x;
        col[i]=x;
    }
    REP(i,n-1) {
        int u,v;
        cin>>u>>v,u--,v--;
        g[u].pb(v);
        g[v].pb(u);
    } 
    dep=in=Vi(n);
    dfs0(0,-1);
    // oparr(in)
    init();
    vector<int> tr[2];
    REP(i,m) {
        if(!i||sq[i]!=sq[i-1]) {
            dp[0]=dp[1]=cnt[0]=cnt[1]=an[0]=an[1]=Vi(n);
            dfs(0,-1);
            cnt0=cnt[0][0],cnt1=cnt[1][0];
            dfs2(0,-1);
            tr[0].clear(),tr[1].clear();
            // oparr(dp[0])oparr(dp[1])oparr(an[0])oparr(an[1])
        }
        int opt;
        cin>>opt;
        if(opt==1) {
            int v;
            cin>>v,v--;
            col[v]=col[v]^1;
            tr[col[v]].pb(v);
        }
        else {
            int u;
            cin>>u,u--;
            int r=an[col[u]][u];
            for(int v:tr[col[u]]) {
                // op(v)ope(dis(u,v))
                r+=dis(u,v);
            }
            // entr
            for(int v:tr[col[u]^1]) {
                // op(v)
                r-=dis(u,v);
            }
            // entr
            cout<<r<<'\n';
            // entr
        }
    }
    return 0;
}
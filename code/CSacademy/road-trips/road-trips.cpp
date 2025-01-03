#include<bits/stdc++.h>
using namespace std;
// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,sse4,bmi2,popcnt")
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
#define Vpii vector<pii>
#ifdef LOCAL
#define op(x) cout<<(#x)<<"="<<(x)<<", ";
#define ope(x) cout<<(#x)<<"="<<(x)<<endl;
#define oparr(x) {cout<<(#x)<<":";for(auto allen:(x)) cout<<allen<<" ";cout<<" size="<<(x).size()<<endl;}
#define entr cout<<endl;
#else
#define op(x) ;
#define ope(x) ;
#define oparr(x) ;
#define entr ;
#endif
template<typename T1,typename T2>
ostream& operator<<(ostream& os,pair<T1,T2> p) { return os<<'{'<<p.f<<','<<p.s<<'}'; }
template<typename T1,typename T2>
istream& operator>>(istream& os,pair<T1,T2> &p) { return os>>p.f>>p.s; }
template<typename S>
ostream& operator<<(ostream& os,vector<S> p) { for(auto allen:p) os<<allen<<' ';return os<<'\n'; }
template<typename S>
istream& operator>>(istream& os,vector<S> &p) { for(auto &allen:p) os>>allen;return os; }
const int mod=998244353;
const int maxn=1e5+5;
const int maxb=20;
const int inf=1e9;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
int st[maxb][maxn];
signed main() {
    IOS();
    int n,m;
    cin>>n>>m;
    Vi c(m);
    REP(i,m) cin>>c[i];
    sort(ALL(c));
    Graphw g(n);
    REP(i,n-1) {
        int u,v,w;
        cin>>u>>v>>w,u--,v--;
        g[u].pb({v,w});
        g[v].pb({u,w});
    }
    Vi dep(n),par(n),lev(n);//par[0]=0;
    Vi leaf;
    auto dfs=[&](auto dfs,int u,int fa)->void{
        for(auto [v,w]:g[u]) {
            if(v==fa) continue;
            par[v]=u;
            dep[v]=dep[u]+w;
            lev[v]=lev[u]+1;
            dfs(dfs,v,u);
        }
        if(g[u].size()==1) {
            leaf.pb(u);
        }
    };
    dfs(dfs,0,-1);
    {//st_init
        REP(i,n) st[0][i]=par[i];
        REP1(i,maxb-1) {
            REP(j,n) {
                st[i][j]=st[i-1][st[i-1][j]];
            }
        }
    }
    auto lca=[&](int a,int b) {
        if(lev[a]>lev[b]) swap(a,b);
        int k=lev[b]-lev[a];
        REP(i,maxb) if(k>>i&1) b=st[i][b];
        RREP(i,maxb) {
            if(st[i][a]!=st[i][b]) {
                a=st[i][a];
                b=st[i][b];
            }
        }
        if(a!=b) a=st[0][a];
        return a;
    };
    auto lor=[&](int a,int b) {
        return lev[a]>lev[b]?a:b;
    };
    int cl=leaf.size();
    if(m>cl) {
        reverse(ALL(c));
        int xx=c.back();
        while(c.size()>cl-1) c.pop_back();
        c.pb(xx);
        reverse(ALL(c));
    }
    ope(lca(4,5))
    vector<Vi> lcas(1<<cl,Vi(cl));
    REP(i,1<<cl) {
        REP(j,cl) {
            if(i) {
                int l=i^(i&-i);
                int id=__lg(i&-i);
                lcas[i][j]=lor(lcas[l][j],lca(leaf[j],leaf[id]));
                op(i)op(j)ope(lcas[i][j])
            }
        }
    }
    oparr(leaf)oparr(c)ope(lcas[1][1])
    Vi dp(1<<cl);
    REP(r,cl) {
        Vi ndp=dp;
        REP(i,1<<cl) {
            op(r)ope(i)
            int id=r;
            REP(j,cl) {
                if(~i>>j&1) {
                    chmax(ndp[i^(1<<j)],dp[i]+c[id]*(dep[leaf[j]]-dep[lcas[i][j]]));
                } 
            }
        }
        swap(dp,ndp);
    }
    int an=*max_element(ALL(dp));
    cout<<an<<'\n';
    return 0;
}
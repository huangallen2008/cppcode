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
template<typename T1,typename T2>
pair<T1,T2> operator+(pair<T1,T2> p1,pair<T1,T2> p2) { return pair<T1,T2>(p1.f+p2.f,p1.s+p2.s); }
const int mod=998244353;
const int maxn=1e6+5;
const int maxb=20;
const int inf=1ll<<60;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
Graph g;
Vi a,in,out;
int id=1;
void dfs(int u,int fa) {
    in[u]=id++;
    for(int v:g[u]) {
        if(v==fa) continue;
        dfs(v,u);
    }
    out[u]=id++;
}
    int n;
int st[maxb][maxn];
void init_st() {
    REP(i,n) st[0][in[i]]=a[i];
    REP1(i,maxb-1) {
        REP(j,n<<1|1) {
            st[i][j]=max(st[i-1][j],st[i-1][min(j+(1<<i-1),n<<1)]) ;
        }
    }
}
int st_mx(int l,int r) {
    if(l>r) return -inf;
    op(l)ope(r)
    int lg=__lg(r-l+1);
    return max(st[lg][l],st[lg][r-(1<<lg)+1]);
}

struct BIT {
    int n;
    Vi b;
    void init(int _n) {
        n=_n;
        b=Vi(n+1);
    }
    void ud(int u,int v) {
        for(;u<=n;u+=u&-u) b[u]+=v;
    }
    int pre(int u) {
        int r=0;
        for(;u>0u;u-=u&-u) r+=b[u];
        return r;
    }
    int qu(int l,int r) {
        return pre(r)-pre(l-1);
    }
};
void solve() {
    id=1;
    cin>>n;
    g=Graph(n);
    a=in=out=Vi(n);
    REP(i,n) cin>>a[i];
    REP(i,n-1) {
        int u,v;
        cin>>u>>v,u--,v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(0,-1);
    init_st();
    Vi p(n);
    REP(i,n) p[i]=i;
    sort(ALL(p),[&](int x,int y) {
        return a[x]==a[y]?in[x]>in[y]:a[x]>a[y];
    });
    // oparr(p)oparr(in)oparr(out)
    int it=0,cnt=0;
    Vi an;
    REP(i,n) {
    ope(i)
        if(max(st_mx(0,in[i]-1),st_mx(out[i]+1,n*2))>a[i]) an.pb(i);
    }
    // REP(i,n) {
    //     int u=p[i];
    //     while(a[p[it]]>a[u]){
    //         int t=seg.qu(in[p[it]]+1,out[p[it]]-1);
    //         // bit.ud(in[p[it++]],1-t);
    //         seg.ud_a(in[p[it]]+1,out[p[it]]-1);
    //         seg.ud(in[p[it]],1-t);
    //         cnt+=1-t;
    //     }
    //     // op(i)op(bit.qu(in[u],out[u]))ope(cnt)
    //     if((cnt-seg.qu(in[u],out[u]))!=0) {
    //         // cout<<u+1<<' ';
    //         an.pb(u);
    //         // ok=1;
    //         // entr
    //         // return;
    //     }
    // }
    // sort(ALL(an));
    cout<<an.size()<<' ';
    for(int c:an) cout<<c+1<<' ';cout<<'\n';

}
signed main() {
    IOS();
    int T=1;
    cin>>T;
    while(T--) {
        solve();
    }
    return 0;
}
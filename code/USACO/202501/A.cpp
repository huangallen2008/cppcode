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
const int maxn=5;
const int maxb=64;
const int inf=1ll<<60;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
struct DSU {
    int n;
    Vi p,sz,rsz;
    int an=0;
    void init(int _n,Vi _rsz) {
        n=_n;
        p=Vi(n);
        sz=Vi(n,1);
        rsz=_rsz;
        REP(i,n) p[i]=i;
    }
    int find(int u) {
        return p[u]==u?u:p[u]=find(p[u]);
    }
    void merge(int a,int b) {
        int x=find(a),y=find(b);
        if(x==y) return;
        if(sz[x]>sz[y]) swap(x,y);
        an-=rsz[x]*(rsz[x]-1)>>1;
        an-=rsz[y]*(rsz[y]-1)>>1;
        p[x]=y;
        sz[y]+=sz[x];
        rsz[y]+=rsz[x];
        an+=rsz[y]*(rsz[y]-1)>>1;
    }
    void ud(int u,int v) {
        int x=find(u);
        an-=rsz[x]*(rsz[x]-1)>>1;
        rsz[x]+=v;
        an-=rsz[x]*(rsz[x]-1)>>1;
    }
}dsu;

signed main() {
    IOS();
    int n,m;
    cin>>n>>m;
    string ss;
    cin>>ss;
    Vi s(n);
    REP(i,n) s[i]=ss[i]=='1';
    Vi _rsz(n);
    REP(i,n) _rsz[i]=s[i]=='0';
    dsu.init(n,_rsz);
    Graph g(n);
    REP(i,m) {
        int u,v;
        cin>>u>>v,u--,v--;
        g[u].pb(v);
        g[v].pb(u);
        if(s[u]&&s[v]) {
            dsu.merge(u,v);
        }
    }
    ope(dsu.an)
    oparr(dsu.sz)oparr(dsu.rsz)
    Vi an;
    RREP(i,n) {
        if(s[i]) {
            dsu.ud(i,1);
        }else {
            for(auto v:g[i]) {
                if(s[v]||v>i) dsu.merge(i,v);
            }
        }
        an.pb(dsu.an);
    }
    reverse(ALL(an));
    for(int x:an) cout<<x<<'\n';
    return 0;
}
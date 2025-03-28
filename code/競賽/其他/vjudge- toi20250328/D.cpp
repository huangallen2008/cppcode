#include<bits/stdc++.h>
using namespace std;
// #pragma GCC optimize("Ofast,unroll-loops")
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
#define SZ(x) ((int)((x).size()))
#define SQ(x) ((x)*(x))
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
const int maxn=2e5+5;
const int maxv=1e6+5;
const int inf=1e9;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
struct DSU {
    int n;
    Vi p,v,sz;
    void init(int _n) {
        n=_n;
        p=v=Vi(n);
        sz=Vi(n,1);
        REP(i,n) p[i]=i;
    }
    int find(int u) {
        return p[u]==u?u:p[u]=find(p[u]);
    }
    void merge(int a,int b) {
        // op(a)ope(b)
        int x=find(a),y=find(b);
        if(x==y) return;
        if(sz[x]>sz[y]) swap(x,y);
        p[x]=y;
        sz[y]+=sz[x];
        v[y]+=v[x];
    }
    void addv(int u,int x) {
        v[find(u)]+=x;
    }
    int getan() {
        int an=0;
        REP(i,n) if(p[i]==i) chmax(an,v[i]);
        return an;
    }
}dsu;
#define piii pair<pii,int>
void solve(int n) {
    map<int,vector<piii>> ml,mr,mu,md;
    map<int,vector<piii>> mlb,mrb,mub,mdb;
    Vi area(n);
    struct S {
        int x1,x2,y1,y2;
    };
    vector<S> a(n);
    REP(i,n) {
        int x,y,w,h;
        cin>>x>>y>>w>>h;
        a[i]={x,x+w,y,y+h};
        area[i]=w*h;
        ml[x].pb({{y,y+h},i});
        mr[x+w].pb({{y,y+h},i});
        md[y].pb({{x,x+w},i});
        mu[y+h].pb({{x,x+w},i});
        mlb[x].pb({{y,y+h},i});
        mrb[x+w].pb({{y,y+h},i});
        mdb[y].pb({{x,x+w},i});
        mub[y+h].pb({{x,x+w},i});
    }
    dsu.init(n);
    REP(i,n) dsu.addv(i,area[i]);
    for(auto &[id,v]:ml) sort(ALL(v));
    for(auto &[id,v]:mr) sort(ALL(v));
    for(auto &[id,v]:md) sort(ALL(v));
    for(auto &[id,v]:mu) sort(ALL(v));
    for(auto &[id,v]:mlb) sort(ALL(v));
    for(auto &[id,v]:mrb) sort(ALL(v));
    for(auto &[id,v]:mdb) sort(ALL(v));
    for(auto &[id,v]:mub) sort(ALL(v));
    REP(i,n) {
        auto [x1,x2,y1,y2]=a[i];
        // op("!!!!!!")ope(i)
        {
            auto &v=mr[x1];
            int idr=lower_bound(ALL(v),piii{{y2,inf},inf})-v.begin();
            auto &v2=mrb[x1];
            int idl=lower_bound(ALL(v2),piii{{y1,-inf},-inf})-v2.begin();
            // op(1)oparr(v)op(idl)ope(idr)
            for(int j=idl;j<idr;j++) dsu.merge(i,v[j].s);
        }
        {
            auto &v=ml[x2];
            int idr=lower_bound(ALL(v),piii{{y2,inf},inf})-v.begin();
            auto &v2=mlb[x2];
            int idl=lower_bound(ALL(v2),piii{{y1,-inf},-inf})-v2.begin();
            // op(2)oparr(v)op(idl)ope(idr)
            // ope(i)
            for(int j=idl;j<idr;j++) {
                dsu.merge(i,v[j].s);
            }
            // entr
        }
        {
            auto &v=md[y1];
            int idr=lower_bound(ALL(v),piii{{x2,inf},inf})-v.begin();
            auto &v2=mdb[y1];
            int idl=lower_bound(ALL(v2),piii{{x1,-inf},-inf})-v2.begin();
            // op(3)oparr(v)op(idl)ope(idr)
            for(int j=idl;j<idr;j++) dsu.merge(i,v[j].s);
        }
        {
            auto &v=mu[y2];
            int idr=lower_bound(ALL(v),piii{{x2,inf},inf})-v.begin();
            auto &v2=mub[y2];
            int idl=lower_bound(ALL(v2),piii{{x1,-inf},-inf})-v2.begin();
            // op(4)oparr(v)op(idl)ope(idr)
            for(int j=idl;j<idr;j++) dsu.merge(i,v[j].s);
        }
    }
    cout<<dsu.getan()<<'\n';
    // ope("ok")
}
signed main() {
    IOS();  
    int n;
    while(cin>>n) solve(n);
    return 0;
}
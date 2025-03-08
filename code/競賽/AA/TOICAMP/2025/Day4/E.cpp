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
    Vi sz,p,s;
    int n,cc,mxsz;
    void init(int _n) {
        n=_n;
        cc=mxsz=0;
        p=s=Vi(n);
        sz=Vi(n,1);
        REP(i,n) p[i]=i;
    }
    int find(int u) {
        return p[u]==u?u:p[u]=find(p[u]);
    }
    void merge(int a,int b) {
        int x=find(a),y=find(b);
        if(x==y) return;
        if(sz[x]>sz[y]) swap(x,y);
        p[x]=y;
        sz[y]+=sz[x];
        chmax(mxsz,sz[y]);
        cc--;
    }
    void set(int u) {
        if(p[u]==u&&!s[u]) {
            s[u]=1,cc++; 
            chmax(mxsz,sz[u]);
        }
    }
    int get_mxsz() { return mxsz; }
    int get_cc() { return cc; }
}dsu;
struct DSU2 {
    Vi p;
    int n;
    void init(int _n) {
        n=_n+1;
        p=Vi(n);
        // sz=Vi(n,1);
        REP(i,n) p[i]=i;
    }
    int find(int u) {
        return p[u]==u?u:p[u]=find(p[u]);
    }
    void merge(int a,int b) {
        int x=find(a),y=find(b);
        if(x==y) return;
        // if(sz[x]>sz[y]) swap(x,y);
        // sz[y]+=sz[x];
        p[x]=y;
    }
    void del(int u) {
        merge(u,u+1); 
    }
};
signed main() {
    IOS();
    int n,m,k;
    cin>>n>>m>>k;
    vector<Vi> a(n,Vi(m));
    REP(i,n) REP(j,m) cin>>a[i][j];
    vector<DSU2> ds(n);
    REP(i,n) ds[i].init(m);
    REP(i,n) REP(j,m) if(a[i][j]) ds[i].del(j);
    vector<Vpii> q(k);
    REP(i,k) {
        int r1,c1,r2,c2;
        cin>>r1>>c1>>r2>>c2,r1--,c1--,r2--,c2--;
        for(int r=r1;r<=r2;r++) {
            int t=ds[r].find(c1);
            while(t<=c2) {
                q[i].pb({r,t});
                ds[r].del(t);
                t=ds[r].find(t);
            }
        }
    } 
    dsu.init(n*m);
    auto ok=[&](int x,int y) {
        return !(x<0||x>=n||y<0||y>=m);
    };
    auto id=[&](int x,int y) { return x*m+y; };
    Vpii dir={{0,1},{0,-1},{1,0},{-1,0}};
    auto set=[&](int x,int y) {
        int i1=id(x,y);
        dsu.set(i1);
        for(auto [dx,dy]:dir) {
            int nx=x+dx,ny=y+dy;
            if(ok(nx,ny)&&dsu.s[id(nx,ny)]) {
                dsu.merge(i1,id(nx,ny));
            }
        }
    };
    REP(i,n) REP(j,m) if(ds[i].find(j)==j) set(i,j);
    int an1=dsu.get_cc(),an2=dsu.get_mxsz();
    RREP(i,k) {
        for(auto [x,y]:q[i]) set(x,y);
        an1+=dsu.get_cc();
        an2+=dsu.get_mxsz();
    }
    cout<<an1<<'\n'<<an2<<'\n';
    return 0;
}
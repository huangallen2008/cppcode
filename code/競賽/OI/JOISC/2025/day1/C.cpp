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
const int maxb=20;
const int inf=1ll<<60;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
int h,w,l;
vector<Vi> a;
struct DSU {
    int n;
    Vi p,sz,v;
    void init(int _n) {
        n=_n;
        p=v=Vi(n);
        sz=Vi(n,1);
        REP(i,n) p[i]=i;
    }
    int find(int u) {
        return p[u]==u?u:find(p[u]);
    }
    void merge(int a,int b,int w) {
        int x=find(a),y=find(b);
        if(x==y) return;
        if(sz[x]>sz[y]) swap(x,y);
        p[x]=y;
        sz[y]+=sz[x];
        v[x]=w;
    }
    int mx(int a,int b) {
        int an=0;
        while(a!=b) {
            if(sz[a]>sz[b]) swap(a,b);
            chmax(an,v[a]);
            a=p[a];
        }
        return an;
    }
}dsu;
struct DSU2 {
    int n;
    Vi p,sz;
    vector<pipii> v;
    void init(int _n,vector<pipii> _v) {
        v=_v;
        n=_n;
        p=Vi(n);
        sz=Vi(n,1);
        REP(i,n) p[i]=i;
        // op("dsu2")oparr(v)
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
        chmax(v[y],v[x]);
        // oparr(v)
    }
}dsu2;
signed main() {
    IOS();
    cin>>h>>w>>l;
    a=vector<Vi>(h,Vi(w));
    REP(i,h) REP(j,w) cin>>a[i][j];
    auto ind=[&](int x,int y) { return x*w+y; };
    // auto ind=[&](pii p) { return p.f*w+p.s; };
    auto nok=[&](int x,int y) { return x<0||y<0||x>=h||y>=w; };
    vector<pipii> v;
    vector<pipii> vv;
    REP(i,h) REP(j,w) vv.pb({a[i][j],{i,j}});
    dsu2.init(h*w,vv);
    sort(ALL(vv));
    // oparr(vv)
    Vpii dir={{0,1},{0,-1},{1,0},{-1,0}};
    dsu.init(h*w);
    REP(x,h) REP(y,w) {
        for(auto [dx,dy]:dir) {
            int nx=x+dx,ny=y+dy;
            if(nok(nx,ny)) continue;
            v.pb({max(a[x][y],a[nx][ny]),{ind(x,y),ind(nx,ny)}});
        }
    }
    sort(ALL(v));
    for(auto [w,p]:v) {
        auto [u,v]=p;
        dsu.merge(u,v,w);
    }
    int N=h*w,M=v.size();
    Vi val(N);
    REP(i,h) REP(j,w) val[ind(i,j)]=a[i][j];
    vector<Vi> st(maxb,Vi(N));
    REP(i,N) st[0][i]=i;
    // oparr(v)
    int it=0;
    REP(i,N) {
        auto upd=[&](pii p) {
            auto [x,y]=p;
            // op(x)ope(y)
            for(auto [dx,dy]:dir) {
                int nx=x+dx,ny=y+dy;
                if(nok(nx,ny)) continue;
                // op(x)op(y)op(nx)op(ny)op(a[nx][ny])ope(vv[i].f)
                if(a[nx][ny]<=a[x][y]) dsu2.merge(ind(nx,ny),ind(x,y));
            }
        };
        while(it<N&&vv[it].f<=vv[i].f+l) upd(vv[it++].s);
        auto pp=vv[i].s;
        int id=ind(pp.f,pp.s);
        auto ret=dsu2.v[dsu2.find(id)].s;
        // op(id)ope(dsu2.find(id))
        st[0][id]=ind(ret.f,ret.s);
    }
    // oparr(st[0])
    REP1(i,maxb-1) {
        REP(j,N) st[i][j]=st[i-1][st[i-1][j]];
    }
    
    int q;
    cin>>q;
    REP(i,q) {
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2,x1--,x2--,y1--,y2--;
        int mxv=dsu.mx(ind(x1,y1),ind(x2,y2));
        int an=0;
        int id1=ind(x1,y1),id2=ind(x2,y2);
        int now=id1;
        RREP(j,maxb) {
            if(val[st[j][now]]<mxv) {
                an+=1<<j;
                now=st[j][now];
            }
        }
        // op(now)op(val[now])ope(mxv)
        if(val[now]<mxv) now=st[0][now],an++;
        if(val[now]>=mxv)cout<<(an?an:1)<<'\n';
        else cout<<"-1\n";
    }
    return 0;
}
/*
1 3 1
2 4 1
1
1 1
1 3
1
*/
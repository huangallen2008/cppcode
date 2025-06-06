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
const int maxb=30;
const int inf=1ll<<60;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
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
        if(p[u]==u) return u;
        int pu=find(p[u]);
        v[u]^=v[p[u]];
        return p[u]=pu;
    }
    bool merge(int a,int b,int v0) {
        int x=find(a),y=find(b);
        if(x==y) {
            if((v[a]^v[b])!=v0) return 0;
            return 1;
        }
        if(sz[x]>sz[y]) swap(x,y);
        int val=v0^v[a]^v[b];
        p[x]=y;
        sz[y]+=sz[x];
        v[x]=val;
        return 1;
    }
    int mns(Vpii a) {
        int an=0;
        REP(i,maxb) {
            Vi c(2);
            for(auto [x,_]:a) c[x>>i&1]++;
            an^=c[1]>c[0]?(1<<i):0;
        }
        return an;
    }
    Vi getan() {
        // oparr(p)oparr(v)
        vector<Vpii> a(n);
        REP(i,n) {
            int x=find(i);
            a[x].pb({v[i],i});
        }
        // ope("ok")
        // int an=0;
        Vi an(n);
        REP(i,n) if(p[i]==i) {
            int b=mns(a[i]);
            for(auto [x,id]:a[i]) {
                an[id]=b^x;
            }
        }
        return an;
    }
}dsu;
signed main() {
    IOS();
    int n,m;
    cin>>n>>m;
    dsu.init(n);
    REP(i,m) {
        int u,v,w;
        cin>>u>>v>>w,u--,v--;
        if(!dsu.merge(u,v,w)) {
            cout<<"-1\n";
            return 0;
        }
    }
    Vi an=dsu.getan();
    REP(i,n) cout<<an[i]<<' ';
    cout<<'\n';
    return 0;
}
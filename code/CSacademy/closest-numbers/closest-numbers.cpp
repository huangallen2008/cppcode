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
const int inf=1ll<<60;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
struct Seg {
    int mn,mx,v;
};
const Seg zero={inf,-inf,inf};
Seg s[maxn]={zero};
int lc[maxn],rc[maxn];
int node_id=1;
struct SEG {
    int n;
    Vi ver;
    int cver=0;
    void pull(int w) {
        int b=lc[w],c=rc[w];
        s[w].mn=min(s[b].mn,s[c].mn);
        s[w].mx=max(s[b].mx,s[c].mx);
        s[w].v=min({s[b].v,s[c].v,s[c].mn-s[b].mx});
    }
    void build(int &w,int l,int r) { if(!w) s[w=node_id++]=zero;
        if(l==r) return;
        int m=l+r>>1;
        build(lc[w],l,m);
        build(rc[w],m+1,r);
    }
    void init(int _n) {
        n=_n;
        ver.pb(node_id++);
        build(ver.back(),0,n-1);
    }
    int _ud(int w,int l,int r,int u,int v) {
        s[w=node_id++]=s[w];
        if(l==r) {
            s[w].mn=s[w].mx=v;
            return w;
        }
        int m=l+r>>1;
        if(u<=m) _ud(lc[w],l,m,u,v);
        else _ud(rc[w],m+1,r,u,v);
        pull(w);
        return w;
    }
    void ud(int u,int v) {
        ver.pb(_ud(ver.back(),0,n-1,u,v));
    }
};
signed main() {
    IOS();

    return 0;
}
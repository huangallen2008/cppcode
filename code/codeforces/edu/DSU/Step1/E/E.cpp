#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops,fast-math")
// #pragma GCC target("avx2,bmi,popcnt")
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
#ifdef LOCAL
#define op(x) cout<<(#x)<<"="<<(x)<<", ";
#define ope(x) cout<<(#x)<<"="<<(x)<<endl;
#define oparr(x) cout<<(#x)<<":";for(auto &allen:(x)) cout<<allen<<" ";cout<<" size="<<(x).size()<<endl;
#define entr cout<<endl;
#else
#define op(x) ;
#define ope(x) ;
#define oparr(x) ;
#define entr ;
#endif
const int mod=1e9+7;
const int maxn=1e4+5;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
struct DSU {
    vector<int> p,sz,v;
    int cnt;
    void init(int n) {
        p=vector<int>(n);
        v=vector<int>(n,-1);
        sz=vector<int>(n,1);
        REP(i,n) p[i]=i;
        cnt=n;
    }
    int find(int u) {
        if(p[u]==u) return u;
        int pu=find(p[u]);
        if(v[p[u]]!=-1) v[u]=v[p[u]];
        return p[u]=pu;
    }
    void merge(int a,int b,int id) {
        int x=find(a),y=find(b);
        if(x==y) return ;
        if(sz[x]>sz[y]) swap(x,y);
        if(x==0) swap(x,y);
        p[x]=y;
        sz[y]+=sz[x];
        if(y==0) v[x]=id;
        cnt--;
    }
}dsu;
signed main() {
    IOS();
    int n,m;
    cin>>n>>m;
    dsu.init(n);
    vector<int> l(n),r(n);
    REP(i,n) cin>>l[i]>>r[i];
    vector<bool> rl(n),rr(n);
    vector<pii> a(m);
    REP(i,m) cin>>a[i].f>>a[i].s;
    REP(i,n) {
        if(l[i]==-1) rl[i]=1;
        if(r[i]==-1) rr[i]=1;
    }
    REP(i,m) {
        if(a[i].s==1) rl[a[i].f-1]=1;
        else rr[a[i].f-1]=1;
    }
    REP(i,n) {
        if(!rl[i]) dsu.merge(i,l[i]-1,-1);
        if(!rr[i]) dsu.merge(i,r[i]-1,-1);
    }
    RREP(i,m) {
        if(a[i].s==1) dsu.merge(a[i].f-1,l[a[i].f-1]-1,i);
        if(a[i].s==2) dsu.merge(a[i].f-1,r[a[i].f-1]-1,i);
    }
    REP(i,n) {
        dsu.find(i);
        cout<<dsu.v[i]<<'\n';
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
// #pragma GCC optimize("O3,unroll-loops,fast-math")
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
const int maxn=5;
const int maxv=31700;
const int inf=(1ll<<50);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
struct DSU {
    Vi p,sz,cnt,deg;
    int n,cc,an;
    void init(int _n) {
        n=_n;
        p=cnt=deg=Vi(n);
        sz=Vi(n,1);
        REP(i,n) p[i]=i;
        cc=n;
        an=0;
    }
    int val(int x) { 
        if(sz[x]==1) return 0;
        return max(cnt[x]>>1,1ll);    
    }
    int find(int u) {
        return p[u]==u?u:p[u]=find(p[u]);
    }
    void merge(int a,int b) {
        int dif=0;
        if(++deg[a]&1) dif++;else dif--;
        if(++deg[b]&1) dif++;else dif--;
        int x=find(a),y=find(b);
        if(x==y) {
            an-=val(x);
            cnt[x]+=dif;
            an+=val(x);
            return;
        }
        if(sz[x]>sz[y]) swap(x,y);
        an-=val(x)+val(y);
        p[x]=y;
        sz[y]+=sz[x];
        cnt[y]+=cnt[x];
        cnt[y]+=dif;
        an+=val(y);
    }
}dsu;
signed main() {
    IOS();
    int n,m;
    cin>>n>>m;
    dsu.init(n);
    vector<pii> a(m);
    REP(i,m) cin>>a[i].f>>a[i].s,a[i].f--,a[i].s--;
    Vi an;
    RREP(i,m) {
        auto [u,v]=a[i];
        dsu.merge(u,v);
        an.pb(dsu.an);
    }
    RREP(i,m) cout<<an[i]<<'\n';
    return 0;
}
/*
6 6
3 4
3 5
3 6
4 5
3 2
1 3

*/
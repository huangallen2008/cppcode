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
    vector<int> p,sz;
    int cnt;
    void init(int n) {
        p=vector<int>(n);
        sz=vector<int>(n,1);
        REP(i,n) p[i]=i;
        cnt=n;
    }
    int find(int u) {
        return p[u]==u?u:p[u]=find(p[u]);
    }
    void merge(int a,int b) {
        int x=find(a),y=find(b);
        if(x==y) return ;
        if(sz[x]>sz[y]) swap(x,y);
        p[x]=y;
        sz[y]+=sz[x];
        cnt--;
    }
    bool same(int a,int b) {
        return find(a)==find(b);
    }
}dsu;
struct qur {
    int t,u,v;
};
signed main() {
    IOS();
    int n,m,k;
    cin>>n>>m>>k;
    dsu.init(n);
    int x=0;
    REP(i,m<<1) cin>>x;
    vector<qur> q;
    REP(i,k) {
        string opt;
        int u,v;
        cin>>opt>>u>>v;
        u--,v--;
        if(opt[0]=='c') q.pb({0,u,v});
        else q.pb({1,u,v}); 
    }
    reverse(ALL(q));
    vector<bool> an;
    for(auto [t,u,v]:q) {
        if(t) {
            if(dsu.same(u,v)) an.pb(1);
            else an.pb(0);
        }
        else dsu.merge(u,v);
    }
    for(bool x:an) {
        if(x) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}
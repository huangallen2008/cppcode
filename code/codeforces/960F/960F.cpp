#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops,fast-math")
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
const int mod=998244353;
const int maxn=2e6+5;
const int maxv=1e5+5;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
int s[maxn];
int lc[maxn];
int rc[maxn];
int node_id=1;
struct SEG {
    int root;
    int n;
    void init(int _n) {
        n=_n;
        root=node_id++,s[root]=0;
    }
    void pull(int w) {
        s[w]=max(s[lc[w]],s[rc[w]]);
    }
    void _ud(int &w,int l,int r,int u,int v) {
        if(!w) w=node_id++,s[w]=0;
        if(l==r) {
            s[w]=max(s[w],v);
            return;
        }
        int m=l+r>>1;
        if(u<=m) _ud(lc[w],l,m,u,v);
        else _ud(rc[w],m+1,r,u,v);
        pull(w);
    }
    void ud(int u,int v) {
        _ud(root,0,n-1,u,v);
    }
    int _qu(int w,int l,int r,int ql,int qr) {
        if(!w) return 0;
        if(ql<=l&&r<=qr) return s[w];
        if(ql>r||qr<l) return 0;
        int m=l+r>>1;
        return max(_qu(lc[w],l,m,ql,qr),_qu(rc[w],m+1,r,ql,qr));
    }
    int qu(int l,int r) {
        return _qu(root,0,n-1,l,r);
    }
};
signed main() {
    IOS();
    int n,m;
    cin>>n>>m;
    vector<SEG> seg(n);
    REP(i,n) seg[i].init(maxv);
    Vi dp(n);
    REP(i,m) {
        int u,v,w;
        cin>>u>>v>>w,u--,v--;
        int r=seg[u].qu(0,w-1)+1;
        chmax(dp[v],r);
        seg[v].ud(w,r);
    }
    int an=*max_element(ALL(dp));
    cout<<an<<'\n';
    return 0;
}
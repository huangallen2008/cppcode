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
const int maxn=1e5+1;
const int maxv=1e5+1;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
struct SEG {
    int n;
    Vi s;
    void init(int _n) {
        n=_n;
        s=Vi(n<<2);
    }
    void _ud(int w,int l,int r,int u,int v) {
        if(l==r) {
            s[w]+=v;
            return;
        }
        int m=l+r>>1;
        if(u<=m) _ud(w<<1,l,m,u,v);
        else _ud(w<<1|1,m+1,r,u,v);
        s[w]=max(s[w<<1],s[w<<1|1]);
    }
    void ud(int u,int v) {
        op(u)ope(v)
        _ud(1,0,n-1,u,v);
    }
    pii _mx(int w,int l,int r) {
        if(l==r) return {s[w],l};
        int m=l+r>>1;
        if(s[w<<1]==s[w]) return _mx(w<<1,l,m);
        else return _mx(w<<1|1,m+1,r);
    }
    pii mx() {
        return _mx(1,0,n-1);
    }
    int _fir(int w,int l,int r) {
        if(l==r) return l;
        int m=l+r>>1;
        if(s[w<<1]>0) return _fir(w<<1,l,m);
        else return _fir(w<<1|1,m+1,r);
    }
    int fir() {
        return _fir(1,0,n-1);
    }
    int qu(int w,int l,int r,int u) {
        if(l==r) return s[w];
        int m=l+r>>1;
        if(u<=m) return qu(w<<1,l,m,u);
        else return qu(w<<1|1,m+1,r,u);
    }
}seg;
signed main() {
    IOS(); 
    int n;
    cin>>n;
    seg.init(maxv);
    REP(i,n) {
        int x;
        cin>>x;
        seg.ud(x,1);
    }
    if(seg.mx().f>(n+1>>1)) {
        cout<<"-1\n";
        return 0;
    }
    Vi an;
    REP(i,n) {
        pii ret=seg.mx();
        if(ret.f>(n-i>>1)) {
            an.pb(ret.f);
            seg.ud(ret.f,-1);
            op(ret.f)ope(seg.qu(1,0,n-1,ret.f))
        }
        else {
            int t=seg.fir();
            an.pb(t);
            seg.ud(t,-1);
            op(t)ope(seg.qu(1,0,n-1,t))
        }
    }
    for(int x:an) cout<<x<<' ';
    cout<<'\n';
    return 0;
}
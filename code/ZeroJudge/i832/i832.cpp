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
const int maxn=2e5+5;
const int maxnl=5e6+5;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
struct SEG {
    int lc[maxnl],rc[maxnl],s[maxnl],vers[maxn];
    int n,nid=1;
    void pull(int w) {
        s[w]=min(s[lc[w]],s[rc[w]]);
    }
    int ud(int w,int l,int r,int u,int v) {
        int nn=nid++;
        assert(nid<maxnl);
        if(w==-1) w=nn;
        lc[nn]=lc[w],rc[nn]=rc[w],s[nn]=0;
        if(l==r) {
            s[nn]=v;
            return nn;
        }
        int m=l+r>>1;
        if(u<=m) lc[nn]=ud(lc[w],l,m,u,v);
        else rc[nn]=ud(rc[w],m+1,r,u,v);
        pull(nn);
        return nn;
    }
    void init(int _n,vector<int>&a) {
        n=_n+1;
        memset(lc,-1,sizeof(lc));
        memset(rc,-1,sizeof(lc));
        vers[0]=0;
        REP1(i,_n) {
            if(a[i]<n) vers[i]=ud(vers[i-1],0,_n,a[i],i);
            else vers[i]=vers[i-1];
        }
    }
    int _qu(int w,int l,int r,int k) {
        if(w==-1||lc[w]==-1||l==r) return l;
        int m=l+r>>1;
        if(s[lc[w]]<k) return _qu(lc[w],l,m,k);
        else return _qu(rc[w],m+1,r,k);
    }
    int qu(int l,int r) {
        return _qu(vers[r],0,n-1,l);
    }
}seg;
signed main() {
    IOS();
    int n,q;
    cin>>n>>q;
    vector<int> a(n+1);
    REP1(i,n) cin>>a[i];
    seg.init(n,a);
    int ans=0;
    REP(i,q) {
        int l,r;
        cin>>l>>r;
        l^=ans,r^=ans;
        ans=seg.qu(l,r);
        cout<<ans<<'\n';
    }
    return 0;
}
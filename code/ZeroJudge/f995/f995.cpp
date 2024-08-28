#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops,fast-math")
// #pragma GCC target("avx2,popcnt")
#define int long long
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
#define RREP(i,n) for(int i=(n)-1;i>=0;i--)
#define RREP1(i,n) for(int i=(n);i>=1;i--)
#define f first
#define s second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)(x.size())
#define SQ(x) (x)*(x)
#define pii pair<int,int>
#define pipii pair<int,pii>
#define Graph vector<vector<int>>
#define IOS() ios::sync_with_stdio(0),cin.tie(0)
#define md(x) (((x)%(mod)+(mod))%(mod))
#define MD(x,M) (((x)%(M)+(M))%(M))
#define ld long double
#define pdd pair<ld,ld>
#ifdef LOCAL
#define op(x) cout<<(#x)<<"="<<(x)<<", ";
#define ope(x) cout<<(#x)<<"="<<(x)<<endl;
#define oparr(x) cout<<(#x)<<":";REP(allen,(x).size()) cout<<x[allen]<<" ";cout<<" size="<<(x).size()<<endl;
#define entr cout<<endl;
#else
#define op(x) ;
#define ope(x) ;
#define oparr(x) ;
#define entr ;
#endif
const int mod=1e9+7;
const int maxn=7e6;
const int maxn2=3e5;
const int maxv=1e3+5;
const int maxs=1e6;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
struct line {
    int m,k;
    bool operator==(const line x) { return x.m==m&&x.k==k; }
};
const line zr={0,-inf};
int node_id=0;
line s[maxn];
int lc[maxn],rc[maxn];
struct LCSEG {
    int cal(line l,int x) {
        return l.m*x+l.k;
    }
    line mxl(line &a,line &b,int x) {
        if(cal(a,x)>cal(b,x)) return a;
        else return b;
    }
    int root;
    void init() {
        s[root=node_id++]=zr;
    }
    void _ud(int &id,int l,int r,line &v) {
        if(v==zr) return;
        if(id==-1) s[id=node_id++]=zr,assert(node_id<maxn);
        if(l==r) {
            s[id]=mxl(s[id],v,l);
            return;
        }
        int m=l+r>>1;
        if(v.m>s[id].m) swap(v,s[id]);
        if(cal(v,m)<cal(s[id],m)) {
            _ud(lc[id],l,m,v);
        }
        else {
            swap(s[id],v);
            _ud(rc[id],m+1,r,v);
        }
    }
    void ud(int l,int r,line v) {
        _ud(root,l,r,v);
    }
    int _qu(int id,int l,int r,int x) {
        if(id==-1) return -inf;
        int an=cal(s[id],x);
        if(l==r) return an;
        int m=l+r>>1;
        if(x<=m) {
            return max(an,_qu(lc[id],l,m,x));
        }
        else {
            return max(an,_qu(rc[id],m+1,r,x));
        }
    }
    int qu(int l,int r,int x) { return _qu(root,l,r,x); }
};
struct SEG_lcseg {
    LCSEG s[maxn2<<2];
    int n;
    void init(int _n) {
        n=_n;
        REP(i,n<<2) s[i].init();
    }
    void _ud(int w,int l,int r,int u,line v) {
        s[w].ud(-maxv,maxv,v);
        if(l==r) return;
        int m=l+r>>1;
        if(u<=m) _ud(w<<1,l,m,u,v);
        else _ud(w<<1|1,m+1,r,u,v);
    }
    void ud(int u,line v) {
        _ud(1,0,n-1,u,v);
    }
    int _qu(int w,int l,int r,int ql,int qr,int x) {
//        op(w)op(l)op(r)op(ql)op(qr)ope(x)
        if(ql<=l&&r<=qr) return s[w].qu(-maxv,maxv,x);
        if(ql>r||qr<l) return -inf;
        int m=l+r>>1;
        return max(_qu(w<<1,l,m,ql,qr,x),_qu(w<<1|1,m+1,r,ql,qr,x));
    }
    int qu(int l,int r,int x) {
        return _qu(1,0,n-1,l,r,x);
    }
} seg_lct;
int solve(int n,int k,vector<int> &pa,vector<int> &pla,vector<int> &b) {
    vector<int> dp(n+1);
    seg_lct.init(n+1);
    seg_lct.ud(0,{0,0});
    REP1(i,n) {
        dp[i]=pla[i]+seg_lct.qu(max(i-k,0ll),i-1,pa[i]);
        // op(max(i-k,(int)0))op(i-1)op(pa[i])ope(dp[i])
        seg_lct.ud(i,{b[i]-i,dp[i]-pa[i]*(b[i]-i)-pla[i]});
        // op(i)op(b[i]-i)ope(dp[i]-pa[i]*(b[i]-i)-pla[i])
    }
    // oparr(dp)
    return dp[n];
}
signed main() {
    IOS();    
    memset(lc,-1,sizeof(lc));
    memset(rc,-1,sizeof(rc));
    int n,k;
    cin>>n>>k;
    vector<int> a(n+1),b(n+1),pa(n+1),pla(n+1);
    REP1(i,n) cin>>a[i];
    REP1(i,n) cin>>b[i];
    REP1(i,n) {
        pa[i]=pa[i-1]+a[i];
        pla[i]=pla[i-1]+a[i]*i;
    }
    cout<<solve(n,k,pa,pla,b)<<'\n';;
    return 0;
}

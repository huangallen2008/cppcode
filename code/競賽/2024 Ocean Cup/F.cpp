#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops,fast-math")
#pragma GCC target("avx2,bmi,popcnt")
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
#define oparr(x) cout<<(#x)<<":";REP(allen,(x).size()) cout<<x[allen]<<" ";cout<<" size="<<(x).size()<<endl;
#define entr cout<<endl;
#else
#define op(x) ;
#define ope(x) ;
#define oparr(x) ;
#define entr ;
#endif
const int mod=998244353;
const int maxn=2e5+5;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
int pw(int x,int p) {
    int r=1;
    while(p>0) {
        if(p&1) {
            r*=x;
            r%=mod;
        }
        x*=x;
        x%=mod;
        p>>=1;
    }
    return r;
}
int inv(int x) {
    return pw(x,mod-2);
}
int fmod(int q,int p) {// q/p
    return (q*inv(p))%mod;
}
set<int> s0;
struct BIT{
    vector<int> a,b;
    int n;
    void init(int _n) {
        n=_n;
        b=vector<int>(n+1,1);
        a=vector<int>(n+1,1);
    }
    void ud(int u,int v) {
        for(;u<=n;u+=u&-u) b[u]=(b[u]*v)%mod;
    }
    int qu_pre(int u) {
        int r=1;
        for(;u>0;u-=u&-u) r=(r*b[u])%mod;
        return r;
    }
    int qu(int l,int r) {
        return (qu_pre(r)*inv(qu_pre(l-1)))%mod;
    }
}bit;
int n,m,now;
int val(int x) {
    return ((m-x-1)*inv(m-x))%mod;
}
int ival(int x) {
    return ((m-x)*inv(m-x-1))%mod;
}
int tran(int x) {
    return md(1-x);
}
signed main() {
    IOS();
    int cntm=0;
    cin>>n>>m>>now;
    vector<int> h(n);
    REP(i,n) cin>>h[i];
    bit.init(m+1);
    REP(i,n) {
        if(h[i]!=m-1) bit.ud(h[i],val(h[i]));
        else cntm++;
    }
    int q;
    cin>>q;
    while(q--) {
        // REP1(i,m) cout<<bit.b[i]<<' ';entr
        int opt;
        cin>>opt;
        if(opt==1) {
            int x,y;
            cin>>x>>y;
            x--;
            if(h[x]!=m-1) bit.ud(h[x],ival(h[x]));
            else cntm--;
            h[x]=y;
            if(y!=m-1) bit.ud(h[x],val(h[x]));
            else cntm++;
        }
        else {
            int p;
            cin>>p;
            now=p;
        }
        if(now==m&&cntm) cout<<1<<'\n';
        else cout<<tran(bit.qu_pre(now-1))<<'\n';
    }
    return 0;
}
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
struct BIT {
    vector<int> b;
    int n;
    void init(int _n) {
        n=_n;
        b=vector<int>(n+1);
    }
    void ud(int u,int v) {
        if(u&1) v=-v;
        for(;u<=n;u+=u&-u) b[u]+=v;
    }
    int qu(int u) {
        int r=0;
        for(;u>0;u-=u&-u) r+=b[u];
        return r;
    }
}bit;
signed main() {
    IOS();
    int n,q;
    cin>>n;
    bit.init(n);
    vector<int> a(n+1);
    REP1(i,n) cin>>a[i];
    cin>>q;
    REP(i,q) {
        int opt;
        cin>>opt;
        if(opt==1) {
            int u,v;
            cin>>u>>v;
            u++;
            bit.ud(u,v-a[u]);
            a[u]=v;
        }
        else {
            int l,r;
            cin>>l>>r;
            l++,r++;
            int ret=bit.qu(r)-bit.qu(l-1);
            if(l&1) ret=-ret;
            cout<<ret<<'\n';
        }
    }
    return 0;
}
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
const int mod=1e9+21;
const int maxn=5;
const int maxc=29;
const int inf=(1ll<<50);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
Vi po;
int toi(char c) { return c-'a'+1; }
struct BIT {
    Vi b;
    int n;
    string s;
    void _ud(int u,int v) {
        for(;u<=n;u+=u&-u) b[u]=(b[u]+v)%mod;
    }
    void init(int _n,string &_s) {
        s=_s;
        n=_n;
        b=Vi(n+1);
        REP1(i,n) {
            _ud(i,po[i]*toi(s[i])%mod);
        }
    }
    void ud(int u,char c) {
        _ud(u,po[u]*(toi(c)-toi(s[u]))%mod);
        s[u]=c;
    }
    int _qu(int u){
        int r=0;
        for(;u>0;u-=u&-u) {
            addmod(r,b[u]);
        }
        return r;
    }
    pii qu(int l,int r) {
        int ret=_qu(r)-_qu(l-1);
        ret=(ret%mod+mod)%mod;
        return {ret,l};
    }
}hbit1,hbit2;
bool cmp(pii a,pii b) {
    if(a.s>b.s) swap(a,b);
    return a.f*po[b.s-a.s]%mod==b.f;
}
signed main() {
    po=Vi(n+1);
    po[0]=1;
    REP1(i,n) po[i]=po[i-1]*maxc%mod;
    IOS(); 
    int n,m;
    cin>>n>>m;
    string str;
    cin>>str;
    str="$"+str+"$";
    hbit1.init(n,str);
    reverse(ALL(str));
    hbit2.init(n,str);
    auto upd1=[&](int u,char c) {
        hbit1.ud(u,c);
    };
    auto upd2=[&](int u,char c) {
        hbit2.ud(n+1-u,c);
    };
    auto upd=[&](int u,char c) {
        upd1(u,c);
        upd2(u,c);
    };
    auto qur1=[&](int l,int r) {
        return hbit1.qu(l,r);
    };
    auto qur2=[&](int l,int r) {
        return hbit2.qu(n+1-r,n+1-l);
    };
    auto com=[&](int l,int r) {
        return cmp(qur1(l,r),qur2(l,r));
    };
    REP(i,m) {
        int opt;   
        cin>>opt;
        if(opt==1) {
            int u;
            char c;
            cin>>u>>c;
            upd1(u,c);
        }
    }
    return 0;
}
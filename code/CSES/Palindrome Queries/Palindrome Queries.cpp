#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast,unroll-loops,fast-math")
#pragma GCC target("avx2,sse4,bmi2,popcnt")
// #define int long long
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
#define ull unsigned long long
#define Vull vector<ull>
#define pui pair<ull,int>
vector<ull> po;
int toi(char c) { return c-'a'+1; }
struct BIT {
    vector<ull> b;
    int n;
    string s;
    void _ud(int u,ull v) {
        for(;u<=n;u+=u&-u) b[u]+=v;
    }
    void init(int _n,string &_s) {
        s=_s;
        n=_n;
        b=Vull(n+1);
        REP1(i,n) {
            _ud(i,po[i]*toi(s[i]));
        }
    }
    void ud(int u,char c) {
        _ud(u,po[u]*(toi(c)-toi(s[u])));
        s[u]=c;
    }
    ull _qu(int u){
        ull r=0;
        for(;u>0;u-=u&-u) {
            r+=b[u];
        }
        return r;
    }
    ull qu(int l,int r) {
        return (_qu(r)-_qu(l-1))*po[n-l];
    }
}hbit1,hbit2;
signed main() {
    IOS(); 
    int n,m;
    cin>>n>>m;
    po=vector<ull>(n+1);
    po[0]=1;
    REP1(i,n) po[i]=po[i-1]*maxc;
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
        return qur1(l,r)==qur2(l,r);
    };
    REP(i,m) {
        int opt;   
        cin>>opt;
        if(opt==1) {
            int u;
            char c;
            cin>>u>>c;
            upd(u,c);
        }
        else {
            int l,r;
            cin>>l>>r;
            if(com(l,r)) {
                cout<<"YES\n";
            }
            else cout<<"NO\n";
        }
    }
    return 0;
}
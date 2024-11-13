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
const int maxn=2000+5;
const int maxb=20;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
int n,T;
vector<bitset<maxn>> bas;
bool ins(bitset<maxn> x) {
    REP(i,n) {
        REP(j,n) cout<<bas[i][j];cout<<'\n';
    }entr
    if(x==0) return 0;
    REP(i,n) {
        if(bas[i]==0) {
            bas[i]=x;
            return 1;
        }
        x^=bas[i];
        if(x==0) return 0;
    }
    return 0;
}
signed main() {
    IOS(); 
    cin>>n>>T;
    bas=vector<bitset<maxn>>(n);
    vector<bitset<maxn>> a(n);
    REP(i,n) {
        REP(j,n) {
            char tt;
            cin>>tt;
            a[i][j]=tt-'0';
        }
    }
    Vi ok(n);
    REP(i,n) ok[i]=ins(a[i]);
    Vi nok;
    REP(i,n) if(bas[i]==0) nok.pb(i);
    int cnt=0;
    oparr(ok)oparr(nok)
    REP(i,n) if(!ok[i]) {
        // op(i)
        // int x=nok[cnt++];
        // a[i][x]=a[i][x]^1;
        a[i].flip(nok[cnt++]);
    }
    if(T==1) {
        cout<<nok.size()<<'\n';
    }
    else {
        REP(i,n) {
            REP(j,n) cout<<a[i][j];
            cout<<'\n';
        }
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O0,unroll-loops,fast-math")
// #pragma GCC target("avx2,bmi,popcnt")
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
// const int mod=1e9+7;
// const int maxn=2e5+5;
// const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}

const int mod=1004535809;

// const int maxn=2000;
// const int k=10;
// __int128 d[maxn+1][maxn*k+1];
// __int128 dp(int u,int r) {
//     if(u<=r) return d[u][r]=1;
//     if(d[u][r]) return d[u][r];
//     __int128 ret=1;
//     for(int i=0;i<r;i++) ret+=dp(u-i,(r-i)*k);
//     return d[u][r]=ret;
// }
void out(__int128 x) {
    if(x==0) {cout<<0<<'\n';return;}
    string s;
    while(x) {
        s+='0'+x%10;
        x/=10;
    }
    reverse(ALL(s));
    cout<<s<<'\n';
}
void out(auto x) {
    cout<<x<<'\n';
}
pii mc(int x,int y,int k) {
    bool inv=x<y;
    if(inv) swap(x,y);
    if(x==1) return {k,0};
    int t=x/y,z=x-t*y;
    pii ret=mc(y,z,k);
    ret.s-=ret.f*t;
    if(inv) swap(ret.s,ret.f);
    return ret;
}
signed main() {
    IOS();
    pii ret=mc(37,107,1);
    cout<<ret.f<<' '<<ret.s<<'\n';
    return 0;
}
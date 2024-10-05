#include<bits/stdc++.h>
#include "lib2382.h"
using namespace std;
// #pragma GCC optimize("O3,unroll-loops,fast-math")
// #pragma GCC target("avx2,sse4,bmi,popcnt")
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
const int mod=1e9+7;
const int maxn=5;
const int maxv=31700;
const int inf=(1ll<<50);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
signed main() {
    IOS();
    int n=Init();
    Vi r(n),t(n);
    Vi ii(n);
    REP(i,n) ii[i]=i;
    shuffle(ALL(ii),rng);
    t[0]=-1;
    int mx=0;
    for(int i=1;i<n;i++) {
        // int i=ii[_i];
        int ret=Ask(ii[mx],ii[mx],ii[i]);
        r[i]=ret;
        t[i]=mx;
        if(ret==0) mx=i;
    }
    Vi a(n);
    a[ii[mx]]=n-1;
    int id=mx,nid=n;
    while(1) {
        for(int i=id+1;i<nid;i++) a[ii[i]]=r[i]^a[ii[id]];
        if(t[id]<0) break;
        a[ii[t[id]]]=Ask(ii[id],ii[id],ii[t[id]])^a[ii[id]];
        nid=id,id=t[id]; 
    }
    // REP(i,n) {
    //     if(i==mx) continue;
    //     int ret=Ask(mx,mx,i);
    //     a[i]=ret^(n-1);
    // }
    Answer(a);
    return 0;
}
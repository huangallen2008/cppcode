#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops,fast-math")
#pragma GCC target("avx2,sse4,bmi,popcnt")
// #define int long long
#define ll long long
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
const int maxn=1e5+5;
const int maxc=512;
const ll inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
// int dp[maxc<<1][maxc][maxc];
signed main() {
    IOS();
    int n,k,c;
    cin>>n>>k>>c;
    vector<pii> a(n);
    vector<int> b[maxc];
    REP(i,n) cin>>a[i].f>>a[i].s,b[a[i].f].pb(a[i].s);
    int cntc=0;
    REP(i,maxc) if(b[i].size()) cntc++;
    REP(i,maxc) sort(ALL(b[i]));
    vector<pipii> all;all.reserve(n);
    REP(i,maxc) for(int j=1;j<b[i].size();j++) {
        all.pb({b[i][j]+b[i][j-1],{b[i][j],i}});
    }
    sort(ALL(all),greater<pipii>());
    ll basei=0,basea=0;
    int ncc=max(0,k-cntc);
    int inc=k-ncc;
    vector<pii> cl;cl.reserve(inc+cntc);
    REP(i,ncc) {
        basei^=all[i].s.s;
        basea+=all[i].s.f;
        b[all[i].s.s].pop_back();
    }
    for(int i=ncc;i<ncc+inc&&i<all.size();i++) {
        cl.pb(all[i].s);
        b[all[i].s.s].pop_back();
    }
    REP(i,maxc) {
        if(b[i].size()) {
            cl.pb({b[i].back(),i});
            // b[i].pop_back();
        }
        // if(b[i].size()) {
        //     cl.pb({b[i].back(),i});
        // }
    }
    vector<vector<ll>> dp(inc+1,vector<ll>(maxc,-inf));
    dp[0][0]=0;
    dp[1][cl[0].s]=cl[0].f;
    REP1(i,SZ(cl)-1) {
        vector<vector<ll>> ndp=dp;
        REP(j,inc+1) {
            REP(k,maxc) {
                if(j) chmax(ndp[j][k],dp[j-1][k^cl[i].s]+cl[i].f);
            }
        }
        dp.swap(ndp);
    }
    REP(i,c+1) {
        ll an=basea+dp[inc][i^basei];
        if(an<0) cout<<"-1 ";
        else cout<<an<<' ';
    }
    cout<<'\n';
    return 0;
}
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
signed main() {
    IOS();
    int n,e,t;
    cin>>n>>e>>t;
    vector<int> x(n+1),l(n+1);
    REP(i,n) cin>>x[i]; x[n]=e;
    REP(i,n) l[n-i]=max(n-(upper_bound(ALL(x),x[i]+(t>>1))-x.begin()),0ll);
    vector<int> a=x;
    reverse(ALL(a));
    vector<int> dp(n+1);
    vector<int> v(n+1);
    dp[0]=0;
    v[0]=dp[0]+2*a[1]+a[0];
    REP1(i,n) {
        dp[i]=dp[l[i]]+max((a[l[i]+1]-a[i])*2,t)+a[l[i]]-a[i];
        if(l[i]>0) chmin(dp[i],v[l[i]-1]-a[i]*3);
        if(i<n) v[i]=min(v[i-1],dp[i]+2*a[i+1]+a[i]);
    }
    cout<<dp[n]+a[n]<<'\n';
    return 0;
}
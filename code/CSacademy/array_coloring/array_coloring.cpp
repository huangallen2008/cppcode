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
const int mod=998244353;
const int maxn=1e7+5;
const int maxb=20;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
int n,m;
Vi a,las,nxt;
int f(int l,int r) {
    if(l>r) return 0;
    if(l==r) return 1;
    int mx=0;
    int t=l;
    int cnt=0;
    while(t<=r) {
        if(nxt[t]!=n) {
            chmax(mx,f(t+1,nxt[t]-1));
            t=nxt[t];
        }
        else {
            t++;
            cnt++;
        }
    }
    return mx+cnt;
}
signed main() {
    IOS(); 
    cin>>n>>m;
    a=nxt=Vi(n);
    las=Vi(m,n);
    REP(i,n) cin>>a[i],a[i]--;
    RREP(i,n) {
        nxt[i]=las[a[i]];
        las[a[i]]=i;
    }
    int cnt0=0;
    REP(i,m) if(las[i]==n) cnt0++;
    cout<<f(0,n-1)+cnt0<<'\n';
    return 0;
}
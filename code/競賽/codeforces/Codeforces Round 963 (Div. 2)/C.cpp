#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops,fast-math")
// #pragma GCC target("avx2,bmi,popcnt")
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
const int maxn=2e5+5;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
void solve() {
    int n,k;
    cin>>n>>k;
    int K=k<<1;
    vector<int> a(n);
    REP(i,n) cin>>a[i];
    vector<int> p(K+1);
    int mx=0;
    REP(i,n) {
        int nv=a[i]%K;
        int l=(nv+k)%K,r=(nv)%K;
        if(l>=r) {
            p[l]++,p[K]--;
            p[0]++,p[r%K]--;
        }
        else {
            p[l]++,p[r]--;
        }
        chmax(mx,a[i]);
    }
    int r=mx%K;
    int an=inf;
    REP1(i,K-1) p[i]+=p[i-1];
    REP(i,K) {
        if(p[i])continue;
        if(i>=r) chmin(an,mx+i-r);
        else chmin(an,mx+K+i-r);
    }
    if(an==inf) cout<<"-1\n";
    else cout<<an<<'\n';
}
signed main() {
    IOS();
    int T=1;
    cin>>T;
    while(T--) 
    solve();
    return 0;
}
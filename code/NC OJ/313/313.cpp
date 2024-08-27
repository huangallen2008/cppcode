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
const int maxn=1e4+5;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
signed main() {
    IOS();
    int n;
    cin>>n;
    vector<vector<bool>> a(n,vector<bool>(n));
    vector<vector<int>> c(n,vector<int>(n));
    REP(i,n) {
        REP(j,n) {
            char c;
            cin>>c;
            if(c=='.') a[i][j]=1;
        }
    }
    REP(i,n) c[0][i]=a[0][i];
    REP1(i,n-1) {
        REP(j,n) {
            if(a[i][j]) c[i][j]=c[i-1][j]+1;
        }
    }
    int an=0;
    for(auto &v:c) {
        int r=0;
        vector<pii> stk;
        stk.pb({-1,-1});
        int t=0;
        REP(i,n) {
            while(stk.back().f>=v[i]) {
                t-=(stk[stk.size()-1].s-stk[stk.size()-2].s)*(stk.back().f-v[i]);
                stk.pop_back();
            }
            t+=v[i];
            r+=t;
            stk.pb({v[i],i});
        }
        an+=r;
    }
    cout<<an<<'\n';
    return 0;
}
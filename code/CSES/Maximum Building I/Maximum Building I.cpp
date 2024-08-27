#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops,fast-math")
#pragma GCC target("avx2,bmi,popcnt")
// #define int long long
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
#define RREP(i,n) for(int i=(n)-1;i>=0;i--)
#define RREP1(i,n) for(int i=(n);i>=1;i--)
#define f first
#define s second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)(x.size())
#define SQ(x) (x)*(x)
#define pii pair<int,int>
#define pipii pair<int,pii>
#define Graph vector<vector<int>>
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
#define oparr(x) cout<<(#x)<<":";REP(allen,(x).size()) cout<<x[allen]<<" ";cout<<" size="<<(x).size()<<endl;
#define entr cout<<endl;
#else
#define op(x) ;
#define ope(x) ;
#define oparr(x) ;
#define entr ;
#endif
const int mod=1e9+7;
const int maxn=1e3+5;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
signed main() {
    IOS();
    int n,m;
    cin>>n>>m;
    vector<vector<int>> a(n+1,vector<int>(m+1));
    REP1(i,n) {
        REP1(j,m) {
            char c;
            cin>>c;
            if(c=='.') a[i][j]=1;
        }
    } 
    REP1(i,n) {
        REP1(j,m) {
            if(a[i][j]) a[i][j]+=a[i-1][j];
        }
    }
    int an=0;
    REP1(rr,n) {
        auto &v=a[rr];
        vector<int> pre(m+1),nxt(m+1);
        vector<pii> stk;
        stk.pb({-1,0});
        REP1(i,m) {
            while(stk.back().f>=v[i]) {
                stk.pop_back();
            }
            pre[i]=stk.back().s;
            stk.pb({v[i],i});
        }
        stk={{-1,m+1}};
        RREP1(i,m) {
            while(stk.size()&&stk.back().f>=v[i]) {
                stk.pop_back();
            }
            nxt[i]=stk.back().s;
            stk.pb({v[i],i});
        }
        REP1(i,m) chmax(an,v[i]*(nxt[i]-pre[i]-1));
    }
    cout<<an<<'\n';
    return 0;
}
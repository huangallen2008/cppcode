#include<bits/stdc++.h>
using namespace std;
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
// #define addmod(x,y) x=((x+(y))%mod)
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
const int mod=998244353;
const int maxn=20+1;
const int maxn2=1100000;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
void addmod(int &a,int b) {
    a+=b;
    if(a>=mod) a-=mod;
}
int a[maxn][maxn],id[maxn][maxn];
signed main() {
    IOS();
    int n,m;
    cin>>n>>m;
    REP(i,n) {
        REP(j,m) {
            cin>>a[i][j],a[i][j]--;
            id[a[i][j]][i]=j;
        }
    }
    int all=(1<<m)-1;
    vector<int> dp(1<<n);
    REP(i,n) {
        REP(j,m) {
            vector<int> ndp(1<<m);
            REP(k,1<<m) {
                if(i==0&&j==0&&k==0) {
                    ndp[k]=1;
                    continue;
                }
                if(j==0) {
                    int ni=all;
                    REP(l,m) if((k>>l)&1) ni^=(1<<id[a[i][l]][i-1]);
                    ndp[k]=dp[ni];
                }
                else {
                    ndp[k]=dp[k];
                    if(((k>>j-1)&3) == 3) addmod(ndp[k],dp[k^(1<<j)^(1<<j-1)]);
                }
            }
            dp.swap(ndp);
        }
    }
    int an=dp[all];
    cout<<an<<'\n';
    return 0;
}
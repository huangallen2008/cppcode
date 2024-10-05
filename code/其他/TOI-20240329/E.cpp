#include<bits/stdc++.h>
using namespace std;
//#pragma GCC optimize("O3,unroll-loops,fast-math")
//#pragma GCC target("avx2,popcnt")
#define int long long
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
const int maxn=255;
const int maxv=1e3+5;
const int maxs=1e6;
const int inf=(1ll<<60);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
bool so(pii a,pii b) {
    if(a.f==b.f) return a.s>b.s;
    return a.f<b.f;
}
void solve() {
    int n,k;
    while(cin>>n>>k) {
        if(n==0&&k==0) break;
        vector<vector<int>> dp1(n+1,vector<int>(k+1)),dp2(n+1,vector<int>(k+1));
        dp1[0][0]=1,dp2[0][0]=1;
        int n1=(n+1)>>1,n2=n>>1;
        vector<int> a(n1+1),b(n2+1);
        REP(i,n1) a[i]=i|1;
        if(n&1) {
            REP(i,n2) b[i]=2+(i&~1);
        }
        else {
            REP(i,n2) b[i]=i|1;
        }
        reverse(ALL(a));
        reverse(ALL(b));
        REP1(i,n1) {
            dp1[i][0]=1;
            REP1(j,k) {
                dp1[i][j]=(a[i]-(k-j))*dp1[i-1][j-1]+dp1[i-1][j];
            }
        }
        REP1(i,n2) {
            dp2[i][0]=1;
            REP1(j,k) {
                dp2[i][j]=(b[i]-(k-j))*dp2[i-1][j-1]+dp2[i-1][j];
            }
        }
        int an=0;
        REP(i,k) {
            an+=dp1[n][i]*dp2[n][k-i];
        }
        cout<<an<<'\n';
    }
}
signed main() {
    IOS();
    solve();
    return 0;
}

#include<bits/stdc++.h>
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
const int maxn=500+5;
const int maxb=10;
const int inf=(1ll<<50);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
int st[maxb][maxb][maxn][maxn];
int n,m;
void init() {
    REP(i,maxb) {
        REP(j,maxb) {
            if(i==0&&j==0) continue;
            REP(k,n) {
                REP(l,m) {
                    if(i>0) st[i][j][k][l]=max(st[i-1][j][k][l],st[i-1][j][min(n-1,k+(1<<i-1))][l]);
                    else st[i][j][k][l]=max(st[i][j-1][k][l],st[i][j-1][k][min(m-1,l+(1<<j-1))]);
                }
            }
        }
    }
}
int qu(int x1,int x2,int y1,int y2) {
    int lgx=__lg(x2-x1+1),lgy=__lg(y2-y1+1);
    return max(max(st[lgx][lgy][x1][y1],st[lgx][lgy][x2-(1<<lgx)+1][y1]),max(st[lgx][lgy][x1][y2-(1<<lgy)+1],st[lgx][lgy][x2-(1<<lgx)+1][y2-(1<<lgy)+1]));
}
signed main() {
    IOS();
    cin>>n>>m;
    REP(i,n) REP(j,m) cin>>st[0][0][i][j];
    init();
    int q;
    cin>>q;
    REP(i,q) {
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2,x1--,x2--,y1--,y2--;
        cout<<qu(x1,x2,y1,y2)<<'\n';
    }
    return 0;
}
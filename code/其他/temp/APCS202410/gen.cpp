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
const int mod=1e9+7;
const int maxn=5;
const int maxb=20;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
vector<pii> dir={{0,1},{1,0},{0,-1},{-1,0}};
pii p;
int n,m,Q;
vector<Vi> a;
bool ok(pii x) {
    if(x.f<0||x.f>=n||x.s<0||x.s>=m) return 0;
    return 1;
}
pii nxt(pii x,int dd)   {
    return {x.f+dir[dd].f,x.s+dir[dd].s};
}
signed main() {
    IOS(); 
    freopen("in.txt","w",stdout);
    int n=500,m=500,q=2500;
    cout<<n<<" "<<m<<' '<<q<<'\n';
    REP(i,n) {
        REP(j,m) {
            if(i==0&&j==0) cout<<"-2 ";
            else if(/*230<=i&&i<=260&&230<=j&&j<=280*/i%17==0&&j%10==0) cout<<"30 ";
            else cout<<"0 ";
        }
        cout<<'\n';
    }
    return 0;
}
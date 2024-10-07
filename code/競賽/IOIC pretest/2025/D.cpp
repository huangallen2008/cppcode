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
const int maxv=1e9+5;
const int inf=1ll<<62;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
signed main() {
    IOS(); 
    int n,q;
    cin>>n>>q;
    string s;
    cin>>s;
    s="$"+s;
    vector<Vi> p(n+1,Vi(n+1));
    REP1(i,n-1) {
        for(int l=i,r=i+1;l>0&&r<=n;l--,r++) {
            if(s[l]!=s[r]) {
                break;
            }
            p[l][r]=1;
        }
    }
    REP1(i,n) {
        for(int l=i,r=i;l>0&&r<=n;l--,r++) {
            if(s[l]!=s[r]) break;
            p[l][r]=1;
        }
    }
    vector<Vi> dp(n+1,Vi(n+1));
    REP1(r,n) {
        RREP1(l,r) {
            if(l==r)dp[l][r]=p[l][r];
            else dp[l][r]=dp[l+1][r]+dp[l][r-1]-dp[l+1][r-1]+p[l][r];
        }
    }
    REP1(i,n)
    REP(i,q) {
        int l,r;
        cin>>l>>r;
        cout<<dp[l][r]<<'\n';
    }
    return 0;
}
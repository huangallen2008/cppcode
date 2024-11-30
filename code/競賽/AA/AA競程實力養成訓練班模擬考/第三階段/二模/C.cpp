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
const int maxn=5e5+5;
const int maxb=20;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
signed main() {
    IOS(); 
    int n,m;
    cin>>n>>m;
    if(m==1) {
        cout<<"1\n";
        return 0;
    }
    Vi a(n);
    REP(i,m) cin>>a[i],a[i]--;
    Vi c(m);
    REP(i,m) c[a[i]]++;
    oparr(c)
    REP(i,m-2) {
        if(c[i]<0) {
            cout<<"0\n";
            return 0;
        }
        int x=c[i]%3;
        c[i]-=x,c[i+1]-=x,c[i+2]-=x;
    }
    if(c[m-1]<0||c[m-2]<0||c[m-1]%3||c[m-2]%3) {
        cout<<"0\n";
        return 0;
    }
    REP(i,m) c[i]/=3;
    vector<Vi> dp(c[0]+1,Vi(c[1]+1,1));//dp[i][j] -> c[x-1]-=i,c[x]-=j
    for(int i=2;i<m;i++) {
        vector<Vi> ndp(c[i-1]+1,Vi(c[i]+1));
        REP(j,c[i-1]+1) {
            REP(k,c[i]+1) {
                for(int x=0;k+x<=c[i]&&j+x<=c[i-1]&&x<=c[i-2];x++) {
                    (ndp[j][k]+=dp[x][j+x])%mod;
                }
            }
        }
        swap(dp,ndp);
        REP(j,c[i-1]+1) {
            op(j)oparr(dp[j])
        }
        entr
    }
    int an=(dp[0][0]+mod)%mod;
    cout<<an<<'\n';
    return 0;
}
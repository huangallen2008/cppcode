#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#define int long long
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,n) FOR(i,0,n)
#define REP1(i,n) FOR(i,1,(n)+1)
#define RREP(i,n) for(int i=(n)-1;i>=0;i--)
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
#define md(x) ((x%(mod)+(mod))%(mod))
#define op(x) cout<<#x<<"="<<x<<", ";
#define ope(x) cout<<#x<<"="<<x<<endl;
#define oparr(x) cout<<#x<<":";REP(i,x.size()) cout<<x[i]<<" ";//cout<<" size="<<x.size()<<endl;
#define entr cout<<endl;
#define ld long double
const int inf=(1ll<<62);
const int maxn=1e5+5;
const int mod=1e9+7;
signed main() {
    IOS();
    int n;
    ld d;
    cin>>n>>d;
    vector<int> w(n);
    REP(i,n) cin>>w[i];
    int sum=0;
    REP(i,n) sum+=w[i];
    ld avg=(ld)sum/d;
    vector<int> val(1<<n);
    REP(i,1<<n) {
        int r=0;
        REP(j,n) if((i>>j)&1) r+=w[j];
        val[i]=r;
    }
    vector<vector<ld>> dp(d+1,vector<ld>(1<<n,(ld)inf));
    dp[0][0]=0;
    REP1(i,d) {
        REP(j,1<<n) {
            if(i==1) {
                dp[i][j]=min(dp[i][j],dp[i-1][0]+SQ(val[j]-avg));
            }
            else {
                for(int k=j;k>0;k=(k-1)&j) {
                    int dif=k^j;
                    dp[i][j]=min(dp[i][j],dp[i-1][k]+SQ(val[dif]-avg));
                }
            }
        }
    }
    cout<<fixed<<setprecision(15)<<(dp[d][(1<<n)-1]/d)<<'\n';
    return 0;
}

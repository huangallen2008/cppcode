#include<bits/stdc++.h>
using namespace std;
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
#define IOS() cin.sync_with_stdio(0),cin.tie(0),cout.tie(0)
const int inf=(1ll<<62);
const int maxn=1e6+5;
const int mod=1e9+7;
int pw(int x,int p) {
    if(p<0) return 0;
    int r=1;
    while(p>0) {
        if(p&1) {
            r*=x;
            r%=mod;
        }
        x*=x;
        x%=mod;
        p>>=1;
    }
    return r;
}
signed main() {
    IOS();
    int n;
    cin>>n;
    vector<vector<int>> dp(n,vector<int>(5));
    REP(i,n) dp[i][0]=pw(2,i+1);
    REP1(i,4) dp[0][i]=0;
    dp[0][1]=1;
    REP1(i,n-1) {
        REP1(j,4) {
            dp[i][j]=(dp[i-1][j-1]+dp[i-1][4])%mod;
        }
    }
    cout<<((pw(2,n)-dp[n-1][4])%mod+mod)%mod<<"\n";
    return 0;
}

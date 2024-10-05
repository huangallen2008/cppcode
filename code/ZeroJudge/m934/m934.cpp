#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
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
#define md(x) (((x)%(mod)+(mod))%(mod))
#define op(x) cout<<(#x)<<"="<<(x)<<", ";
#define ope(x) cout<<(#x)<<"="<<(x)<<endl;
#define oparr(x) cout<<(#x)<<":";REP(idd,(x).size()) cout<<x[idd]<<" ";cout<<endl;
#define entr cout<<endl;
const int inf=(1<<30);
const int maxn=100+5;
const int mod=1e9+7;
int a[maxn],p[maxn],dp[maxn][maxn];
signed main() {
    IOS();
    int n;
    cin>>n;
//    vector<int> a(n+1);
    REP1(i,n) cin>>a[i];
//    vector<int> p(n+1);
    REP1(i,n) p[i]=p[i-1]+a[i];
//    vector<vector<int>> dp(n+1,vector<int>(n+1,inf));
    REP1(i,n) dp[i][i]=0;
    REP1(x,n-1) {
        for(int i=1;i+x<=n;i++) {
            int j=i+x;
            dp[i][j]=inf;
            for(int k=i;k<j;k++)
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+abs(p[j]-(p[k]<<1)+p[i-1]));
        }
    }
    cout<<dp[1][n]<<'\n';
    return 0;
}

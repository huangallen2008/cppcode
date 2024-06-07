#include<bits/stdc++.h>
using namespace std;
#define ll long long
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
#define Graph vector<vector<int>>
#define IOS() cin.sync_with_stdio(0),cin.tie(0),cout.tie(0)
const int inf=(1ll<<63)-1;
const int maxn=1e5+5;
const int mod=1e9+7;
int n,k;
vector<int> a;
/*
d(i,j)=d(i-1,j-1)+d(a[i]-1,j);
*/
int d() {
    vector<vector<int>> dp(n,vector<int>(k+1,0));
    dp[0][0]=1;
    dp[0][1]=1;
    REP1(i,n-1) {
        dp[i][0]=1;
        REP1(j,k) dp[i][j]=(i>0?dp[i-1][j-1]:0)+(a[i]>0?dp[a[i]-1][j]:0);
    }
    return dp[n-1][k];
}
signed main()
{
    IOS();
    cin>>n>>k;
    a=vector<int>(n);
    REP(i,n) cin>>a[i];
    vector<int> t=a;
    sort(ALL(t));
    REP(i,n) a[i]=lower_bound(ALL(t),a[i])-t.begin();
    cout<<d()<<"\n";
    return 0;
}

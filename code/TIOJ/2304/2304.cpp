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
const int inf=(1ll<<62);
const int maxn=1e5+5;
const int mod=1e9+9;
signed main()
{
    IOS();
    int n,m;
    cin>>n>>m;
    vector<int> a(n+1),b(m+1);
    REP1(i,n) cin>>a[i];
    REP1(i,m) cin>>b[i];
    vector<vector<int>> dp(n+1,vector<int>(m+1)),d2(n+1,vector<int>(m+1));
    d2[0][0]=inf;
    REP1(i,n) {
        if(dp[i-1][0]==-1) {
            dp[i][0]=-1;
            d2[i][0]=-1;
        }
        else {
            dp[i][0]=max(dp[i-1][0]+a[i],(int)-1);
            d2[i][0]=max(d2[i-1][0],dp[i][0]);
        }
    }
    REP1(i,m) {
        if(dp[0][i-1]==-1) {
            dp[0][i]=-1;
            d2[0][i]=-1;
        }
        else {
            dp[0][i]=max(dp[0][i-1]+b[i],(int)-1);
            d2[0][i]=min(d2[0][i-1],dp[0][i]);
        }
    }
    REP1(i,n) {
        REP1(j,m) {
            int p=dp[i-1][j],q=dp[i][j-1];
            int x=max(p+a[i],(int)-1),y=max(q+b[j],(int)-1);
            if(q<0) {
                if(p<0) dp[i][j]=-1;
                else dp[i][j]=x;
            }
            else {
                if(p<0) dp[i][j]=y;
                else dp[i][j]=min(x,y);
            }
            if(dp[i][j]==-1) {
                d2[i][j]=-1;
                continue;
            }
            p=d2[i-1][j],q=d2[i][j-1];
            if(p<0) {
                if(q<0) d2[i][j]=-1;
                else d2[i][j]=q;
            }
            else {
                if(q<0) d2[i][j]=p;
                else d2[i][j]=min(p,q);
            }
            d2[i][j]=max(d2[i][j],dp[i][j]);
        }
    }
//    REP(i,n+1) {
//        REP(j,m+1) cout<<dp[i][j]<<" ";
//        cout<<endl;
//    }cout<<endl;
//    REP(i,n+1) {
//        REP(j,m+1) cout<<d2[i][j]<<" ";
//        cout<<endl;
//    }cout<<endl;
    cout<<d2[n][m]<<"\n";
    return 0;
}
/*
3 4
3 1 -4
1 -5 9 2

4 3
2 -3 4 -5
1 -5 9

10 12
6 7 2 -10 0 9 -11 0 13 18
1 4 10 -1 -10 -11 -14 11 -2 3 18 -6
*/

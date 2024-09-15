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
#define md(x) (x%mod+mod)%mod
#define Graph vector<vector<int>>
#define IOS() cin.sync_with_stdio(0),cin.tie(0),cout.tie(0)
const int inf=(1ll<<63)-1;
const int maxn=1e5+5;
const int mod=1e9+7;
vector<int> a,p;
int n,l,u;
int d() {
    vector<int> dp(n+1),pd(n+1);
    REP1(i,n) {
        int ri=prev(upper_bound(ALL(p),p[i]-l))-p.begin();
        int li=prev(lower_bound(ALL(p),p[i]-u))-p.begin();
        if(p[i]<l) dp[i]=0;
        else if(p[i]<=u) dp[i]=md(pd[ri]+1);
        else dp[i]=md(pd[ri]-pd[li]);
        pd[i]=md(pd[i-1]+dp[i]);
    }
    return md(dp[n]);
}
signed main()
{
    IOS();
    cin>>n>>l>>u;
    a=vector<int>(n+1);
    p=vector<int>(n+1);
    REP1(i,n) cin>>a[i];
    REP1(i,n) p[i]=p[i-1]+a[i];
    cout<<d()<<"\n";
    return 0;
}

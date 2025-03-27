#include<bits/stdc++.h>
using namespace std;
#define int long long
#define REP(i,n) for(int i=0;i<(n);i++)
#define Vi vector<int>
#define IOS() ios::sync_with_stdio(0),cin.tie(0)
signed main() {
    IOS();
    int n;
    cin>>n;
    vector<Vi> d(n,Vi(n));
    REP(i,n) REP(j,n) cin>>d[i][j];
    int ans=0;
    for(int i=1;i<n;i++) {
        int mn=d[0][i]*2;
        REP(j,i) mn=min(mn,d[0][i]-d[0][j]+d[i][j]);
        ans+=mn;
    }
    cout<<ans<<"\n";
    return 0;
}
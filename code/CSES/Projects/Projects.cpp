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
#define Graph vector<vector<int>>
#define IOS() cin.sync_with_stdio(0),cin.tie(0),cout.tie(0)
const int inf=(1ll<<62);
const int maxn=2e5+5;
const int mod=1e9+7;
struct P {
    int a,b,p;
};
//bool so(P a,P b) {
//    if(a.b==b.b) return a.a<b.a;
//    return a.b<b.b;
//}
void solve() {
    int n;
    cin>>n;
    vector<P> a(n);
    vector<int> t;
    REP(i,n) {
        int x,y,z;
        cin>>x>>y>>z;
        y++;
        a[i]={x,y,z};
        t.pb(x);
        t.pb(y);
    }
    vector<vector<pii>> b(n*2);
    sort(ALL(t));
    REP(i,n) {
        a[i].a=lower_bound(ALL(t),a[i].a)-t.begin();
        a[i].b=lower_bound(ALL(t),a[i].b)-t.begin();
        b[a[i].b].pb({a[i].a,a[i].p});
    }
//    sort(ALL(a),so);
//    cout<<"\n";
//    REP(i,n) cout<<a[i].a<<" "<<a[i].b<<" "<<a[i].p<<"\n";
    int an=0;
    vector<int> dp(n*2);
//    REP(i,n*2) cout<<t[i]<<" ";cout<<"\n";
    REP(i,n*2) {
        for(auto [x,y]:b[i]) dp[i]=max(dp[i],dp[x]+y);
        if(i>0) dp[i]=max(dp[i],dp[i-1]);
//        an=max(an,dp[i]);
//        cout<<dp[i]<<" ";
    }
//    cout<<"\n";
    cout<<dp[n*2-1]<<"\n";
}
signed main() {
    IOS();
    solve();
    return 0;
}

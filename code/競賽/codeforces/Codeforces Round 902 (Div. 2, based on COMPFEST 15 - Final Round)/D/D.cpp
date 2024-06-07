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
const int mod=998244353;
void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    REP(i,n) cin>>a[i];
    REP(i,n) {
        for(int j=i+1;j<=n;j+=i+1) a[i]=max(a[i],a[j-1]);
    }
    sort(ALL(a));
    vector<int> p2(n);
    p2[0]=1;
    REP1(i,n-1) p2[i]=(p2[i-1]*2)%mod;
    int an=0;
    REP(i,n) {
        an=(an+p2[i]*a[i])%mod;
    }
    cout<<an<<"\n";
}
signed main() {
    IOS();
//    int T;
//    cin>>T;
//    while(T--) {
        solve();
//    }
    return 0;
}

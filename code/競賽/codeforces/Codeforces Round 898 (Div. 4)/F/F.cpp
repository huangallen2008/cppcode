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
const int inf=(1ll<<63)-1;
const int maxn=2e5+5;
const int mod=1e9+7;
void solve() {
    int n,k;
    cin>>n>>k;
    vector<int> a(n),h(n);
    REP(i,n) cin>>a[i];
    REP(i,n) cin>>h[i];
    int an=0,r=1,x=a[n-1];
    if(a[n-1]<=k) an=1;
    RREP(i,n-1) {
        if(a[i]<=k) an=max(an,(int)1);
        if((h[i]%h[i+1]==0)) {
            while(x+a[i]>k) {
                x-=a[i+r];
                r--;
            }
            r++;
            x+=a[i];
            an=max(an,r);
        }
        else {
            r=1;
            x=a[i];
        }
    }
    cout<<an<<"\n";
}
signed main() {
    IOS();
    int T;
    cin>>T;
    while(T--) {
        solve();
    }
    return 0;
}

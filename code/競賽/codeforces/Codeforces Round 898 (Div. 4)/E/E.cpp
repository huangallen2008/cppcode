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
    int n,x;
    cin>>n>>x;
    vector<int> a(n);
    REP(i,n) cin>>a[i];
    int l=1,r=1e10,m;
    while(l<r) {
        m=(l+r+1)/2;
        int t=0;
        REP(i,n) {
            if(a[i]>m) continue;
            t+=m-a[i];
        }
        if(t>x) r=m-1;
        else l=m;
    }
    cout<<l<<"\n";
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

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
signed main() {
    IOS();
    int x,n;
    cin>>x>>n;
    vector<int> a(n);
    REP(i,n) cin>>a[i];
    sort(ALL(a));
    int id=lower_bound(ALL(a),x)-a.begin();
    if(id>(n-1)/2) cout<<id<<" "<<a[0]<<"\n";
    else cout<<n-id<<" "<<a[n-1]<<"\n";
    return 0;
}

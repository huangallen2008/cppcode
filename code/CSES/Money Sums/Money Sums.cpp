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
void solve() {
    int n;
    int s=0;
    cin>>n;
    vector<int> a(n);
    vector<bool> an(100001);
    an[0]=1;
    REP(i,n) {
        cin>>a[i];
        RREP(j,s+1) if(an[j]) an[j+a[i]]=1;
        s+=a[i];
    }
    vector<int> t;
    REP1(i,s) if(an[i]) t.pb(i);
    cout<<t.size()<<"\n";
    REP(i,t.size()) cout<<t[i]<<" ";
    cout<<"\n";
}
signed main() {
    IOS();
    solve();
    return 0;
}

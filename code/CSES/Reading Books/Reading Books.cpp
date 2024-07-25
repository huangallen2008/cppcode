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
    int n;
    cin>>n;
    int s=0,mx=0;
    REP(i,n) {
        int x;
        cin>>x;
        s+=x;
        mx=max(mx,x);
    }
    if(s-mx<mx) cout<<mx*2<<"\n";
    else cout<<s<<"\n";
}
signed main() {
    IOS();
    solve();
    return 0;
}

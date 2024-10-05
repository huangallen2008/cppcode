#include<bits/stdc++.h>
using namespace std;
#define int long double
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
    int px,py,ax,ay,bx,by;
    cin>>px>>py>>ax>>ay>>bx>>by;
    int anaa=max(SQ(ax)+SQ(ay),SQ(px-ax)+SQ(py-ay));
    int anbb=max(SQ(bx)+SQ(by),SQ(px-bx)+SQ(py-by));
    int dab=SQ(ax-bx)+SQ(ay-by);
    int anab=max(max(SQ(ax)+SQ(ay),SQ(px-bx)+SQ(py-by)),dab/4);
    int anba=max(max(SQ(bx)+SQ(by),SQ(px-ax)+SQ(py-ay)),dab/4);
    cout<<fixed<<setprecision(15)<<sqrt(min(min(anaa,anab),min(anba,anbb)))<<"\n";
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

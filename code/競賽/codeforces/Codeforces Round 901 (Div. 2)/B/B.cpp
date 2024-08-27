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
    int n,m,k;
    cin>>n>>m>>k;
    int s1=0,s2=0,mn1=inf,mx2=0,mn=inf,mx=0;;
    REP(i,n) {
        int x;
        cin>>x;
        mn1=min(mn1,x);
        mn=min(mn,x);
        mx=max(mx,x);
        s1+=x;
    }
    REP(i,m) {
        int x;
        cin>>x;
        mx2=max(mx2,x);
        mn=min(mn,x);
        mx=max(mx,x);
        s2+=x;
    }
    if(mx2>mn1) {
        s1+=mx2-mn1;
        s2-=mx2-mn1;
    }
    if(k&1) cout<<s1<<"\n";
    else cout<<s1-mx+mn<<"\n";
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

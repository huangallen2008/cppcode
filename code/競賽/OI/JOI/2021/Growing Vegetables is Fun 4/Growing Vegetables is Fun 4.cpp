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
    int n;
    cin>>n;
    vector<int> a(n);
    REP(i,n) cin>>a[i];
    vector<int> x(n),y(n);
    REP(i,n-1) x[i]=max(a[i]+1-a[i+1],(int)0);
    RREP(i,n-1) y[i]=max(a[i+1]+1-a[i],(int)0);
//    cout<<"x:";REP(i,n) cout<<x[i]<<" ";cout<<"\n";
//    cout<<"y:";REP(i,n) cout<<y[i]<<" ";cout<<"\n";
    vector<int> px(n),py(n);
    px[0]=x[0],py[n-2]=y[n-2];
    REP1(i,n-1) px[i]=px[i-1]+x[i];
    RREP(i,n-2) py[i]=py[i+1]+y[i];
    int an=min(py[0],px[n-2]);
    for(int i=0;i<n-2;i++) an=min(an,max(px[i],py[i+1]));
    cout<<an<<"\n";
    return 0;
}

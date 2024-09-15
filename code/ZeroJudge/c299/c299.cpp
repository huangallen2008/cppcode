#include<bits/stdc++.h>
using namespace std;
#define ll long long
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
signed main()
{
    IOS();
    int n;
    cin>>n;
    vector<int> a(n);
    REP(i,n) cin>>a[i];
    sort(ALL(a));
    bool ok=1;
    int mn=inf,mx=-inf;
    REP1(i,n-1) if(a[i]!=a[i-1]+1) ok=0;
    REP(i,n) mn=min(mn,a[i]);
    REP(i,n) mx=max(mx,a[i]);
    cout<<mn<<" "<<mx<<" "<<(ok?"yes":"no")<<"\n";
    return 0;
}

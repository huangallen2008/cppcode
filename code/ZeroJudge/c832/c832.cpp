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
const int inf=(1ll<<62)-1;
const int maxn=2e5+5;
const int mod=1e9+7;
bool dif(int a,int b,int c) {
    return (a!=b&&b!=c)&&a!=c;
}
bool ok(int a,int b,int c,int d,int e,int f) {
    if(dif(a,c,e)) return 1;
    if(dif(a,c,f)) return 1;
    if(dif(a,d,e)) return 1;
    if(dif(a,d,f)) return 1;
    if(dif(b,c,e)) return 1;
    if(dif(b,c,f)) return 1;
    if(dif(b,d,e)) return 1;
    if(dif(b,d,f)) return 1;
    return 0;
}
signed main()
{
    IOS();
    int T;
    cin>>T;
    while(T--) {
        int a,b,c,d,e,f;
        cin>>a>>b>>c>>d>>e>>f;
        if(ok(a,b,c,d,e,f)) cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0;
}

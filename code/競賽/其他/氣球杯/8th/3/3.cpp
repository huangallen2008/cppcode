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
const int inf=(1ll<<62);
const int maxn=1e5+5;
const int mod=1e9+7;
vector<int> g(4),a(5);
int f(int u) {
    if(u==4) {
        int an=0;
        int ni=1;
        REP(i,4) {
            ni*=a[i];
            if(g[i]==1) {
                an+=ni;
                ni=1;
            }
        }
        ni*=a[4];
        an+=ni;
        return an;
    }
    int an;
    if(u%2==0) an=0;
    else an=inf;
    REP(i,4) {
        if(g[i]==0) {
            g[i]=1;
            if(u%2==0) an=max(an,f(u+1));
            else an=min(an,f(u+1));
            g[i]=2;
            if(u%2==0) an=max(an,f(u+1));
            else an=min(an,f(u+1));
            g[i]=0;
        }
    }
    return an;
}
signed main()
{
    IOS();
    REP(i,5) cin>>a[i];
    cout<<f(0)<<"\n";
    return 0;
}
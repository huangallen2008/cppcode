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
const int maxn=1e6+5;
const int mod=1e9+9;
struct S {
    int x,y,v;
};
bool so(S a,S b) {
    return a.y*b.x<b.y*a.x;
}
signed main()
{
    IOS();
    int n;
    cin>>n;
    vector<S> v0;
    vector<int> a(1);
    REP(i,n) {
        int x,y,v;
        cin>>x>>y>>v;
        if(x<0) {
            x*=-1;
            y*=-1;
        }
        if(x==0) a[0]+=v;
        else v0.pb({x,y,v});
    }
    sort(ALL(v0),so);
    a.pb(v0[0].v);
    REP1(i,v0.size()-1) {
        if(v0[i].x*v0[i-1].y==v0[i].y*v0[i-1].y) a.back()+=v0[i].v;
        else a.pb(v0[i].v);
    }
    int mx=0,mn=inf,p=0,xp=-inf,np=inf;
    REP(i,a.size()) {
        p+=a[i];
        xp=max(xp,p);
        np=min(np,p);
        mn=min(mn,p-xp);
        mx=max(mx,p-np);
    }
    cout<<max(p-mn,mx)<<"\n";
    return 0;
}

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
int n;
vector<int> p,a;
int lb(int l,int r,int v) {
    int m;
    if(p[r]<v) return r+1;
    while(r>l) {
        m=(l+r)/2;
        if(p[m]>=v) r=m;
        else l=m+1;
    }
    return l;
}
void f(int l,int r,int u) {
    if(l>r) return;
    a[r]=u;
    if(l==r) return;
    int m=lb(l,r-1,p[r]);
    f(l,m-1,p[r]);
    f(m,r-1,p[r]);
}
signed main()
{
    IOS();
    cin>>n;
    p=vector<int>(n);
    a=vector<int>(n);
    REP(i,n) cin>>p[i];
    f(0,n-1,-1);
    vector<pii> an;
    REP(i,n) an.pb({p[i],a[i]});
    sort(ALL(an));
    REP(i,n) cout<<an[i].f<<" "<<an[i].s<<"\n";
    return 0;
}

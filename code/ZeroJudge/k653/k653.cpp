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
signed main()
{
    IOS();
    int k,n,m;
    string s;
    cin>>k>>s>>n>>m;
    vector<pii> a,t;
    REP(i,n) {
        int p,d;
        cin>>p>>d;
        a.pb({p,d});
        if(d==0) t.pb({p,i});
        else t.pb({k+1-p,i});
    }
    sort(ALL(t));
    vector<bool> an(k+2);
    for(int i=m;i<n;i++) {
        if(t[i].f==t[m-1].f) continue;
        int id=a[t[i].s].f+(t[m-1].f)*(a[t[i].s].s*2-1);
        an[id]=1;
    }
    REP1(i,k) if(an[i]) cout<<s[i-1];
    cout<<"\n";
    return 0;
}

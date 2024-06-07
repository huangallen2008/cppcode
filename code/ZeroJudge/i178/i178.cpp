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
    int x,y;
    cin>>x>>y;
    vector<int> a(x),b(y),w(x),l(x);
    int sw=0,sl=0;
    REP(i,x) cin>>a[i];
    REP(i,y) cin>>b[i];
    sort(ALL(a));
    sort(ALL(b));
    REP(i,x) {
        w[i]=lower_bound(ALL(b),a[i])-b.begin();
        l[i]=y-(upper_bound(ALL(b),a[i])-b.begin());
        sw+=w[i];
        sl+=l[i];
    }
    if(w[x-1]<l[x-1]||sw+w[x-1]<=sl+l[x-1]) cout<<"-1\n";
    else {
        int l2=0,r=x-1,m;
        while(r>l2) {
            m=(l2+r)/2;
            if(w[m]>=l[m]&&sw+w[m]>sl+l[m]) r=m;
            else l2=m+1;
        }
        cout<<a[l2]<<"\n";
    }
    return 0;
}

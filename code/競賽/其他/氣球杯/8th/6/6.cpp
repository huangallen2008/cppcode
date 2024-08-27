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
signed main()
{
    IOS();
    int n,q;
    cin>>n>>q;
    vector<int> a(n),an(q);
//    vector<pii> qu;
    vector<int> b;
    REP(i,n) cin>>a[i];
    if(n<=1000) {
        REP(i,n) {
            for(int j=i+1;j<n;j++) b.pb(a[j]-a[i]);
        }
        sort(ALL(b));
    }
    REP(i,q) {
        int x;
        cin>>x;
        if(x==1) {
            int y,k;
            cin>>y>>k;
            y--;
            vector<int> t;
            REP(j,n) if(j!=y) t.pb(abs(a[y]-a[j]));
            sort(ALL(t));
            cout<<t[k-1]<<"\n";
//            an[i]=t[k-1];
        }
        else {
            int k;
            cin>>k;
            cout<<b[k-1]<<"\n";;
//            qu.pb({k,i});

        }
    }
//    sort(ALL(a));
//    REP(i,qu.size()) {
//        int ni=qu[i].s,k=qu[i].f;
//        int l=-2e8,r=2e8,m;
//        while(l<r) {
//            m=(r-l)/2+l;
//            int c=0;
//            REP(j,n) c+=(upper_bound(ALL(a),a[j]+m)-a.begin())-1;
//        }
//    }
    return 0;
}

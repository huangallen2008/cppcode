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
const int maxn=6e5+5;
const int mod=1e9+7;
bool so(pii a,pii b) {
    return a.s>b.s;
}
signed main()
{
    IOS();
    int n,m;
    cin>>n>>m;
    vector<pii> a(n);
    REP(i,n) {
        cin>>a[i].f>>a[i].s;
    }
    sort(ALL(a),so);
    int an=0;
    bool ok=1;
    REP(i,n) {
        if(m<=a[i].f) {
            cout<<an+m*a[i].s<<"\n";
            ok=0;
            break;
        }
        an+=a[i].f*a[i].s;
        m-=a[i].f;
    }
    if(ok) cout<<an<<"\n";
    return 0;
}

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
const int mod=1e9+9;
struct p {
    int d,l,u,r;
};
signed main()
{
    IOS();
    int n,c;
    int an=0;
    cin>>n>>c;
    vector<p> a;
    vector<int> d,u;
    REP(i,n) {
        int _d,_l,_u,_r;
        cin>>_d>>_l>>_u>>_r;
        a.pb({_d,_l,_u,_r});
        d.pb(_d);
        u.pb(_u);
    }
    sort(ALL(d));
    sort(ALL(u));
    REP(di,n) {
        REP(ui,n) {
            if(d[di]>=u[ui]) continue;
            vector<int> l;
            vector<pii> r;
            REP(i,n) {
                if(d[di]<=a[i].d&&a[i].u<=u[ui]) {
                    l.pb(a[i].l);
                    r.pb({a[i].r,a[i].l});
                }
            }
            sort(ALL(l));
            sort(ALL(r));
            REP(li,SZ(l)) {
                int cnt=0;
                REP(ri,SZ(r)) {
                    if(r[ri].f<=l[li]) continue;
                    if(r[ri].s>=l[li]) cnt++;
                    an=max(an,cnt*c-(u[ui]-d[di]+1)*(r[ri].f-l[li]+1));
                }
            }
        }
    }
    cout<<an<<"\n";
    return 0;
}

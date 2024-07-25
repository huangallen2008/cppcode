#include<bits/stdc++.h>
using namespace std;
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
const int maxn=2e5+5;
const int mod=1e9+7;
void solve() {
    int n,c,nc;
    cin>>n>>nc;
    c=nc;
    vector<pii> a(n);
    REP(i,n) {
        cin>>a[i].s;
    }
    REP(i,n) {
        cin>>a[i].f;
    }
    sort(ALL(a));
    int p=1;
    REP(i,n) {
        if(a[i].f>=nc) {
            c+=nc*(n-p);
            break;
        }
        if(p+a[i].s>=n) {
            c+=a[i].f*(n-p);
            break;
        }
        else {
            p+=a[i].s;
            c+=a[i].s*a[i].f;
        }
    }
    cout<<c<<"\n";
}
signed main() {
    IOS();
    int T;
    cin>>T;
    while(T--) {
        solve();
    }
    return 0;
}

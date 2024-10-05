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
#define pipii pair<int,pii>
#define Graph vector<vector<int>>
#define IOS() cin.sync_with_stdio(0),cin.tie(0),cout.tie(0)
const int inf=(1ll<<62);
const int maxn=1e6+5;
const int mod=1e9+7;
bool so(pii a,pii b) {
    return a.f>b.f;
}
void solve() {
    int n,c;
    cin>>n>>c;
    vector<int> a(n+1);
    REP1(i,n) cin>>a[i];
    vector<pii> k;
    for(int i=2;i<=n;i++) k.pb({a[i]-i*c,i});
    sort(ALL(k),so);
    int cnt=0;
    REP(i,k.size()) {
        if(k[i].f>=-a[1]) {
            a[1]+=a[k[i].s];
            cnt++;
        }
        else break;
    }
    if(cnt<n-1) cout<<"No\n";
    else cout<<"Yes\n";
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

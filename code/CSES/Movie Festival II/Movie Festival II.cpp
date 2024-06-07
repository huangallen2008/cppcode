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
bool so(pii a,pii b) {
    return a.s<b.s;
}
void solve() {
    int n,k;
    cin>>n>>k;
    multiset<int> s;
    REP(i,k) s.insert(0);
    vector<pii> v;
    REP(i,n) {
        int l,r;
        cin>>l>>r;
        v.pb({l,r});
    }
    sort(ALL(v),so);
    int an=0;
    REP(i,n) {
        if(v[i].f<*s.begin()) continue;
        s.erase(prev(s.upper_bound(v[i].f)));
        s.insert(v[i].s);
        an++;
    }
    cout<<an<<"\n";
}
signed main() {
    IOS();
    solve();
    return 0;
}

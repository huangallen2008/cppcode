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
    int n,a,b;
    cin>>n>>a>>b;
    vector<int> v(n+1),p(n+1);
    REP1(i,n) cin>>v[i];
    REP1(i,n) p[i]=p[i-1]+v[i];
    int an=-inf;
    multiset<int> s;
    REP(i,n-a+1) {
        s.insert(p[i]);
        if(i>=b-a+1) s.erase(s.find(p[i-b+a-1]));
        an=max(an,p[i+a]-*s.begin());
    }
    cout<<an<<"\n";
}
signed main() {
    IOS();
    solve();
    return 0;
}

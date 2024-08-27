#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
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
const ll inf=(1ll<<63)-1;
const int maxn=2e5+5;
const ll mod=1e9+7;
void solve() {
    int n,x;
    cin>>n>>x;
    vector<int> p(n);
    REP(i,n) cin>>p[i];
    sort(ALL(p));
    int l=0,r=n-1,an=0;
    while(l<=r) {
        if(p[l]+p[r]<=x) l++;
        an++;
        r--;
    }
    cout<<an<<"\n";
}
signed main() {
    IOS();
    solve();
    return 0;
}

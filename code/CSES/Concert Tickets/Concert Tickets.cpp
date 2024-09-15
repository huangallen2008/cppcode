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
    int n,m;
    cin>>n>>m;
    multiset<int> s;
    REP(i,n) {
        int x;
        cin>>x;
        s.insert(x);
    }
    REP(i,m) {
        int x;
        cin>>x;
        if(s.size()==0||x<*s.begin()) cout<<"-1\n";
        else {
            int r=*prev(s.upper_bound(x));
            cout<<r<<"\n";
            s.erase(s.find(r));
        }
    }
}
signed main() {
    IOS();
    solve();
    return 0;
}

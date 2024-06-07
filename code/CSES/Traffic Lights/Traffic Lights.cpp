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
const int inf=(1ll<<63)-1;
const int maxn=2e5+5;
const int mod=1e9+7;
void solve() {
    int x,n;
    cin>>x>>n;
    set<int> s;
    multiset<int> s1;
    s.insert(0),s.insert(x);
    s1.insert(x);
    int an=0;
    REP(i,n) {
        int p;
        cin>>p;
        int r=*s.lower_bound(p),l=*prev(s.lower_bound(p));
        s.insert(p);
        s1.erase(s1.find(r-l));
        s1.insert(r-p),s1.insert(p-l);
//        cout<<"ok"<<endl;
        cout<<*s1.rbegin()<<" ";
    }
    cout<<"\n";
}
signed main() {
    IOS();
    solve();
    return 0;
}

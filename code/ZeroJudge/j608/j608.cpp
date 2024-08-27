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
const int inf=(1ll<<63)-1;
const int maxn=1e5+5;
const int mod=1e9+7;
signed main()
{
    IOS();
    int n,k,an=0;
    cin>>n>>k;
    vector<pii> t(n);
    REP(i,n) cin>>t[i].s;
    REP(i,n) cin>>t[i].f;
    sort(ALL(t));
    multiset<int> s;
    REP(i,k) s.insert(-1);
    REP(i,n) {
        if(t[i].s>*s.begin()) {
            s.erase(prev(lower_bound(ALL(s),t[i].s)));
            s.insert(t[i].f);
            an++;
        }
    }
    cout<<an<<"\n";
    return 0;
}

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
struct A {
    int a,b,c;
};
void solve() {
    int n;
    cin>>n;
    int a,b;
    cin>>a>>b;
    pii p={a,b};
    int l=1;
    vector<A> an;
    REP1(i,n-1) {
        cin>>a>>b;
        if(max(p.f,a)>min(p.s,b)) {
            an.pb({p.f,l,i});
            l=i+1;
            p={a,b};
        }
        else {
            p.f=max(p.f,a);
            p.s=min(p.s,b);
        }
    }
    an.pb({p.f,l,n});
    cout<<an.size()<<"\n";
    REP(i,an.size()) cout<<an[i].a<<" "<<an[i].b<<" "<<an[i].c<<"\n";
}
signed main() {
    IOS();
    solve();
    return 0;
}

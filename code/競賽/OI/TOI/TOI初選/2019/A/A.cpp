#include<bits/stdc++.h>
using namespace std;
#define int long long
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)
#define REP1(i,n) FOR(i,1,n+1)
#define RREP(i,n) for(int i=(n)-1;i>=0;i--)
#define f first
#define s second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)x.size()
#define SQ(x) (x)*(x)
#define pii pair<int,int>
#define Graph vector<vector<int>>
#define IOS() cin.sync_with_stdio(0),cin.tie(0),cout.tie(0)
const int inf=(1ll<<63)-1;
const int mod=1e9+7;
const int maxn=2e5+5;
pii f(int a,int b) {
    int c=__gcd(abs(a),abs(b));
    if(a<0) return {-a/c,-b/c};
    return {a/c,b/c};
}
signed main() {
    IOS();
    int n;
    vector<pii> v;
    cin>>n;
    v=vector<pii>(n);
    REP(i,n) cin>>v[i].f>>v[i].s;
    vector<int> an={inf};
    REP(i,n) {
        map<pii,vector<int>> m;
        int c=0;
        for(int j=i+1;j<n;j++) {
            pii id=f(v[j].f-v[i].f,v[j].s-v[i].s);
            if(SZ(m[id])==0) m[id].pb(i);
            m[id].pb(j);
            if(SZ(m[id])==4) {
                if(m[id]<an) an=m[id];
            }
        }
    }
    if(SZ(an)==1) cout<<"0";
    else REP(i,4) cout<<an[i]+1<<" ";
    cout<<endl;
    return 0;
}

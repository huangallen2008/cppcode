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
#define IOS() ios::sync_with_stdio(0),cin.tie(0)
#define op(x) cout<<#x<<"="<<x<<", ";
#define ope(x) cout<<#x<<"="<<x<<endl;
#define oparr(x) cout<<#x<<":";REP(i,x.size()) cout<<x[i]<<" ";cout<<" size="<<x.size()<<endl;
const int inf=(1ll<<62);
const int maxn=1e6+5;
const int mod=1e9+7;
signed main() {
    IOS();
    int n;
    cin>>n;
    vector<vector<int>> d(n);
    REP(i,n) {
        int k;
        cin>>k;
        d[i]=vector<int>(k);
        REP(j,k) cin>>d[i][j];
    }
    REP(i,n) sort(ALL(d[i]));
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    REP(i,n) pq.push({d[i][0],i});
    vector<int> it(n);
    int an,nan=0;
    auto [lm,lmid]=pq.top();
    pq.pop();
    REP(i,n) nan=max(nan,d[i][it[i]]-lm);
    it[lmid]++;
    if(it[lmid]>=d[lmid].size()) {
        cout<<nan<<'\n';
        return 0;
    }
    pq.push({d[lmid][it[lmid]],lmid});
    an=nan;
//    op(an) ope(nan)
    while(pq.size()) {
        auto [nm,u]=pq.top();
        pq.pop();
        nan=max(d[lmid][it[lmid]]-d[u][it[u]],nan-nm+lm);
        it[u]++;
        an=min(an,nan);
//        op(nan) op(u) op(nm) oparr(it)
        if(it[u]>=d[u].size()) break;
        pq.push({d[u][it[u]],u});
        lm=nm,lmid=u;
    }
    cout<<an<<'\n';
    return 0;
}

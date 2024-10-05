#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define FOR(i,a,b) for (int i = (a); i<(b); i++)
#define REP(i,n) FOR(i,0,n)
#define REP1(i,n) FOR(i,1,n+1)
#define RREP(i,n) for (int i=(n)-1; i>=0; i--)
#define f first
#define s second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)(x.size())
#define SQ(x) (x)*(x)
#define pii pair<int, int>
#define IOS() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
const ll inf = 1ll<<62;
const int iinf=2147483647;
const ll mod = inf;
const ll maxn=1e5+5;
const double PI=acos(-1);
ll pw(ll x, ll p, ll m=mod){
    ll ret=1;
    while (p>0){
        if (p&1){
            ret*=x;
            ret%=m;
        }
        x*=x;
        x%=m;
        p>>=1;
    }
    return ret;
}
int n,m,k,a,x,an=0;
priority_queue<pii,vector<pii>,greater<pii>> p1,p2;
main() {
    IOS();
    cin>>n>>m>>k>>a;
    REP(i,m) p1.push({0,0});
    REP(i,n-m) p2.push({0,0});
    REP(i,a) {
        cin>>x;
        if(x<=k && p1.top().f<=p2.top().f) {
            int f=p1.top().f+x,s=p1.top().s+p1.top().f;
            p1.pop();
            p1.push({f,s});
        }
        else {
            int f=p2.top().f+x,s=p2.top().s+p2.top().f;
            p2.pop();
            p2.push({f,s});
        }
    }
    while(p1.size()) {
        an+=p1.top().s;
        p1.pop();
    }
    while(p2.size()) {
        an+=p2.top().s;
        p2.pop();
    }
    cout<<an<<"\n";
    return 0;
}

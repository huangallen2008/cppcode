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
#define MD(x,m) ((x)%(m)+(m))%(m)
#define md(x) MD(x,mod)
#define IOS() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
const ll inf = 1ll<<62;
const int iinf=2147483647;
const ll mod = 1e9+9;
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
int k,n,an=0;
int a[1001]={},c[1001]={};
main() {
    IOS();
    cin>>k>>n;
    REP(i,n) {
        cin>>a[i];
        an=md(an+a[i]);
    }
    REP(i,n) cin>>c[i];
    FOR(i,n,k) {
        int t=0;
        REP(j,n) t+=md(a[i-j-1]*c[j]);
        a[i]=md(t);
        an=md(an+a[i]);
    }
    cout<<md(an)<<"\n";
    return 0;
}

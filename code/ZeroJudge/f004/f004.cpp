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
#define lbs(x,y) *lower_bound(ALL(x),y)
#define lb(x,y) lower_bound(ALL(x),y)-x.begin()
#define ubs(x,y) *upper_bound(ALL(x),y)
#define ub(x,y) upper_bound(ALL(x),y)-x.begin()
#define IOS() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
const ll inf = 1ll<<62;
const int iinf=2147483647;
const ll mod = 1e9+9;
const ll maxn=1e5+5;
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
int n;
bool fir=0;
void f(int x) {
    if(n>=x) {
        if(fir) cout<<" + ";
        if(!fir) fir=1;
        cout<<x<<"*"<<(n/x);
        n%=x;
    }
}
main() {
    IOS();
    while(cin>>n) {
        fir=0;
        cout<<n<<" = ";
        f(1000);
        f(500);
        f(100);
        f(50);
        f(10);
        f(5);
        f(1);
        cout<<"\n";
    }
    return 0;
}

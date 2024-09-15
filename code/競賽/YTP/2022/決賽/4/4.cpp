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
string s;
int x,d,p,c=2,t=0;
vector<int> v;
main() {
    IOS();
    cin>>s;
    x=s[0]-'0';
    d=s[2]-'0';
    p=s[4]-'0';
    v.pb(pw(x+d,p));
    v.pb(abs(pw(x+d,p)-pw(x,p)));
    while(true) {
        t=pw(x+c*d,p);
        c++;
        REP(i,SZ(v)) {
            if(i==SZ(v)-1 && t==v[i]) {
                cout<<v[i]<<"\n";
                return 0;
            }
            swap(t,v[i]);
            t=abs(v[i]-t);
        }
        v.pb(t);
    }
    return 0;
}

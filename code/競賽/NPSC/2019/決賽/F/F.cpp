#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,n) FOR(i,0,n)
#define REP1(i,n) FOR(i,1,n+1)
#define RREP(i,n) for(int i=n-1;i>=0;i--)
#define f first
#define s second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)(x.size())
#define SQ(x) (x)*(x)
#define pii pair<int,int>
#define MD(x,m) (x%m+m)%m
#define md(x) MD(x,mod)
#define IOS() cin.sync_with_stdio(0),cin.tie(0),cout.tie(0)
const ll inf=(1ll<<63)-1;
const int maxn=1e4+5;
const ll mod=1e9+7;
ll pw(ll x,ll p,ll m=mod) {
    ll r=1;
    while(p>0) {
        if(p&1) {
            r*=x;
            r%=m;
        }
        x*=x;
        x%=m;
        p>>=1;
    }
    return r;
};
ll inv(ll x,ll m=mod) {
    return pw(x,m-2,m);
}
int n,q,k;
int t;
signed main()
{
    IOS();
    cin>>n>>q;
    REP(i,q) {
        cin>>k;
        k=n*(n+1)/2-k;
        t=0;
        bool ok=1;
        vector<int> v;
        while(k>0) {
            int x=((int)sqrt(k*8+1)-1)/2;
            t+=x+1;
            v.pb(x);
            k-=x*(x+1)/2;
            if(t>n+1) {
                cout<<"No\n";
                ok=0;
                break;
            }
        }
        if(ok==0) continue;
        REP(i,SZ(v)) {
            REP(rd,v[i]) cout<<"0";
            if(i==SZ(v)-1&&t==n+1) continue;
            cout<<"1";
        }
        REP(i,n-t) cout<<"1";
        cout<<"\n";
    }
    return 0;
}

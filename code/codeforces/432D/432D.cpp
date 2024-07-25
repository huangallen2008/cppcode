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
#define SQ(x) x*x
#define pii pair<int,int>
#define MD(x,m) (x%m+m)%m
#define md(x) MD(x,mod)
#define IOS() cin.sync_with_stdio(0),cin.tie(0),cout.tie(0)
const ll inf=(1ll<<63)-1;
const int maxn=1e6+5;
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
string s;
int n;
int w=0;
int f[maxn]={};
int a[maxn]={};
vector<pii> an;
signed main()
{
    IOS();
    cin>>s;
    n=SZ(s);
    s="$"+s;
    f[0]=-1; f[1]=0;
    for(int i=2;i<=n;i++) {
        while(w>=0) {
            if(s[i]==s[w+1]) {
                f[i]=++w;
                break;
            }
            else w=f[w];
        }
        if(w<0) f[i]=++w;
    }
    REP1(i,n) a[i]=1;
    for(int i=n;i>0;i--) {
        a[f[i]]+=a[i];
    }
    an.pb({n,1});
    while(w>0) {
        an.pb({w,a[w]});
        w=f[w];
    }
    cout<<SZ(an)<<"\n";
    RREP(i,SZ(an)) cout<<an[i].f<<" "<<an[i].s<<"\n";
    return 0;
}

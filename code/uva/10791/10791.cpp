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
const int maxn=2e5+5;
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
int n,c=1,an=0,tn;
int ct=0;
signed main()
{
    IOS();
    cin>>n;
    while(n!=0) {
        ct=0;
        cout<<"Case "<<c++<<": ";
        an=0;
        tn=n;
        for(int i=2;i*i<=n;i++) {
            int t=1;
            while(n%i==0) {
                n/=i;
                t*=i;
            }
            if(t>1) {
                an+=t;
                ct++;
            }
        }
        if(n!=1) an+=n;
        if(tn==n || ct==1) an++;
        if(tn==1) an=2;
        cout<<an<<"\n";
        cin>>n;
    }
    return 0;
}

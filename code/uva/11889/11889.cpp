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
int T,a,b,c;
bool gg=0;
signed main()
{
    IOS();
    cin>>T;
    while(T--) {
        b=1;
        cin>>a>>c;
        for(int i=2;i*i<=c;i++) {
            int ta=1,tc=1;
            while(a%i==0) {
                a/=i;
                ta*=i;
            }
            while(c%i==0) {
                c/=i;
                tc*=i;
            }
            if(ta>tc) {
                gg=1;
                break;
            }
            if(ta<tc){
                b*=tc;
            }
        }
        if(a!=1 && c==1) gg=1;
        if(a==1 && c!=1) b*=c;

        if(gg) cout<<"NO SOLUTION\n";
        else cout<<b<<"\n";
    }
    return 0;
}

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
const int maxn=100;
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
int f[maxn]={};
int w;
void d() {
    s="$problem$"+s;
    w=0;
    for(int i=2;i<SZ(s);i++) {
        while(w>=0) {
            if(tolower(s[i])==tolower(s[w+1])) {
                f[i]=++w;
                break;
            }
            else w=f[w];
        }
        if(w<0) f[i]=++w;
        if(f[i]==7) {
            cout<<"yes\n";
            return;
        }
    }
    cout<<"no\n";
}
signed main()
{
    IOS();
    f[0]=-1; f[1]=0;
    while(getline(cin,s)) {
        d();
    }
    return 0;
}

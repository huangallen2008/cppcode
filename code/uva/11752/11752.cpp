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
bool isp(int n) {
    if(n==1) return 0;
    for(int i=2;i*i<=n;i++) if(n%i==0) return 0;
    return 1;
}
int np[]={4,6,8,9,10,12,14,15,16,18,20,21,22,24,25,26,27,28,30,32,33,34,35,36,38,39,40,42,44,45,46,48,49,50,51,52,54,55,56,57,58,60,62,63,64};
class cmp {
    public:
    bool operator()(pii a,pii b) const {
        return pw(a.f,np[a.s],inf)<pw(b.f,np[b.s],inf);
    }
};
priority_queue<pii,vector<pii>,cmp> pq;
signed main()
{
    IOS();
    for(int i=2;i<65537;i++) {
        if(isp(i)) pq.push({i,0});
    }
    while(true) {
        int a=pq.top().f,b=pq.top().s;
        pq.pop();
        cout<<a<<" "<<b<<"\n";
        //cout<<pw(a,np[b],inf)<<"\n";
        if(pw(a,np[b+1],inf)>0) pq.push({a,b+1});
    }
    return 0;
}

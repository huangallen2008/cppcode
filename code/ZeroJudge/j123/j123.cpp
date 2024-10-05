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
#define Graph vector<vector<int>>
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
int r,c,n;
int x;
char t;
vector<int> s,u={4,3,4,4,5};
vector<vector<pii>> A={{{0,1},{1,1},{2,1},{3,1}},{{0,3}},{{0,2},{1,2}},{{0,3},{-1,3}},{{0,2},{1,2},{-1,2}}};
pii an={0,0};
int mx(vector<int> v) {
    int a=0;
    for(auto p:v) a=max(a,p);
    return a;
}
signed main()
{
    IOS();
    cin>>r>>c>>n;
    s=vector<int>(r);
    an.f=r*c;
    REP(i,n) {
        cin>>t>>x;
        int b=t-'A';
        int id;
        bool nok=0;
        x+=(b>=3?1:0);
        if(b==0) id=mx({s[x],s[x+1],s[x+2]});
        if(b==1) id=mx({s[x]});
        if(b==2) id=mx({s[x],s[x+1]});
        if(b==3) id=mx({s[x-1]-2,s[x]});
        if(b==4) id=mx({s[x],s[x+1],s[x-1]-1});
        for(auto [p,q]:A[b]) {
            if(id+q>c) {
                nok=1;
                break;
            }
        }
        if(nok) {
            an.s++;
            continue;
        }
        an.f-=u[b];
        for(auto [p,q]:A[b]) s[x+p]=id+q;
    }
    cout<<an.f<<" "<<an.s<<"\n";
    return 0;
}

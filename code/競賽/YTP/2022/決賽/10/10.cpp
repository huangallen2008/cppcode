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
const ll mod = 1e9+7;
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
int l,w,n,x;
int an=inf;
vector<int> v[100];
int dp[100][100000]={};
int d(int i,int j) {
    if(i==w-1) return 0;
    if(dp[i][j]) return dp[i][j];
    int id=lower_bound(ALL(v[i+1]),v[i][j])-v[i+1].begin();
    if(id<SZ(v[i+1]) && v[i+1][id]==v[i][j]) return d(i+1,id);
    return dp[i][j]=min((id==0?inf:d(i+1,id-1)+abs(v[i][j]-v[i+1][id-1])),(id==SZ(v[i+1])?inf:d(i+1,id)+abs(v[i][j]-v[i+1][id])));
}
main() {
    IOS();
    cin>>l>>w;
    REP(i,w) {
        cin>>n;
        REP(j,n) {
            cin>>x;
            v[i].pb(x);
        }
    }
    REP(i,SZ(v[0])) {
        an=min(an,d(0,i));
    }
    cout<<an<<"\n";
    return 0;
}

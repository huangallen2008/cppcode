#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,n) FOR(i,0,n)
#define REP1(i,n) FOR(i,1,(n)+1)
#define RREP(i,n) for(int i=(n)-1;i>=0;i--)
#define f first
#define s second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)(x.size())
#define SQ(x) (x)*(x)
#define pii pair<int,int>
#define Graph vector<vector<int>>
#define IOS() cin.sync_with_stdio(0),cin.tie(0),cout.tie(0)
const int inf=(1ll<<63)-1;
const int maxn=2e5+5;
const int mod=1e9+7;
int n,q;
vector<int> ua(vector<int> a) {
    unordered_map<int,int> m;
    int x=1;
    REP1(i,n) {
        if(m[a[i]]==0) {
            m[a[i]]=x++;
            a[i]=m[a[i]];
        }
        else a[i]=m[a[i]];
    }
    return a;
}
vector<int> bn(vector<int> a) {
    vector<int> l(n+1,n+1),nxt(n+1);
    for(int i=n;i>0;i--) {
        nxt[i]=l[a[i]];
        l[a[i]]=i;
    }
    return nxt;
}
int bit[maxn]={};
void ud(int u,int v) {
    for(;u<=n;u+=u&-u) bit[u]+=v;
}
int qu(int u) {
    int an=0;
    for(;u>0;u-=u&-u) an+=bit[u];
    return an;
}
signed main()
{
    IOS();
    cin>>n>>q;
    vector<int> a(n+1);
    REP1(i,n) cin>>a[i];
    a=ua(a);
    vector<int> next;
    next=bn(a);
    vector<vector<pii>> b(n+1);
    REP(i,q) {
        int x,y;
        cin>>x>>y;
        b[x].pb({y,i});
    }
    vector<int> an(q);
    for(int i=n;i>0;i--) {
        ud(i,1);
        if(next[i]<=n) ud(next[i],-1);
        REP(j,b[i].size()) an[b[i][j].s]=qu(b[i][j].f)-qu(i-1);
    }
    REP(i,q) cout<<an[i]<<endl;
    return 0;
}

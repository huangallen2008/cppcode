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
#define b(x) ;
const int inf=(1ll<<62);
const int maxn=1e5+5;
const int mod=1e9+9;
int n,m,k;
struct BIT {
    vector<int> b;
    int n;
    BIT(int _n) {
        n=_n;
        b=vector<int>(_n+1);
    }
    void ud(int u,int v) {
        b[u]+=v;
        int t=b[u];
        for(;u<=n;u+=(u&-u)) b[u]=max(b[u],t);
    }
    int qu(int u) {
        int r=b[u];
        for(;u>0;u-=(u&-u)) r=max(r,b[u]);
        return r;
    }
};
struct N {
    int a,b,e;
};
bool so(N a,N b) {
    if(a.a==b.a) return a.b>b.b;
    return a.a<b.a;
}
signed main()
{
    IOS();
    cin>>n>>m>>k;
    BIT bit(m);
    vector<N> v;
    REP(i,k) {
        int a,b,e;
        cin>>a>>b>>e;
        v.pb({a,b,e});
    }
    sort(ALL(v),so);
    int x,an=0;
    cout<<"\n\n";
    REP(i,k) {
        cout<<v[i].a<<" "<<v[i].b<<" "<<v[i].e<<"\n";
        x=bit.qu(v[i].b-1)+v[i].e;
        bit.ud(v[i].b,x);
//        cout<<d[i]<<" ";
        an=max(an,x);
    }
    cout<<an<<"\n";
    return 0;
}
/*
2 3 6
1 1 3
1 2 4
1 3 6
2 1 7
2 2 2
2 3 4


*/

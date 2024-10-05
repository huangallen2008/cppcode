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
const int maxn=1e5+5;
const int mod=1e9+7;
vector<vector<int>> y(4),x;
int n;
void f(int k,int u,int d) {
    if(u>=n) {
        y[k].pb(d);
        return;
    }
    f(k,u+1,d);
    f(k,u+1,d+x[k][u]);
}
signed main()
{
    IOS();
    int a,b,c,d;
    cin>>a>>b>>c>>d>>n;
    x=vector<vector<int>>(4,vector<int>(n));
    REP(i,4) REP(j,n) cin>>x[i][j];
    f(0,0,0);
    f(1,0,0);
    f(2,0,0);
    f(3,0,0);
    REP(i,4) sort(ALL(y[i]));
    bool ok=1;
    REP(i,n) {
        if(y[0][i]%a!=0||y[0][i]==0) continue;
        int r=y[0][i]/a;
        bool b1=*lower_bound(ALL(y[1]),r*b)==r*b;
        if(r*b>y[1].back()) b1=0;
        bool b2=*lower_bound(ALL(y[2]),r*c)==r*c;
        if(r*c>y[2].back()) b2=0;
        bool b3=*lower_bound(ALL(y[3]),r*d)==r*d;
        if(r*d>y[3].back()) b3=0;
        if(b1&&b2&&b3) {
            cout<<r*a<<" "<<r*b<<" "<<r*c<<" "<<r*d<<"\n";
            ok=0;
            break;
        }
    }
    if(ok) cout<<"-1\n";
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
//#define ll long long
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
const int maxn=1e6+5;
const int mod=1e9+7;
int n,l,w;
vector<int> x,y,xi,yi;
vector<vector<int>> m,yp;
int f(int i,int a,int b) {
    if(a==0) return yp[i][b];
    return yp[i][b]-yp[i][a-1];
}
signed main()
{
    IOS();
    cin>>n>>l>>w;
    x=vector<int>(n);
    y=vector<int>(n);
    xi=vector<int>(n);
    yi=vector<int>(n);
    m=vector<vector<int>>(n,vector<int>(n));
    yp=vector<vector<int>>(n,vector<int>(n));
    REP(i,n) cin>>x[i]>>y[i];
    xi=x; yi=y;
    sort(ALL(xi)); sort(ALL(yi));
    REP(i,n) x[i]=lower_bound(ALL(xi),x[i])-xi.begin();
    REP(i,n) y[i]=lower_bound(ALL(yi),y[i])-yi.begin();
    REP(i,n) m[x[i]][y[i]]++;
    REP(i,n) {
        yp[i][0]=m[i][0];
        REP1(j,n-1) yp[i][j]=yp[i][j-1]+m[i][j];
    }
    int an=0;
    int ay=0,by=0;
    while(ay<n&&by<n-1) {
        while(yi[by+1]-yi[ay]>l) {
            ay++;
        }
        by++;
        int cnt=f(0,ay,by);
        int ax=0,bx=0;
        while(ax<n&&bx<n-1) {
            while(xi[bx+1]-xi[ax]>w) {
                cnt-=f(ax,ay,by);
                ax++;
            }
            bx++;
            cnt+=f(bx,ay,by);
            an=max(an,cnt);
        }
    }
    cout<<an<<"\n";
    return 0;
}

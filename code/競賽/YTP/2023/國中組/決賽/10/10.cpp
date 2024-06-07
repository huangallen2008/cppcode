#include<bits/stdc++.h>
using namespace std;
#define ll long long
//#define int long long
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
const int inf=(1ll<<62);
const int maxn=1e5+5;
const int mod=1e9+9;
signed main()
{
    IOS();
    int T;
    cin>>T;
    while(T--) {
        int n,m;
        int la,lb;
        cin>>n>>m;
        vector<vector<int>> a(n+1,vector<int>(m+1)),p(n+1,vector<int>(m+1));
        vector<vector<pii>> d(n+1,vector<pii>(m+1,{-1,-1}));
        REP1(i,n) {
            REP1(j,m) {
                cin>>a[i][j];
                p[i][j]=p[i-1][j]+p[i][j-1]-p[i-1][j-1]+a[i][j];
//                cout<<p[i][j]<<" ";
            }
        }
        cin>>la>>lb;
        REP1(i,n) {
            REP1(j,m) {
                REP1(ni,i) {
                    REP1(nj,j) {
                        if(d[i][j].f==-1) {
                            d[i][j]={d[ni-1][nj].s+p[i][j]-p[ni-1][j]-p[i][nj-1]+p[ni-1][nj-1],d[ni][nj].f};

                        }
//                        cout<<p[i][j]-p[ni-1][j]-p[i][nj-1]+p[ni-1][nj-1]<<" "<<d[ni][nj].f<<" "<<"{{"<<d[i][j].f<<","<<d[i][j].s<<"}} ";
                        else if(d[ni][nj].f-(d[ni][nj].s+p[i][j]-p[ni-1][j]-p[i][nj-1]+p[ni-1][nj-1])>d[i][j].s-d[i][j].f) {
                            d[i][j]={d[ni][nj].s+p[i][j]-p[ni-1][j]-p[i][nj-1]+p[ni-1][nj-1],d[ni][nj].f};
                        }
                    }
                }
//                cout<<"{"<<d[i][j].f<<" "<<d[i][j].s<<"} ";
            }
        }
        if(la+d[n][m].f>lb+d[n][m].s) cout<<"A\n";
        else if(la+d[n][m].f<lb+d[n][m].s) cout<<"B\n";
        else cout<<"Tie\n";
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#define int long long
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
#define RREP(i,n) for(int i=(n)-1;i>=0;i--)
#define f first
#define s second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)(x.size())
#define SQ(x) (x)*(x)
#define pii pair<int,int>
#define pipii pair<int,pii>
#define Graph vector<vector<int>>
#define IOS() ios::sync_with_stdio(0),cin.tie(0)
#define md(x) (((x)%(mod)+(mod))%(mod))
#define op(x) cout<<#x<<"="<<x<<", ";
#define ope(x) cout<<#x<<"="<<x<<endl;
#define oparr(x) cout<<#x<<":";REP(i,x.size()) cout<<x[i]<<" ";cout<<" size="<<x.size()<<endl;
#define entr cout<<endl;
const int inf=(1ll<<62);
const int maxn=1e5+5;
const int mod=1e9+7;
signed main() {
    IOS();
    int n;
    cin>>n;
    pii s,e;
    vector<vector<bool>> m(n,vector<bool>(n));
    REP(i,n) {
        REP(j,n) {
            char c;
            cin>>c;
            if(c!='#') m[i][j]=1;
            if(c=='S') s={i,j};
            if(c=='T') e={i,j};
        }
    }
    int dir=0;//D:0 L:1 U:2 R:3
    vector<pii> dir_a={{0,1},{1,0},{0,-1},{-1,0}};
    vector<int> an;
    while(1) {
        int nx=s.f+dir_a[dir].f,ny=s.s+dir_a[dir].s;
        int rx=s.f+dir_a[(dir+1)%4].f,ry=s.s+dir_a[(dir+1)%4].s;
        if(!m[rx][ry]) an.pb(dir);
        if(s==e) break;
        if(m[rx][ry]) {
            dir=(dir+1)%4;
            s={rx,ry};
        }
        else if(m[nx][ny]) {
            s={nx,ny};
        }
        else {
            dir=(dir-1+4)%4;
        }
    }
    string itod="DLUR";
    REP(i,an.size()) cout<<itod[an[i]];
    cout<<'\n';
    return 0;
}

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
vector<pii> d={{0,1},{0,-1},{1,0},{-1,0}};
signed main()
{
    IOS();
    int h,w;
    cin>>h>>w;
    vector<vector<bool>> m(h+2,vector<bool>(w+2));
    vector<vector<int>> v(h+2,vector<int>(w+2));
    REP1(i,h) {
        REP1(j,w) {
            char c;
            cin>>c;
            if(c=='.') m[i][j]=1;
        }
    }
    int vid=1;
    vector<int> a;
    REP1(i,h) {
        REP1(j,w) {
            if(v[i][j]==0&&m[i][j]) {
                int c=0;
                while(1) {
                    v[i][j]=vid;
                    int c0=m[i+1][j]+m[i][j+1]+m[i-1][j]+m[i][j-1];
//                    cout<<c0<<"\n";
                    REP(di,4) {
                        if(m[i+d[di].f][j+d[di].s]) {
                            i+=d[di].f,j+=d[di].s;
                            break;
                        |
                    }
                    c++;
                }
                vid++;
            }
        }
    }
    return 0;
}
/*
3 3
...
.0.
...


*/

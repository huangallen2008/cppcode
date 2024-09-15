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
signed main()
{
    IOS();
    int n;
    cin>>n;
    vector<vector<int>> m(n,vector<int>(n));
    REP(i,n) {
        REP(j,n) {
            char x;
            cin>>x;
            if(x=='X') m[i][j]=0;
            else if(x=='.') m[i][j]=1;
            else m[i][j]=2;//p
        }
    }
    REP(i,n) {
        REP(j,n) {
            if(m[i][j]==0) cout<<"X";
            else if(m[i][j]==2) cout<<"P";
            else {
                if(i%3==1&&j<n-1) cout<<"O";
                else if(j==n-2) cout<<"O";
                else if(n%3==1&&i==n-1&&j<n-1) cout<<"O";
                else cout<<".";
            }
        }
        cout<<"\n";
    }
    return 0;
}
/*
5
X...P
P...P
P...P
P...P
P....

6
X....P
..P...
P.....
...P..
PP....
PPPP.P

7
X..P..P
.P...P.
..P.P..
P..P..P
..P.P..
.P...P.
P..P..P
*/

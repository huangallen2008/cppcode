#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
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
const ll inf=(1ll<<63)-1;
const int maxn=1e5+5;
const ll mod=1e9+7;
int n,m,q,l,r;
vector<vector<char>> a;
vector<vector<int>> v;
char c;
int x;
int id(char c) {
    if(c-'a'<0) return c-'A';
    else return c-'a'+26;
}
signed main()
{
    IOS();
    cin>>n>>m>>q>>l>>r;l--;r--;
    a=vector<vector<char>>(n,vector<char>(m));
    v=vector<vector<int>>(55);
    REP(i,n)
        REP(j,m)
            cin>>a[i][j];
    REP(j,m) {
        REP(i,n) {
            if(a[i][j]=='.') continue;
            v[id(a[i][j])].pb(j);
        }
    }
    REP(i,q) {
        cin>>x>>c;
        int ic=id(c);
        x--;//m-1->m-1-x%m
        int nl=m-1-x%m,li,ri;
        if(v[ic].back()<=nl) {
            li=v[ic][0];
            ri=v[ic].back();
        }
        else {
            int iid=upper_bound(ALL(v[ic]),nl)-v[ic].begin();
            li=v[ic][iid];
            if(iid==0) ri=v[ic].back();
            else ri=v[ic][iid-1];
        }
        li=(li+x)%m;
        ri=(ri+x)%m;
        if(li>=l&&ri<=r) cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0;
}
/*
10 25 10
5 20
.................O..O....
.CCCC.................SS.
.....................S...
....Z.....Z...........S..
.......Z..Z............S.
.............X....X..SS..
.DD..F...................
.D.D.FFFFFF.....X........
.D.D.F........X...X......
.DD..F...........OO...N..
4 O
15 Z
25 O
4 X
4 N
20 Z
1 Z
5 Z
25 S
16 N

N
N
Y
N
N
N
Y
Y
N
Y
*/

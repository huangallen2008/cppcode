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
int n;
#define opp(xx,y) {int x2=xx-1;if(-9<x2&&x2<9&&-9<y&&y<9&&-9<x2+y&&x2+y<9)cout<<x2<<' '<<y<<' ';else cout<<"0 0 ";}
#define entr cout<<'\n';
bool fir=1;
void f(int n) {
    if(n<=0) return;
    if(n==1) {
        if(fir) cout<<"-1 1 -1 0 0 -1\n0 1 1 0 1 -1\n";
        else cout<<"-1 1 -1 0 0 -1\n0 1 0 0 1 -1\n";
        return;
    }
    if(n==2) {
        cout<<"1 0 2 -1 2 -2\n1 -1 1 -2 0 -2\n0 -1 -1 -1 -2 0\n-1 0 -2 1 -2 2\n-1 1 -1 2 0 2\n0 1 1 1 0 0\n";
        return;
    }
    int x,y;
    x=-n,y=n;
    REP(i,n-1) {
        opp(x,y)opp(x,y-1)opp(x+1,y-2)entr
        x++;
    }
    x=-n,y=0;
    REP(i,n-1) {
        opp(x,y)opp(x+1,y-1)opp(x+2,y-1)entr
        y++;
    }
    x=0,y=-n;
    REP(i,n-1) {
        opp(x,y)opp(x+1,y)opp(x+1,y+1)entr
        x--,y++;
    }
    x=n,y=-n;
    REP(i,n-1) {
        opp(x,y)opp(x,y+1)opp(x-1,y+2)entr
        x--;
    }
    x=n,y=0;
    if(fir){
        fir=0;
        opp(n,0)
    }
    else opp(n-1,0)
    opp(n-1,1)opp(n,-1)entr
    opp(n-2,1)opp(n-2,0)opp(n-3,0)entr
    REP(i,n-1) {
        if(i>1){opp(x,y)opp(x-1,y+1)opp(x-2,y+1)entr}
        y--;
    }
    x=0,y=n;
    REP(i,n-1) {
        opp(x,y)opp(x-1,y)opp(x-1,y-1)entr
        x++,y--;
    }
    f(n-3);
}
void solve() {
    int n;
    cin>>n;
    int x,y;
    cin>>x>>y;
    if(n==3) {
        cout<<"No\n";
        return;
    }
    cout<<"Yes\n";
    f(n-1);
}
signed main()
{
    IOS();
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}

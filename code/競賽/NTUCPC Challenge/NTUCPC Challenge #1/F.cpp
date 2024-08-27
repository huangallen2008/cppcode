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
<<<<<<< HEAD
// #ifdef LOCAL
#define op(x) cout<<(#x)<<"="<<(x)<<", ";
#define ope(x) cout<<(#x)<<"="<<(x)<<endl;
#define oparr(x) cout<<(#x)<<":";for(auto &allen:(x)) cout<<allen<<" ";cout<<" size="<<(x).size()<<endl;
#define entr cout<<endl;
// #else
// #define op(x) ;
// #define ope(x) ;
// #define oparr(x) ;
// #define entr ;
// #endif
=======
>>>>>>> 0b1a1b11a3c05bbc53306c9c4fc912c08c4ad5ba
const ll inf=(1ll<<63)-1;
const int maxn=1e5+5;
const ll mod=1e9+7;
int n;
#define opp(x,y) cout<<x<<' '<<y<<' ';
#define entr cout<<'\n';
bool fir=1;
<<<<<<< HEAD
int nox,noy;
int ty=0;
void f(int n) {
    if(n<=0) return;
    if(n==1) {
        if(nox==0) {
            opp(-1,1)opp(-1,0)opp(0,-1)entr
            opp(0,1)opp(1,0)opp(1,-1)entr
            // cout<<"-1 1 -1 0 0 -1\n0 1 1 0 1 -1\n";
        }
        else {
            opp(-1,1)opp(-1,0)opp(0,-1)entr
            opp(0,1)opp(0,0)opp(1,-1)entr
            // cout<<"-1 1 -1 0 0 -1\n0 1 0 0 1 -1\n";
        }
        return;
    }
    if(n==2) {
        if(nox==0) cout<<"1 0 2 -1 2 -2\n1 -1 1 -2 0 -2\n0 -1 -1 -1 -2 0\n-1 0 -2 1 -2 2\n-1 1 -1 2 0 2\n0 1 1 1 2 0\n";
        else if(nox==2)cout<<"1 0 2 -1 2 -2\n1 -1 1 -2 0 -2\n0 -1 -1 -1 -2 0\n-1 0 -2 1 -2 2\n-1 1 -1 2 0 2\n0 1 1 1 0 0\n";
        else cout<<"1 0 2 -1 0 0\n1 -1 1 -2 0 -2\n0 -1 -1 -1 -2 0\n-1 0 -2 1 -2 2\n-1 1 -1 2 0 2\n0 1 1 1 2 0\n";
        return;
    }
    if(n==3&&nox==1) {
        cout<<"3 0 3 -1 2 1\n2 0 2 -1 1 1\n3 -2 3 -3 2 -3\n1 -3 0 -3 -1 -2\n2 -2 1 -2 0 -1\n0 -2 -1 -1 -2 -1\n1 -1 0 0 -1 0\n-2 0 -3 0 -2 1\n-3 1 -3 2 -2 2\n0 1 0 2 -1 1\n-1 2 -2 3 -3 3\n-1 3 0 3 1 2\n";
        return;
    }
    if(n==5&&nox==1) {
        cout<<"-5 5 -5 4 -4 3\n-4 5 -4 4 -3 3\n-3 5 -3 4 -2 3\n-2 5 -2 4 -1 3\n-5 0 -4 -1 -3 -1\n-5 1 -4 0 -3 0\n-5 2 -4 1 -3 1\n-5 3 -4 2 -3 2\n0 -5 1 -5 1 -4\n-1 -4 0 -4 0 -3\n-2 -3 -1 -3 -1 -2\n-3 -2 -2 -2 -2 -1\n5 -5 5 -4 4 -3\n4 -5 4 -4 3 -3\n3 -5 3 -4 2 -3\n2 -5 2 -4 1 -3\n5 0 4 1 3 1\n5 -1 4 0 5 -2\n2 0 4 -1 3 0\n5 -3 4 -2 3 -2\n0 5 -1 5 -1 4\n1 4 0 4 0 3\n2 3 1 3 1 2\n3 2 2 2 2 1\n3 -1 2 -1 2 -2\n1 -1 1 -2 0 -2\n0 -1 -1 -1 -2 0\n-1 0 -2 1 -2 2\n-1 1 -1 2 0 2\n0 1 1 1 0 0\n";
=======
void f(int n) {
    if(n<=0) return;
    if(n==1) {
        if(fir) cout<<"-1 1 -1 0 0 -1\n0 1 1 0 1 -1\n";
        else cout<<"-1 1 -1 0 0 -1\n0 1 0 0 1 -1\n";
        return;
    }
    if(n==2) {
        cout<<"1 0 2 -1 2 -2\n1 -1 1 -2 0 -2\n0 -1 -1 -1 -2 0\n-1 0 -2 1 -2 2\n-1 1 -1 2 0 2\n0 1 1 1 0 0\n";
>>>>>>> 0b1a1b11a3c05bbc53306c9c4fc912c08c4ad5ba
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
<<<<<<< HEAD
    if(nox==n-1||nox==n) {
        if(n-1==nox) {
            opp(n,0)
        }
        else opp(n-1,0)
        opp(n-1,1)opp(n,-1)entr
        opp(n-2,1)opp(n-2,0)opp(n-3,0)entr
    }
    if(nox==n-2) {
        opp(n-1,0)opp(n,-1)opp(n,-2)entr
        opp(n-1,-1)opp(n-2,-1)opp(n-3,0)entr
    }
    REP(i,n-1) {
        if(nox==n||nox==n-1) {if(i>1){opp(x,y)opp(x-1,y+1)opp(x-2,y+1)entr}}
        else if(nox==n-2) {if(i==0||i>2){opp(x,y)opp(x-1,y+1)opp(x-2,y+1)entr}}
        else {opp(x,y)opp(x-1,y+1)opp(x-2,y+1)entr}
        y--;
    }
    if(nox>=n-2)nox=n-3;
=======
    if(fir) {
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
>>>>>>> 0b1a1b11a3c05bbc53306c9c4fc912c08c4ad5ba
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
<<<<<<< HEAD
    // ty=;
    int x,y;
    cin>>x>>y;
    nox=x,noy=y;
    fir=1;
    if(n==3&&x==1) {
        cout<<"No\n";
        return;
    }
    if(n==4&&x==1) {
        cout<<"Yes\n3 0 3 -1 2 1\n2 0 2 -1 1 1\n3 -2 3 -3 2 -3\n1 -3 0 -3 -1 -2\n2 -2 1 -2 0 -1\n0 -2 -1 -1 -2 -1\n1 -1 0 0 -1 0\n-2 0 -3 0 -2 1\n-3 1 -3 2 -2 2\n0 1 0 2 -1 1\n-1 2 -2 3 -3 3\n-1 3 0 3 1 2\n";
=======
    int x,y;
    cin>>x>>y;
    fir=1;
    if(n==2&&x==0&&y==-1) {
        cout<<"Yes\n-1 0 0 0 1 -1\n-1 1 0 1 1 0\n";
        return;
    }
    if(n==3) {
        cout<<"No\n";
>>>>>>> 0b1a1b11a3c05bbc53306c9c4fc912c08c4ad5ba
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

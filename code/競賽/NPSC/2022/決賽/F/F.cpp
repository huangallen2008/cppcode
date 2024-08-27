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
void f(int n) {
    if(n<=1) return;
    if(n==2) {
        cout<<"-1 1 -1 0 0 -1\n0 1 1 - 1 -1\n";
        return;
    }
    int x,y;
    x=2,y=-(n-1);
    REP(i,n-2) {
        x++;
        cout<<x-1<<" "<<y+1<<" "<<x<<" "<<y<<" "<<x<<" "<<y-1<<"\n";
    }
    x=n-1,y=-n+3;
    REP(i,n-2) {
        y++;
        cout<<x<<" "<<y<<" "<<x-1<<" "<<y<<" "<<x+1<<" "<<y-1<<"\n";
    }
    x=n-3,y=2;
    REP(i,n-2) {
        x--,y++;
        cout<<x<<" "<<y<<" "<<x+1<<" "<<y<<" "<<x<<" "<<y-1<<"\n";
    }
    x=-2,y=n-1;
    REP(i,n-2) {
        x--;
        cout<<x<<" "<<y<<" "<<x+1<<" "<<y-1<<" "<<x<<" "<<y+1<<"\n";
    }
    x=-(n-1),y=n-3;
    REP(i,n-2) {
        y--;
        cout<<x<<" "<<y<<" "<<x+1<<" "<<y<<" "<<x-1<<" "<<y+1<<"\n";
    }
    x=-(n-3),y=-2;
    REP(i,n-2) {
        x++,y--;
        cout<<x<<" "<<y<<" "<<x<<" "<<y+1<<" "<<x-1<<" "<<y<<"\n";
    }
    f(n-3);
}
signed main()
{
    IOS();
    cin>>n;
    f(n);
    return 0;
}

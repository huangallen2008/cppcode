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
signed main()
{
    IOS();
    int x1,x2,y1,y2,x3,y3,x,y;
    cin>>x1>>y1>>x2>>y2>>x3>>y3;
    int a=SQ(x1-x2)+SQ(y1-y2),b=SQ(x1-x3)+SQ(y1-y3);
    if(a==b) {
        x=x2+x3-x1;
        y=y2+y3-y1;
    }else if(a<b) {
        x=x1+x3-x2;
        y=y1+y3-y2;
    }else {
        x=x1+x2-x3;
        y=y1+y2-y3;
    }
    cout<<x<<" "<<y<<"\n";
    return 0;
}

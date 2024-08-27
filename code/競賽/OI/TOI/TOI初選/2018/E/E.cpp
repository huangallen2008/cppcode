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
int n;
int x,y;
vector<int> h;
vector<int> s(maxn*4,inf);
void it(int w,int l,int r) {
    if(l==r) {
        s[w]=h[l];
        return;
    }
    int m=(l+r)/2;
    it(w*2,l,m);
    it(w*2+1,m+1,r);
    s[w]=min(s[w*2],s[w*2+1]);
}
int q(int w,int l,int r,int ll,int rr) {
    if(ll<=l&&rr>=r) return s[w];
    if(ll>r||rr<l) return inf;
    int m=(l+r)/2;
    return min(q(w*2,l,m,ll,rr),q(w*2+1,m+1,r,ll,rr));
}
signed main()
{
    IOS();
    cin>>n;
    h=vector<int>(n);
    REP(i,n) cin>>h[i];
    it(1,0,n-1);
    REP(i,n) {
        cin>>x>>y;
        x--;y--;
        cout<<q(1,0,n-1,x,y)+1<<"\n";
    }
    return 0;
}

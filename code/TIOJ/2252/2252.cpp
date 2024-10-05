#include <bits/stdc++.h>
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
#define ld long double
const int inf=(1ll<<62)-1;
const int maxn=3e3+5;
const int mod=1e9+7;
ld dot(pii x,pii y) {
    return x.f*y.f+x.s*y.s;
}
pii dir(pii x,pii y) {
    return {y.f-x.f,y.s-x.s};
}
bool in(pii a,pii b,pii c) {
    return dot(dir(a,b),dir(a,c))>0&&dot(dir(b,a),dir(b,c))>0;
}
ld dis2(pii a,pii b) {
    return (ld)sqrt(SQ(b.f-a.f)+SQ(b.s-a.s));
}
ld dis1(int a,int b,int c,pii x) {
    return abs(a*x.f+b*x.s+c)/(ld)sqrt(SQ(a)+SQ(b));
}
main() {
    IOS();
    pii c0;
    int n;
    cin>>c0.f>>c0.s>>n;
    n++;
    vector<pii> c(n);
    ld an=2000000;
    REP(i,n) cin>>c[i].f>>c[i].s;
    REP(i,n-1) {
        if(in(c[i],c[i+1],c0))  {
            int x1=c[i].f,y1=c[i].s,x2=c[i+1].f,y2=c[i+1].s,x0=c0.f,y0=c0.s;
            an=min(an,(ld)dis1(y2-y1,x1-x2,(x2-x1)*y1+(y1-y2)*x1,c0));
//            an=min(an,(ld)SQ((y2-y1)*x0+(x1-x2)*y0+(x2-x1)*y1+(y1-y2)*x1)/(SQ(y2-y1)+SQ(x2-x1)));
        }
    }
    REP(i,n) an=min(an,(ld)dis2(c0,c[i]));
    cout<<fixed<<setprecision(15)<<an<<"\n";
    return 0;
}

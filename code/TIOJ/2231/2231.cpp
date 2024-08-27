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
const int inf=(1ll<<62)-1;
const int maxn=6e5+5;
const int mod=1e9+7;
vector<int> b,w,t,pb,pw;
pii mn(pii a,pii b) {
    if(a.f+a.s>b.f+b.s) return b;
    return a;
}
signed main()
{
    IOS();
    int n;
    cin>>n;
    b=vector<int>(n+1);
    w=vector<int>(n+1);
    t=vector<int>(n+1);
    pb=vector<int>(n+1);
    pw=vector<int>(n+1);
    REP1(i,n) cin>>b[i];
    REP1(i,n) cin>>w[i];
    REP1(i,n) cin>>t[i];
    REP1(i,n) pb[i]=pb[i-1]+b[i];
    REP1(i,n) pw[i]=pw[i-1]+w[i];
    vector<pii> dw(n+1),db(n+1);
    REP1(i,n-1) {
        dw[i]=mn({dw[i-1].f+w[i],max(dw[i-1].s-w[i],t[i])},{db[i-1].f+db[i-1].s+w[i],t[i]});
        db[i]=mn({db[i-1].f+b[i],max(db[i-1].s-b[i],t[i])},{dw[i-1].f+dw[i-1].s+b[i],t[i]});
    }
    int an=inf;
    REP(i,n) an=min(an,dw[i].f+dw[i].s+pb[n]-pb[i]);
    REP(i,n) an=min(an,db[i].f+db[i].s+pw[n]-pw[i]);
//    REP1(i,n) cout<<dw[i].f<<" "<<dw[i].s<<"\n";cout<<"\n\n\n";
//    REP1(i,n) cout<<db[i].f<<" "<<db[i].s<<"\n";cout<<endl;
    cout<<an<<"\n";
    return 0;
}

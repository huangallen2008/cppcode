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
const int inf=(1ll<<63)-1;
const int maxn=2e5+5;
const int mod=1e9+7;
struct rec {
    int x1,y1,x2,y2;
};
struct ord {
    int l,r,v;
};
vector<rec> recs;
vector<int> x,y;
vector<vector<ord>> od;
int an=0;
int n;
struct seg {
    int l,r;
    int m,ms;
    int t=0;
};
seg s[maxn*4];
void pull(seg &a,seg &b,seg &c) {
    a.l=b.l; a.r=c.r;
    a.m=min(b.m,c.m);
    a.ms=b.ms*(b.m==a.m)+c.ms*(c.m==a.m);
}
void push(seg &a,seg &b,seg &c) {
    if(a.t) {
        b.t+=a.t;
        b.m+=a.t;
        c.t+=a.t;
        c.m+=a.t;
        a.t=0;
    }
}
void build(int w,int l,int r) {
    if(l==r) {
        s[w]={l,r,0,x[l+1]-x[l],0};
        return;
    }
    int m=(l+r)/2;
    build(w*2,l,m);
    build(w*2+1,m+1,r);
    pull(s[w],s[w*2],s[w*2+1]);
}
void ud(int w,int l,int r,int val) {
    if(l<=s[w].l&&s[w].r<=r) {
        s[w].t+=val;
        s[w].m+=val;
        return;
    }
    if(l>s[w].r||r<s[w].l) return;
    push(s[w],s[w*2],s[w*2+1]);
    ud(w*2,l,r,val);
    ud(w*2+1,l,r,val);
    pull(s[w],s[w*2],s[w*2+1]);
}
signed main()
{
    IOS();
    int x1,y1,x2,y2;
    while(cin>>x1) {
//        if(x1==-1) break;
        cin>>y1>>x2>>y2;
        recs.pb({x1,y1,x2,y2});
        x.pb(x1);
        x.pb(x2);
        y.pb(y1);
        y.pb(y2);
    }
    n=recs.size();
    sort(ALL(x));
    sort(ALL(y));
    od=vector<vector<ord>>(y.size());
    REP(i,n) {
        recs[i].x1=lower_bound(ALL(x),recs[i].x1)-x.begin();
        recs[i].x2=lower_bound(ALL(x),recs[i].x2)-x.begin();
        recs[i].y1=lower_bound(ALL(y),recs[i].y1)-y.begin();
        recs[i].y2=lower_bound(ALL(y),recs[i].y2)-y.begin();
        od[recs[i].y1].pb({recs[i].x1,recs[i].x2-1,1});
        od[recs[i].y2].pb({recs[i].x1,recs[i].x2-1,-1});
//        cout<<recs[i].y1<<":"<<recs[i].x1<<"~"<<recs[i].x2-1<<" "<<1<<endl;
//        cout<<recs[i].y2<<":"<<recs[i].x1<<"~"<<recs[i].x2-1<<" "<<-1<<endl;
    }
    build(1,0,n*2-2);
//    cout<<"x:"; REP(i,x.size()) cout<<x[i]<<" ";cout<<endl;
//    cout<<"y:"; REP(i,y.size()) cout<<y[i]<<" ";cout<<endl;
    REP(i,od.size()-1) {
        for(auto [l,r,v]:od[i]) ud(1,l,r,v);
        an+=(x[2*n-1]-x[0]-(s[1].m==0)*s[1].ms)*(y[i+1]-y[i]);
//        cout<<an<<"\n";
    }
    cout<<an<<"\n";
    return 0;
}
/*
0 0 7 9
1 7 9 13
3 5 12 11
-1
*/

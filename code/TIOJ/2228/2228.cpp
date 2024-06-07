#include<bits/stdc++.h>
using namespace std;
#define ll long long
//#define int long long
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
const int maxn=6e5+5;
const int mod=1e9+7;
struct store {
    int x1,x2,y1,y2,w;
};
struct ln {
    int y1,y2,w;
};
struct seg {
    int v,t;
};
seg s[maxn*4];
void push(seg &a,seg &b,seg &c) {
    if(a.t) {
        b.v+=a.t;
        b.t+=a.t;
        c.v+=a.t;
        c.t+=a.t;
        a.t=0;
    }
}
void ud(int w,int l,int r,int ul,int ur,int v) {
    if(ul<=l&&r<=ur) {
        s[w].t+=v;
        s[w].v+=v;
        return;
    }
    if(ul>r||ur<l) return;
    int m=(l+r)/2;
    push(s[w],s[w*2],s[w*2+1]);
    ud(w*2,l,m,ul,ur,v);
    ud(w*2+1,m+1,r,ul,ur,v);
    s[w].v=max(s[w*2].v,s[w*2+1].v);
}
signed main()
{
    IOS();
    int n;
    int an=0;
    cin>>n;
    vector<int> x,y;
    vector<store> st;
    vector<vector<ln>> o(n*2+1);
    REP(i,n) {
        int x0,y0,r,w;
        cin>>x0>>y0>>r>>w;
        st.pb({x0+y0-r,x0+y0+r,y0-x0-r,y0-x0+r,w});
        x.pb(x0+y0-r);
        x.pb(x0+y0+r);
        y.pb(y0-x0-r);
        y.pb(y0-x0+r);
    }
    sort(ALL(x));
    sort(ALL(y));
    REP(i,n) {
        st[i].x1=lower_bound(ALL(x),st[i].x1)-x.begin();
        st[i].x2=lower_bound(ALL(x),st[i].x2)-x.begin();
        st[i].y1=lower_bound(ALL(y),st[i].y1)-y.begin();
        st[i].y2=lower_bound(ALL(y),st[i].y2)-y.begin();
        o[st[i].x1].pb({st[i].y1,st[i].y2,st[i].w});
        o[st[i].x2+1].pb({st[i].y1,st[i].y2,-st[i].w});
    }
    REP(i,n*2+1) {
        for(auto [y1,y2,w]:o[i]) ud(1,0,n*2-1,y1,y2,w);
        an=max(an,s[1].v);
    }
    cout<<an<<"\n";
    return 0;
}

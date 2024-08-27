#include<bits/stdc++.h>
using namespace std;
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
/*
l sort
next[]
seg
q
*/
struct Query {
    int l,r,id;
};
vector<int> buildnext(vector<int> a) {
    int n=a.size();
    vector<pii> s(1,{1e9+1,n});
    vector<int> nxt(n);
    RREP(i,n) {
        while(a[i]>s.back().f) s.pop_back();
        nxt[i]=s.back().s;
        s.pb({a[i],i});
    }
    return nxt;
}
struct Seg {
    int s=0;
    int t=0;
};
Seg s[4*maxn];
void ud(int w,int l,int r,int ll,int rr,int v) {
    if(ll<=l&&r<=rr) {
        s[w].t=v;
        s[w].s=v*(r-l+1);
        return;
    }
    if(l>rr||r<ll) return;
    int m=(l+r)/2;
    if(s[w].t) {
        s[w*2].t=s[w].t;
        s[w*2].s=s[w].t*(m-l+1);
        s[w*2+1].t=s[w].t;
        s[w*2+1].s=s[w].t*(r-m);
        s[w].t=0;
    }
    ud(w*2,l,m,ll,rr,v);
    ud(w*2+1,m+1,r,ll,rr,v);
    s[w].s=s[w*2].s+s[w*2+1].s;
}
int qu(int w,int l,int r,int ll,int rr) {
    if(ll<=l&&r<=rr) return s[w].s;
    if(l>rr||r<ll) return 0;
    int m=(l+r)/2;
    if(s[w].t) {
        s[w*2].t=s[w].t;
        s[w*2].s=s[w].t*(m-l+1);
        s[w*2+1].t=s[w].t;
        s[w*2+1].s=s[w].t*(r-m);
        s[w].t=0;
    }
    return qu(w*2,l,m,ll,rr)+qu(w*2+1,m+1,r,ll,rr);
}
signed main()
{
    IOS();
    int n,q;
    cin>>n>>q;
    vector<int> a(n),p(n);
    REP(i,n) cin>>a[i];
    p[0]=a[0];
    REP1(i,n-1) p[i]=p[i-1]+a[i];
    vector<vector<Query>> b(n);
    REP(i,q) {
        int x,y;
        cin>>x>>y;
        b[x-1].pb({x-1,y-1,i});
    }
    vector<int> next;
    next=buildnext(a);
    vector<int> an(q);
    RREP(i,n) {
        ud(1,0,n-1,i,next[i]-1,a[i]);
        REP(j,SZ(b[i])) {
            int l=b[i][j].l,r=b[i][j].r;
            an[b[i][j].id]=qu(1,0,n-1,l,r)-(p[r]-(l==0?0:p[l-1]));
        }
    }
    REP(i,q) cout<<an[i]<<"\n";
    return 0;
}

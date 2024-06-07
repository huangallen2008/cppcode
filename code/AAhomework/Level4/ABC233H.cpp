#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#define int long long
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
#define RREP(i,n) for(int i=(n)-1;i>=0;i--)
#define RREP1(i,n) for(int i=(n);i>=1;i--)
#define f first
#define s second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)(x.size())
#define SQ(x) (x)*(x)
#define pii pair<int,int>
#define pipii pair<int,pii>
#define Graph vector<vector<int>>
#define IOS() ios::sync_with_stdio(0),cin.tie(0)
#define md(x) (((x)%(mod)+(mod))%(mod))
#ifdef LOCAL
#define op(x) cout<<(#x)<<"="<<(x)<<", ";
#define ope(x) cout<<(#x)<<"="<<(x)<<endl;
#define oparr(x) cout<<(#x)<<":";REP(i,(x).size()) cout<<x[i]<<" ";cout<<" size="<<(x).size()<<endl;
#define entr cout<<endl;
#else
#define op(x) ;
#define ope(x) ;
#define oparr(x) ;
#define entr ;
#endif
const int mod=1e9+7;
const int maxn=2e5+5;
const int maxv=1e5+5;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
//shuffle(a,a+n,rng)
pii chan(pii p) { return {p.f+p.s+1,p.f-p.s+maxv+1}; }
struct BIT {
    vector<int> b;
    int n;
    void init(int _n) {
        n=_n;
        b=vector<int>(n+1);
    }
    void ud(int u,int v) {
        if(u<0||u>n) return;
        for(;u<=n;u+=u&-u) b[u]+=v;
    }
    int qu(int u) {
        if(u<=0) return 0;
        if(u>n) u=n;
        int an=0;
        for(;u>0;u-=u&-u) an+=b[u];
        return an;
    }
} bit;
int n,q;
struct Data {
    int u,ty,l,r,id;
    //0:update  1:qurey
};
bool so(Data a,Data b) {
    if(a.u==b.u) return a.ty<b.ty;
    return a.u<b.u;
}
bool finish(vector<int> &l,vector<int> &r) {
    REP(i,q) if(l[i]!=r[i]) return 0;
    return 1;
}
vector<Data> evnt[maxv<<1];
signed main() {
    IOS();
    cin>>n;
    vector<pii> ds(n);
    REP(i,n) cin>>ds[i].f>>ds[i].s;
    REP(i,n) {
        ds[i]=chan(ds[i]);
    }
    cin>>q;
    vector<int> l(q,0),r(q,maxv<<1),x(q),y(q),k(q);
    REP(i,q) {
        pii p;
        cin>>p.f>>p.s>>k[i];
        p=chan(p);
        x[i]=p.f,y[i]=p.s;
    }
    while(!finish(l,r)) {
        bit.init(maxv<<1);
        vector<int> mid(q),ret(q);
        REP(i,n) {
            evnt.pb({ds[i].f,0,ds[i].s,0,0});
        }
        REP(i,q) {
            if(l[i]==r[i]) continue;
            mid[i]=(l[i]+r[i])>>1;
            evnt.pb({x[i]-mid[i]-1,1,y[i]-mid[i],y[i]+mid[i],-i-1});
            evnt.pb({x[i]+mid[i],1,y[i]-mid[i],y[i]+mid[i],i});
        }
        sort(ALL(evnt),so);
        for(auto [u,ty,l,r,id]:evnt) {
            if(ty) {
                if(id>=0) ret[id]+=bit.qu(r)-bit.qu(l-1);
                else ret[-id-1]-=bit.qu(r)-bit.qu(l-1);
            }
            else {
                bit.ud(l,1);
            }
        }
        REP(i,q) {
            if(l[i]==r[i]) continue;
            if(ret[i]>=k[i]) r[i]=mid[i];
            else l[i]=mid[i]+1;
        }
    }
    REP(i,q) cout<<l[i]<<'\n';
    return 0;
}

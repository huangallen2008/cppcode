#include<bits/stdc++.h>
using namespace std;
// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,sse4,bmi2,popcnt")
#define int long long
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,n) for(int i=1;i<=(n);i++)
#define RREP(i,n) for(int i=(n)-1;i>=0;i--)
#define RREP1(i,n) for(int i=(n);i>=1;i--)
#define f first
#define s second
#define pb push_back
#define ALL(x) (x).begin(),(x).end()
#define SZ(x) (int)((x).size())
#define SQ(x) (x)*(x)
#define pii pair<int,int>
#define pipii pair<int,pii>
#define Graph vector<vector<int>>
#define Graphw vector<vector<pii>>
#define IOS() ios::sync_with_stdio(0),cin.tie(0)
#define md(x) (((x)%(mod)+(mod))%(mod))
#define MD(x,M) (((x)%(M)+(M))%(M))
#define ld long double
#define pdd pair<ld,ld>
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)
#define addmod(x,y) x=((x+(y))%mod)
#define Vi vector<int>
#define Vpii vector<pii>
#ifdef LOCAL
#define op(x) cout<<(#x)<<"="<<(x)<<", ";
#define ope(x) cout<<(#x)<<"="<<(x)<<endl;
#define oparr(x) {cout<<(#x)<<":";for(auto allen:(x)) cout<<allen<<" ";cout<<" size="<<(x).size()<<endl;}
#define entr cout<<endl;
#else
#define op(x) ;
#define ope(x) ;
#define oparr(x) ;
#define entr ;
#endif
template<typename T1,typename T2>
ostream& operator<<(ostream& os,pair<T1,T2> p) { return os<<'{'<<p.f<<','<<p.s<<'}'; }
template<typename T1,typename T2>
istream& operator>>(istream& os,pair<T1,T2> &p) { return os>>p.f>>p.s; }
template<typename S>
ostream& operator<<(ostream& os,vector<S> p) { for(auto allen:p) os<<allen<<' ';return os<<'\n'; }
template<typename S>
istream& operator>>(istream& os,vector<S> &p) { for(auto &allen:p) os>>allen;return os; }
template<typename T1,typename T2>
pair<T1,T2> operator+(pair<T1,T2> p1,pair<T1,T2> p2) { return pair<T1,T2>(p1.f+p2.f,p1.s+p2.s); }
const int mod=1e9+7;
const int maxn=5;
const int maxb=64;
const int inf=1ll<<60;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
int pw(int x,int p){
    int r=1;
    while(p>0) {
        if(p&1) r=r*x%mod;
        x=x*x%mod;
        p>>=1;
    }
    return r;
}
int inv(int x) {
    return pw(x,mod-2);
}
signed main() {
    IOS();
    int n,m,q;
    cin>>n>>m>>q;
    map<int,int> mp;
    mp[0]=mp[n]=0;
    REP(i,m) {
        int l,r;
        cin>>r>>l,l=n-l,r=n-r;
        mp[l]^=1;
        mp[r+1]^=1;
    }
    struct qur {
        int l,r,k;
    };
    vector<qur> qu(q);
    REP(i,q) cin>>qu[i].r>>qu[i].l>>qu[i].k,qu[i].l=n-qu[i].l,qu[i].r=n-qu[i].r;
    REP(i,q) mp[qu[i].l];
    int now=0,las=-1;
    Vpii a;
    for(auto [x,y]:mp) {
        // op(x)ope(y)
        if(las!=-1)a.pb({las,now?x-las:las-x});
        now^=y;
        las=x;
    }
    // oparr(a)
    int nn=a.size();
    Vi c(nn);
    {
        Vpii t(nn);
        REP(i,nn) t[i]={a[i].s,i};
        sort(ALL(t),greater<pii>()); 
        // oparr(t)
        c[t[0].s]=0;
        REP1(i,nn-1) {
            c[t[i].s]=c[t[i-1].s];
            if(t[i].f!=t[i-1].f) c[t[i].s]++;
        }
    }
    // oparr(c)
    for(int k=0;(1<<k)<=nn;k++) {
        vector<pair<pii,int>> t(nn);
        // ope(k)
        REP(i,nn) t[i]={{c[i],c[(i+(1<<k))%nn]},i};
        sort(ALL(t),greater<pair<pii,int>>()); 
        c[t[0].s]=0;
        REP1(i,nn-1) {
            c[t[i].s]=c[t[i-1].s];
            if(t[i].f!=t[i-1].f) c[t[i].s]++;
        }
    }
    // oparr(c)
    vector<Vpii> st(20,Vpii(nn));
    REP(i,nn) st[0][i]={c[i],i};
    REP1(i,19) {
        REP(j,nn) {
            st[i][j]=min(st[i-1][j],st[i-1][min(j+(1<<i-1),nn-1)]);
        }
    }
    auto st_qu=[&](int l,int r) ->int {
        int lg=__lg(r-l+1);
        return min(st[lg][l],st[lg][r-(1<<lg)+1]).s;
    };
    Vi ps(nn);
    REP(i,nn) {
        // if(a[i].s>=0) ope(pw(2,a[i].f+abs(a[i].s)-1)-(a[i].f?pw(2,a[i].f-1):0))
        ps[i]=(i?ps[i-1]:0)+(a[i].s<0?0:pw(2,a[i].f+abs(a[i].s))-(pw(2,a[i].f)));
    }
    oparr(ps)
    oparr(a)
    auto gps=[&](int x) ->int{
        if(x<0) return 0;
        int id=upper_bound(ALL(a),pii{x,inf})-a.begin()-1;
        int ext=(a[id].s<0?0:pw(2,x+1)-(pw(2,a[id].f)));
        op(x)op(id)ope(ext)
        return ((id?ps[id-1]:0)+ext)%mod;
    };
    auto gh=[&](int l,int r) {
        return ((gps(r)-gps(l-1))%mod)*inv(pw(2,l))%mod;
    };
    oparr(c)
    REP(i,n) ope(gps(i))
    REP(i,q) {
        op(i)ope("!!!!!!!")
        op(qu[i].l)ope(qu[i].r)
        int lid=lower_bound(ALL(a),pii{qu[i].l,-inf})-a.begin();
        int rid=upper_bound(ALL(a),pii{qu[i].r-qu[i].k+1,inf})-a.begin()-1;
        op(lid)ope(rid)
        int id=st_qu(lid,rid);
        op("qu")op(i)ope(id)
        int an=gh(a[id].f,a[id].f+qu[i].k-1);
        cout<<an<<'\n';
    }
    return 0;
}
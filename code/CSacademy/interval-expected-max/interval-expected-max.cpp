#include<bits/stdc++.h>
using namespace std;
// #pragma GCC optimize("Ofast,unroll-loops,fast-math")
// #pragma GCC target("avx2,sse4,bmi,popcnt")
#define int long long
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,n) for(int i=1;i<=(n);i++)
#define RREP(i,n) for(int i=(n)-1;i>=0;i--)
#define RREP1(i,n) for(int i=(n);i>=1;i--)
#define f first
#define s second
#define pb push_back
#define ALL(x) (x).begin(),(x).end()
#define ALL1(x) (x).begin()+1,(x).end()
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
#ifdef LOCAL
#define op(x) cout<<(#x)<<"="<<(x)<<", ";
#define ope(x) cout<<(#x)<<"="<<(x)<<endl;
#define oparr(x) cout<<(#x)<<":";for(auto &mken:(x)) cout<<mken<<" ";cout<<" size="<<(x).size()<<endl;
#define entr cout<<endl;
#else
#define op(x) ;
#define ope(x) ;
#define oparr(x) ;
#define entr ;
#endif
const int mod=30011;
const int maxn=1e5+5;
const int sn=300;
const int inf=(1ll<<62); 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
struct BIT {
    int n;
    Vi b;
    void init(int _n) {
        n=_n;
        b=Vi(n+1);
    } 
    void ud(int u,int v) {
        for(;u<=n;u+=u&-u) b[u]+=v;
    }
    int pre(int u) {
        int r=0;
        for(;u>0;u-=u&-u) r+=b[u];
        return r;
    }
    int qu(int l,int r) {
        return pre(r)-pre(l-1);
    }
};
struct SOL {
    BIT bit,bitv;
    Vi a,v;
    int n;
    int an=0;
    int sum=0;
    void init(int _n,Vi _a) {
        n=_n;
        v=a=_a;
        Vi t=a;
        sort(ALL(t));
        for(int &x:a) x=(lower_bound(ALL(t),x)-t.begin())+1;
        bit.init(n);
        bitv.init(n);
    }
    void add(int u) {
        bit.ud(a[u],1);
        bitv.ud(a[u],v[u]);
        an+=bit.pre(a[u])*v[u]+bitv.qu(a[u]+1,n);
        sum+=v[u];
        op("add")op(u)ope(an)
    }
    void del(int u) {
        an-=bit.pre(a[u])*v[u]+bitv.qu(a[u]+1,n);
        bitv.ud(a[u],-v[u]);
        bit.ud(a[u],-1);
        sum-=v[u];
        op("del")op(u)ope(an)
    }
    int getan() { op(an)ope(sum)return an*2+sum; }
};
Vi ss(maxn);
void init_ss() {
    REP(i,maxn) ss[i]=i/sn;
}
struct MO {
    int n;
    struct qur {
        int l,r,id;
    };
    SOL sol;
    vector<qur> q;
    Vi an;
    int Q;
    void solve(int _n,int _Q,Vi a,vector<pii> _qu) {
        n=_n;
        Q=_Q;
        q=vector<qur>(Q);
        an=Vi(Q);
        REP(i,Q) q[i]={_qu[i].f,_qu[i].s,i};
        sort(ALL(q),[&](qur a,qur b) {
            if(ss[a.l]!=ss[b.l]) return ss[a.l]<ss[b.l];
            return ss[a.l]&1?a.r<b.r:a.r>b.r;
        });
        sol.init(n,a);
        int l=0,r=0;
        for(auto [nl,nr,id]:q) {
            while(l>nl) sol.add(l--);
            while(r<nr) sol.add(r++);
            while(l<nl) sol.del(++l);
            while(r>nr) sol.del(--r);
            an[id]=sol.getan();
        }
    }
    Vi getan() { return an; }
}mo;
signed main() {
    IOS();
    init_ss();
    int n,q;
    cin>>n>>q;
    Vi a(n);
    REP(i,n) cin>>a[i];
    vector<pii> qu(q);
    REP(i,q) cin>>qu[i].f>>qu[i].s;
    mo.solve(n,q,a,qu);
    Vi an=mo.getan();
    REP(i,q) cout<<an[i]<<' ';
    cout<<'\n';
    return 0;
}
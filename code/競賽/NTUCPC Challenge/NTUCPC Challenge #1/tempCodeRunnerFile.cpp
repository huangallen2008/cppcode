#include<bits/stdc++.h>
using namespace std;
<<<<<<< HEAD
#pragma GCC optimize("O3,unroll-loops,fast-math")
// #pragma GCC target("avx2,sse4,bmi,popcnt")
#define int long long
// #define ll long long
=======
#pragma GCC optimize("O0,unroll-loops,fast-math")
// #pragma GCC target("avx2,bmi,popcnt")
#define int long long
>>>>>>> 0b1a1b11a3c05bbc53306c9c4fc912c08c4ad5ba
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
<<<<<<< HEAD
#ifdef LOCAL_
=======
#ifdef LOCAL
>>>>>>> 0b1a1b11a3c05bbc53306c9c4fc912c08c4ad5ba
#define op(x) cout<<(#x)<<"="<<(x)<<", ";
#define ope(x) cout<<(#x)<<"="<<(x)<<endl;
#define oparr(x) cout<<(#x)<<":";for(auto &allen:(x)) cout<<allen<<" ";cout<<" size="<<(x).size()<<endl;
#define entr cout<<endl;
#else
#define op(x) ;
#define ope(x) ;
#define oparr(x) ;
#define entr ;
#endif
const int mod=1e9+7;
<<<<<<< HEAD
const int maxn=1e5+5;
const int maxc=512;
=======
const int maxn=2e5+5;
>>>>>>> 0b1a1b11a3c05bbc53306c9c4fc912c08c4ad5ba
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
<<<<<<< HEAD
struct DS {
    map<int,int> mp;
    int sum=0;
    void init() {
        mp.clear();
        sum=0;
        mp[0]=inf,mp[inf]=0;
    }
    void ins(int x,int y) {
        auto it=mp.lower_bound(x);
        if(it->s>=y) {
            return;
        }
        if(it->f!=x) {
            mp[x]=it->s;
        }
        auto it_r=mp.find(x);
        it=it_r;
        while(it->s<=y) {
            // op(it->f)op(it->s)op(prev(it)->f)ope(prev(it)->s)
            sum+=(y-it->s)*(it->f-prev(it)->f);
            it=prev(it);
        }
        mp.erase(next(it),it_r);
        mp[x]=y;
        // for(auto &[x,y]:mp) {
        //     cout<<"{"<<x<<','<<y<<"} ";
        // }entr
    }
}d1,d2,d3,d4;
struct DSU {
    vector<int> p,sz;
    int cc=0,n=0;
    void init(int _n) {
        n=_n;
        p=vector<int>(n);
        sz=vector<int>(n,1);
        REP(i,n) p[i]=i;
        cc=n;
    }
    int find(int u) {
        return p[u]==u?u:p[u]=find(p[u]);
    }
    void merge(int a,int b) {
        int x=find(a),y=find(b);
        if(x==y) return;
        p[x]=y;
        sz[y]+=sz[x];
        cc--;
    }
}dsu;
int n,m;
int id(int a,int b) {
    return (a-1)*m+b-1;
}
bool nok(int x,int y) {
    return x<=0||y<=0||x>n||y>m;
}
signed main() {
    IOS();
    cin>>n>>m;
    int N=n*m;
    vector<pii> a(N);
    vector<vector<int>> b(n+1,vector<int>(m+1));
    REP1(i,n) {
        REP1(j,m) {
            int x;
            cin>>x,x--;
            a[x]={i,j};
            b[i][j]=x;
        }
    }
    int q;cin>>q;
    REP(rd,q+1) {
        dsu.init(N);
        d1.init(),d2.init(),d3.init(),d4.init();
        vector<pii> dir={{0,1},{0,-1},{1,0},{-1,0}};
        int mxy=0,mny=inf,mxx=0,mnx=inf;
        vector<vector<bool>> used(n+1,vector<bool>(m+1));
        int an=0;
        REP(i,N) {
            auto [x,y]=a[i];
            chmin(mny,y);
            chmin(mnx,x);
            chmax(mxy,y);
            chmax(mxx,x);
            int ix=n+1-x,iy=m+1-y;
            d1.ins(x,y);
            d2.ins(ix,y);
            d3.ins(x,iy);
            d4.ins(ix,iy);
            for(auto [dx,dy]:dir) {
                int nx=x+dx,ny=y+dy;
                if(nok(nx,ny)||!used[nx][ny]) continue;
                dsu.merge(id(x,y),id(nx,ny));
            }
            used[x][y]=1;
            // op(x)ope(y)
            int sum=d1.sum+d2.sum+d3.sum+d4.sum;
            
            int dy=mxy-mny+1,dx=mxx-mnx+1;
            op(d1.sum)op(d2.sum)op(d3.sum)ope(d4.sum)
            op(dx)op(dy)op(sum)op(dsu.cc)entr entr
            if(sum-N-(n*dy)-m*dx==i+1&&dsu.cc==N-i) {
                an++;
            }
        }
        cout<<an<<'\n';
        if(rd<q) {
            int x1,y1,x2,y2;
            cin>>x1>>y1>>x2>>y2;
            swap(b[x1][y1],b[x2][y2]);
            swap(a[b[x1][y1]],a[b[x2][y2]]);
        }
    }
=======
pii mc(int x,int y,int k) {
    bool inv=x<y;
    if(inv) swap(x,y);
    if(x==1) return {k,0};
    int t=x/y,z=x-t*y;
    pii ret=mc(y,z,k);
    ret={ret.s,ret.f-ret.s*t};
    if(inv) swap(ret.s,ret.f);
    // if(!inv){op(x)op(y)op(ret.f)op(ret.s)op(ret.f*x+ret.s*y)ope(k)}
    // else{op(x)op(y)op(ret.f)op(ret.s)op(ret.f*y+ret.s*x)ope(k)}
    return ret;
}
void solve() {
    int n,m,a,b,k;
    cin>>n>>m>>a>>b>>k;
    if(a*n+b*m<k) {
        cout<<n+m<<'\n';
        return;
    }
    if(a<b) swap(a,b),swap(n,m);
    int gcd=__gcd(a,b);
    bool ok=1;
    pii ret;
    if(k%gcd==0) {
        a/=gcd,b/=gcd,k/=gcd;
        ret=mc(a,b,k);
        if(ret.f<0) {
            int t=(b-1-ret.f)/b;
            ret.f+=b*t,ret.s-=a*t;
            if(ret.s<0) {
                ok=0;
            }
        }
        else if(ret.s<0){
            int t=(a-1-ret.s)/a;
            ret.s+=a*t,ret.f-=b*t;
            if(ret.f<0) {
                ok=0;
            }
        }
    }
    else ok=0;
    if(!ok) {
        cout<<n+m<<'\n';
        return;
    }
    assert(ret.f>=0);
    assert(ret.s>=0);
    pii amn,bmn;
    {
        int t=min((ret.f)/b,m/a+1);
        assert(t>=0&&a>=0&&b>=0);
        amn={ret.f-b*t,ret.s+a*t};
    }
    {
        int t=min(ret.s/a,n/b+1);
        assert(t>=0&&a>=0&&b>=0);
        bmn={ret.f+b*t,ret.s-a*t};
    }
    // assert(amn.f<=bmn.f);
    // assert(bmn.s<=amn.s);
    // op(amn.f)op(amn.s)op(bmn.f)op(bmn.s)entr
    int l=0,r=(n*a+m*b)/k,mid;
    while(l<r) {
        mid=l+r+1>>1;
        pii now={amn.f*mid,amn.s*mid};
        if(now.f>n||bmn.s*mid>m) {
            r=mid-1;
            continue;
        }
        // if(now.s<bmn.s*mid) {
        //     r=mid-1;
        //     continue;
        // }
        if(now.s<=m) {
            l=mid;
            continue;
        }
        // op(now.f)op(now.s)
            int t=(now.s-m+a-1)/a;
            now={now.f+t*b,now.s-t*a};
            // assert(now.s<=m);
        // op(now.f)ope(now.s)
        if(now.f<=n&&now.s>=bmn.s*mid) {
            l=mid;
        }
        else r=mid-1;
    }
    int ans=inf;
    // int rr=(amn.s==0?0:a/amn.s+5);
    // op(a)ope(amn.s)
    vector<bool> ro(a);
    r0[0]=1;
    REP1(i,a-1) ro[i]=rd(0,3);
    for(int ll=l;ll>=0&&ll>=l-a;ll--) {
        pii now={amn.f*ll,amn.s*ll};
        if(now.s>m) {
            int t=(now.s-m+a-1)/a;
            now={now.f+t*b,now.s-t*a};
        }
        // assert(now.f<=n);
        // assert(now.f>=ll*amn.f);
        // assert(now.s<=m);
        // assert(now.s>=ll*bmn.s);
        // assert(now.f*a+now.s*b==k*ll);
        int an=n+m-now.f-now.s;
        chmin(ans,an);
    }
    cout<<ans<<'\n';
}
signed main() {
    IOS();
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    int T;
    cin>>T;
    while(T--) solve();
>>>>>>> 0b1a1b11a3c05bbc53306c9c4fc912c08c4ad5ba
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops,fast-math")
// #pragma GCC target("avx2,sse4,bmi,popcnt")
#define int long long
// #define ll long long
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
#ifdef LOCAL_
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
const int maxn=1e5+5;
const int maxc=512;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
struct DS {
    map<int,int> mp;
    int sum=0;
<<<<<<< HEAD
    void init() {
        mp.clear();
        sum=0;
=======
    DS() {
>>>>>>> 0b1a1b11a3c05bbc53306c9c4fc912c08c4ad5ba
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
<<<<<<< HEAD
    vector<pii> a(N);
    vector<vector<int>> b(n+1,vector<int>(m+1));
=======
    dsu.init(N);
    vector<pii> a(N);
>>>>>>> 0b1a1b11a3c05bbc53306c9c4fc912c08c4ad5ba
    REP1(i,n) {
        REP1(j,m) {
            int x;
            cin>>x,x--;
            a[x]={i,j};
<<<<<<< HEAD
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
        }
    }
    // int q;cin>>q;assert(q==0);
    vector<pii> dir={{0,1},{0,-1},{1,0},{-1,0}};
    int mxy=0,mny=inf,mxx=0,mnx=inf;
    int an=0;
    vector<vector<bool>> used(n+1,vector<bool>(m+1));
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

            ope(i)
        }

    }
    cout<<an<<'\n';
>>>>>>> 0b1a1b11a3c05bbc53306c9c4fc912c08c4ad5ba
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
// #pragma GCC optimize("O3,unroll-loops,fast-math")
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
const int mod=998244353;
const int maxn=1e7+5;
const int maxb=20;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
struct BIT2 {
    struct ord {
        int a,b,c;
    };
    vector<ord> stk;
    vector<Vi> b;
    int n;
    void init(int _n) {
        n=_n;
        b=vector<Vi>(n+1,Vi(n+1));
    }
    void ud(int x,int y,int v) {
        stk.pb({x,y,v});
        x++,y++;
        // chmin(x,n);
        // chmin(y,n);
        for(int p=x;p<=n;p+=p&-p) {
            for(int q=y;q<=n;q+=q&-q) {
                b[p][q]+=v;
            }
        }
    }
    int qu(int x,int y) {
        x++,y++;
        // op(x)ope(y)
        // chmin(x,n);
        // chmin(y,n);
        int r=0;
        for(int p=x;p>0;p-=p&-p) {
            for(int q=y;q>0;q-=q&-q) {
                r+=b[p][q];
            }
        }
        return r;
    }
    int qu(int x1,int x2,int y1,int y2)  {
        return qu(x2,y2)-qu(x1-1,y2)-qu(x2,y1-1)+qu(x1-1,y1-1);
    }
    void clean() {
        for(auto [x,y,v]:stk) {
            ud(x,y,-v);
        }
        stk.clear();
    }
}bit;
void solve(int C) {
    cout<<"Case #"<<C<<": ";
    int r,c,k;
    cin>>r>>c>>k;
    bit.init(max(r,c));
    vector<Vi> a(r,Vi(c));
    vector<vector<pii>> b(r*c);
    REP(i,r) {
        REP(j,c) {
            cin>>a[i][j],a[i][j]--;
            b[a[i][j]].pb({i,j});
        }
    }
    int lb=0,rb=max(r,c),mb;
    while(lb<rb) {//fir mb that r >= k 
        mb=lb+rb+1>>1;
        int re=0;//number of val <= mb 
        REP(i,r*c) {
            for(auto &[x,y]:b[i]) {
                bit.ud(x,y,1);
            }
            for(auto &[x,y]:b[i]) {
                int x1=max(x-mb,0ll),x2=min(x+mb,r-1);
                int y1=max(y-mb,0ll),y2=min(y+mb,c-1);
                // op(x1)op(x2)op(y1)ope(y2)
                re+=(x2-x1+1)*(y2-y1+1)-bit.qu(x1,x2,y1,y2);
                // op(i)ope(re)
            }
            // for(auto &[x,y]:b[i]) bit.ud(x,y,-1);
            // ope(i)
            bit.clean();
        }
        // op(mb)ope(r)
        if(re>=k) lb=mb;
        else rb=mb-1;
    }
    cout<<lb<<'\n';
}
signed main() {
    IOS(); 
    #ifdef LOCAL_
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    int T;
    cin>>T;
    REP1(i,T) solve(i);
    return 0;
}
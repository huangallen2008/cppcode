#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
//#define int long long
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
#define MD(x,M) (((x)%(M)+(M))%(M))
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
struct SEG {
    vector<int> s;
    void init(int n) {
        s=vector<int>(n<<2);
    }
    void ud(int w,int l,int r,int u,int v) {
        if(l==r) {
            s[w]=v;
            return;
        }
        int m=(l+r)>>1;
        if(u<=m) ud(w<<1,l,m,u,v);
        else ud(w<<1|1,m+1,r,u,v);
        s[w]=max(s[w<<1],s[w<<1|1]);
    }
    int qu(int w,int l,int r,int ql,int qr) {
        if(ql<=l&&r<=qr) return s[w];
        if(ql>r||qr<l) return -inf;
        int m=(l+r)>>1;
        return max(qu(w<<1,l,m,ql,qr),qu(w<<1|1,m+1,r,ql,qr));
    }
} seg;
signed main() {
    IOS();
    int n;
    cin>>n;
    seg.init(n);
    map<int,int> ind_b;//val a->index b
    vector<int> a(n),b(n),indx(n);//index a->index b
    REP(i,n) cin>>a[i];
    REP(i,n) cin>>b[i];
    reverse(ALL(a));
    reverse(ALL(b));                //!!  reverse reverse reverse
    REP(i,n) ind_b[b[i]]=i;
    REP(i,n) indx[i]=ind_b[a[i]];

    vector<int> dp(n);
    vector<vector<int>> lev(n+1);
    REP(i,n) {
        dp[i]=seg.qu(1,0,n-1,0,indx[i]-1)+1;
        lev[dp[i]].pb(i);
        seg.ud(1,0,n-1,indx[i],dp[i]);
    }
    int ans=0;
    REP(i,n) ans=max(ans,dp[i]);
    int ita=n,itb=n;
    vector<int> an;
    RREP1(i,ans) {
        int maxc=0,maxi=0;
        for(auto v:lev[i]) {
            if(indx[v]>itb||v>ita) continue;
            if(a[v]==maxc) {
                if(v>maxi) {
                    maxi=v;
                    maxc=a[v];
                }
            }
            else if(a[v]>maxc) {
                maxc=a[v];
                maxi=v;
            }
        }
        itb=indx[maxi];
        ita=maxi;
        an.pb(maxc);
    }
    REP(i,an.size()) cout<<an[i]<<' ';
    cout<<'\n';
    return 0;
}

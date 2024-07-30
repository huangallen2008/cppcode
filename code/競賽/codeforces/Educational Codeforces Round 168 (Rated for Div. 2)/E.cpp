#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops,fast-math")
// #pragma GCC target("avx2,bmi,popcnt")
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
#ifdef LOCAL
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
const int maxn=1e4+5;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
struct BIT {
    vector<int> b;
    int n;
    void init(int _n) {
        n=_n;
        b=vector<int>(n+1);
    }
    void ud(int u,int v) {
        for(;u<=n;u+=u&-u) b[u]+=v;
    }
    int pre(int u) {
        int r=0;
        for(;u>0;u-=u&-u) r+=b[u];
        return r;
    }
    int sum() {
        return pre(n);
    }
    int qu(int k,int ba) {
        k+=pre(ba);
        int id=0;
        int lg=__lg(n);
        for(int i=lg;i>=0;i--) {
            if(b[id+(1<<i)]<k) {
                id+=1<<i;
                k-=b[id];
            }
        }
        return id+1;
    }
    int val(int u) {
        return pre(u)-pre(u-1);
    }
}bit;
vector<vector<int>> id; 
void solve() {
    int n,q;
    cin>>n>>q;
    bit.init(n);
    vector<int> a(n+1);
    id=vector<vector<int>>(n);
    REP1(i,n) cin>>a[i];
    REP1(i,n) {
        if(a[i]<n) id[a[i]].pb(i);
    }
    vector<vector<pii>> qu(n); 
    REP(i,q) {
        int u,x;
        cin>>u>>x;
        qu[x].pb({u,i});
    }
    vector<vector<int>> la(n+1,vector<int>(1));
    int resok=n;
    REP1(i,n) {
        ope(i)
        if(a[i]>=n) continue;
        int res=id[a[i]].size()-1;
        for(int x=resok;x>0;x--) {
            if(bit.sum()-bit.pre(la[x].back())<x) {
                resok--;
                continue;
            }
            int ret=bit.qu(x,la[x].back());
            la[x].pb(ret);
            while(res>0&&id[a[i]][res]>ret) {
                bit.ud(id[a[i]][res--],-1);
            }
        }
    }
    vector<bool> an(q);
    REP1(x,n) {
        ope(x)
        for(auto [u,id]:qu[x]) {
            if(a[u]>=la[x].size()) an[id]=1;
            else {
                if(u>la[x][a[u]]) an[id]=1;
                else an[id]=0;
            }
        }
    }
    REP(i,q) {
        if(an[i]) cout<<"YES\n";
        else cout<<"NO\n";
    }
}
signed main() {
    IOS();
    // int T;
    // cin>>T;
    // while(T--) 
    solve();
    return 0;
}
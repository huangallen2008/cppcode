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
#define op(x) cout<<#x<<"="<<x<<", ";
#define ope(x) cout<<#x<<"="<<x<<endl;
#define oparr(x) cout<<#x<<":";REP(i,x.size()) cout<<x[i]<<" ";cout<<" size="<<x.size()<<endl;
#define entr cout<<endl;
#else
#define op(x) ;
#define ope(x) ;
#define oparr(x) ;
#define entr ;
#endif
const int mod=998244353;
const int maxn=2e5+5;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
//shuffle(a,a+n,rng)
int pw(int x,int p) {
    int r=1;
    while(p>0) {
        if(p&1) {
            r*=x;
            r%=mod;
        }
        x*=x;
        x%=mod;
        p>>=1;
    }
    return r;
}
int inv(int x) {
    return pw(x,mod-2);
}
bool ised(int x,int y) {
    int k=x^y;
    int cnt=0;
    while(k>0) {
        cnt+=k&1;
        k>>=1;
    }
    return cnt<=2;
}
vector<int> iv;
struct DSU {
    vector<int> p,v,deg,sz,a;
    vector<bool> added;
    int n;
    void init(int _n,vector<int> &_a) {
        a=_a;
        n=_n;
        p=vector<int>(n);
        v=vector<int>(n);
        sz=vector<int>(n,1);
        deg=vector<int>(n);
        added=vector<bool>(n);
        REP(i,n) p[i]=i;
    }
    int find(int u) {
        if(p[u]==u) return u;
        return p[u]=find(p[u]);
    }
    void merge(int a,int b) {
        int x=find(a),y=find(b);
        if(x==y) return ;
        if(sz[x]>sz[y]) swap(x,y);
        p[x]=y;
        sz[y]+=sz[x];
        v[y]=md(v[x]*v[y]);
    }
    void upd(int u) {//deg[u]+1 ud v[x]
        int x=find(u);
//        ope(x)
        if(deg[u]>0)v[x]=md(md(v[x]*(deg[u]+1))*iv[deg[u]]);
        else v[x]=1;
//        ope(x)
        deg[u]++;
    }
    void add(int u) {// add node
        vector<int> to;
        REP(i,n) {
//            ope(i)
            if(!added[i]) continue;
            if(ised(a[u],a[i])) {
                upd(i);
                to.pb(i);
            }
        }
        int t=a[u];
        REP(c1,20) {
            REP(c2,20) {

            }
        }

        added[u]=1;
//        op(u)oparr(to)
        deg[u]=to.size();
        v[u]=deg[u];
        for(int &v:to) merge(u,v);
//        oparr(v)
    }
    int get_an() {
//        oparr(p)
        int ans=0;
        REP(i,n) if(p[i]==i&&sz[i]>1) ans=md(ans+v[i]);
        return ans;
    }
}dsu;
signed main() {
    IOS();
    int n;
    cin>>n;
    iv=vector<int>(n+1);
    REP1(i,n) iv[i]=inv(i);
    vector<int> a(n);
    REP(i,n) cin>>a[i];
    vector<int> d(n);
    REP(i,n) {
        cin>>d[i];
        d[i]--;
    }
    reverse(ALL(d));
    vector<int> an;
    dsu.init(n,a);
    for(int x:d) {
        dsu.add(x);
        an.pb(dsu.get_an());
    }
    reverse(ALL(an));
    for(int x:an) {
        cout<<x<<'\n';
    }
    return 0;
}

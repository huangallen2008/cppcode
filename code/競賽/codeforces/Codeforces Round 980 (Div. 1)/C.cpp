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
const int mod=1e9+7;
const int maxn=5;
const int maxb=20;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
Graph ga,gb;
Vi depa,depb,a,b;
int ma,mb;
int n,k;
void dfsa(int u) {
    for(int v:ga[u]) {
        if(depa[v]!=-1) continue;
        depa[v]=depa[u]+1;
        dfsa(v);
    }
}
void dfsb(int u) {
    for(int v:gb[u]) {
        if(depb[v]!=-1) continue;
        depb[v]=depb[u]+1;
        dfsb(v);
    }
}
int pw(int x,int f) {
    int r=1;
    while(f>0) {
        if(f&1) r=r*x%k;
        x=x*x%k;
        f>>=1;
    }
    return r;
}
const int C=48763;
void solve() {
    cin>>n>>k;
    a=b=Vi(n);
    depa=depb=Vi(n,-1);
    ga=gb=Graph(n);
    REP(i,n) cin>>a[i];
    cin>>ma;
    REP(i,ma) {
        int u,v;
        cin>>u>>v,u--,v--;
        ga[u].pb(v);
    }
    REP(i,n) cin>>b[i];
    cin>>mb;
    REP(i,mb) {
        int u,v;
        cin>>u>>v,u--,v--;
        gb[u].pb(v);
    }
    int cnta0=0,cntb1=0;
    REP(i,n) cnta0+=a[i]==0;
    REP(i,n) cntb1+=b[i]==1;
    if(cnta0!=cntb1) {
        cout<<"NO\n";
        return;
    }
    dfsa(0);
    dfsb(0);
    REP(i,n) depa[i]=(depa[i]%k+k)%k;
    REP(i,n) depb[i]=(depb[i]%k+k)%k;
    Vi oa,ob,ia,ib;
    REP(i,n) {
        if(a[i]) oa.pb(depa[i]);
        else ia.pb(depa[i]);
    }
    REP(i,n) {
        if(b[i]) ob.pb(depb[i]);
        else ib.pb(depb[i]);
    }
    sort(ALL(oa));
    sort(ALL(ob));
    sort(ALL(ia));
    sort(ALL(ib));
    Vi doa,dob,dia,dib;
    doa=dob=dia=dib={0};
    REP(i,oa.size()) {
        doa.pb(((oa[(i+1)%oa.size()]-oa[i])%k+k)%k);
    }
    REP(i,ob.size()) {
        dob.pb(((ob[(i+1)%ob.size()]-ob[i])%k+k)%k);
    }
    REP(i,ia.size()) {
        dia.pb(((ia[(i+1)%ia.size()]-ia[i])%k+k)%k);
    }
    REP(i,ob.size()) {
        dib.pb(((ib[(i+1)%ib.size()]-ib[i])%k+k)%k);
    }
    int oas=doa.size()-1;
    int ias=dia.size()-1;
    int obs=dob.size()-1;
    int ibs=dib.size()-1;
    {
        Vi t=doa;t.erase(t.begin());
        for(int x:t) doa.pb(x);
    }
    {
        Vi t=dob;t.erase(t.begin());
        for(int x:t) dob.pb(x);
    }
    {
        Vi t=dia;t.erase(t.begin());
        for(int x:t) dia.pb(x);
    }
    {
        Vi t=dib;t.erase(t.begin());
        for(int x:t) dib.pb(x);
    }
    int N=n*2+1;
    REP1(i,doa.size()-1) doa[i]=(doa[i-1]+doa[i]*pw(C,i))%k;
    REP1(i,dob.size()-1) dob[i]=(dob[i-1]+dob[i]*pw(C,i))%k;
    REP1(i,dia.size()-1) dia[i]=(dia[i-1]+dia[i]*pw(C,i))%k;
    REP1(i,dib.size()-1) dib[i]=(dib[i-1]+dib[i]*pw(C,i))%k;
    unordered_map<int,int> moa,mia;
    REP(i,doa.size()-oas) moa[((doa[i+oas]-doa[i])*pw(C,N-i)%k+k)%k]=i+1;
    REP(i,dia.size()-ias) mia[((dia[i+ias]-dia[i])*pw(C,N-i)%k+k)%k]=i+1;
    Vi iaok,oaok;
    REP(i,dob.size()-obs) if(mia[((dob[i+obs]-dob[i])*pw(C,N-i)%k+k)%k]) iaok.pb(((i+1-mia[((dob[i+obs]-dob[i])*pw(C,N-i)%k+k)%k])%k+k)%k);
    REP(i,dib.size()-ibs) if(moa[((dib[i+ibs]-dib[i])*pw(C,N-i)%k+k)%k]) oaok.pb(((i+1-moa[((dib[i+ibs]-dib[i])*pw(C,N-i)%k+k)%k])%k+k)%k);
    // oparr(iaok)oparr(oaok)
    unordered_map<int,int> oo;
    for(int x:iaok) oo[((k-2-x)%k+k)%k]=1;
    bool an=0;
    for(int x:oaok) if(oo[x]) an=1;
    if(an) cout<<"YES\n";
    else cout<<"NO\n";
}
signed main() {
    IOS(); 
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}
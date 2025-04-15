#include<bits/stdc++.h>
using namespace std;
#define int long long
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,n) for(int i=1;i<=(n);i++)
#define pb push_back
#define pii pair<int,int>
#define f first
#define s second
#define Vi vector<int>
#define Vpii vector<pii>
#define SZ(x) ((int)((x).size()))
#define ALL(x) (x).begin(),(x).end()
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)
const int inf=(1ll<<60);
#ifdef LOCAL
#define op(x) cout<<(#x)<<'='<<(x)<<", ";
#define ope(x) cout<<(#x)<<"="<<(x)<<endl;
#define oparr(x) {cerr<<(#x)<<": ";for(auto allen:x) cout<<(allen)<<' ';cout<<endl;}
#define entr cout<endl;
#else
#define op(x) ;
#define ope(x) ;
#define oparr(x) ;
#define entr ;
#endif
std::vector<long long> maximum_profit(const std::vector<signed> &A, const std::vector<signed> &Q) {
    // ope("ok")
    int n=SZ(A),m=SZ(Q);
    Vi a(n),q(m);
    REP(i,n) a[i]=A[i];
    REP(i,m) q[i]=Q[i];


    Vi an;
    int alan=0;
    REP(i,n) alan+=abs(a[i]);
    ope(alan)
    an.pb(alan);
    int cnt=0;
    auto sig=[&](int x) { return x>=0; };
    set<int> res;
    REP(i,n) res.insert(i);
    for(int i=n-1;i>=0;i--) {
        if(i!=n-1&&sig(a[i])==sig(a[i+1])) {
            a[i]+=a[i+1];
            res.erase(i+1);
        }
    }
    oparr(a)
    set<pii> s;
    for(int x:res) s.insert({abs(a[x]),x});
    for(int i=n-1;i>=SZ(res);i--) an.pb(an.back());
    ope(s.begin()->f)
    oparr(a)
    int ccc=0;
    while(res.size()) {
        // if(ccc++>5) break;
        auto [v,id]=*s.begin();
        op(v)ope(id)
        auto it=res.lower_bound(id);
        int now=an.back();
        if(it==res.begin()||it==prev(res.end())) {
            an.pb(now-v);
            s.erase({abs(a[id]),id});
            res.erase(res.find(id));
            continue;
        }
        an.pb(now-v);
        an.pb(now-v*2);
        if(next(it)!=res.end()) {
            ope("ok1")
            s.erase({abs(a[*next(it)]),*next(it)});
            s.erase({abs(a[id]),id});
            a[id]+=a[*next(it)];
            s.insert({abs(a[id]),id});
            res.erase(next(it));
            oparr(a)
        }
        if(it!=res.begin()) {
            ope("ok2")
            s.erase({abs(a[*prev(it)]),*prev(it)});
            s.erase({abs(a[id]),id});
            a[*prev(it)]+=a[id];
            s.insert({abs(a[*prev(it)]),*prev(it)});
            res.erase(it);
        }
    }
    oparr(an)
    Vi ans(m);
    REP(i,m) {
        if(n-q[i]>=SZ(an)){ans[i]=0;}else {ans[i]=an[n-q[i]];}
    }
    return ans;
}

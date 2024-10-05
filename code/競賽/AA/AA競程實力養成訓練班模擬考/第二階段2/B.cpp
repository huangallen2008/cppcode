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
#define pdd pair<ld,ld>
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
const int maxv=31700;
const int inf=(1ll<<30);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
pii to(pii a,pii b) { return {b.f-a.f,b.s-a.s}; }
pii add(pii a,pii b) { return {a.f+b.f,a.s+b.s}; }
pii mul(pii a,int b) { return {a.f*b,a.s*b}; }
int cro(pii a,pii b) { return a.f*b.s-a.s*b.f; }
pii dot(pii a,pii b) { return {a.f*b.f,a.s*b.s}; }
int sig(int x) { if(x==0) return 0;if(x<0) return -1; else return 1; }
bool opp(pii x,pii y,pii a,pii b) {
    return sig(cro(to(x,y),to(x,a)))*sig(cro(to(x,y),to(x,b)))<=0;
}
bool inter(pii o,pii op,pii a,pii b) { 
    return opp(o,op,a,b)&&opp(a,b,o,op);
}
bool fuck(pii a,pii b) {
    // op(a.f)op(b.f)ope(a.f==b.f)
    return a.f==b.f;
}
pdd lin(pii a,pii b) {
    return {(ld)(a.s-b.s)/(a.f-b.f),(ld)a.s-a.f*((ld)(a.s-b.s)/(a.f-b.f))};
}
pdd ohyes={inf,inf};
pdd ohno={-inf,-inf};
pdd lin_inter_p(pdd a,pdd b) {
    if(a.f==b.f) return a.s==b.s?ohyes:ohno;
    pdd ret= {(b.s-a.s)/(a.f-b.f),a.f*(b.s-a.s)/(a.f-b.f)+a.s};
    return ret;
}
ld val(pdd l,ld x) {
    return x*l.f+l.s;
}
bool owo=0;
pdd inter_p(pii o,pii op,pii a,pii b) {
    if(fuck(o,op)) {
        if(fuck(a,b)) {
            if(a.f!=o.f||((o.s<op.s?o.s>b.s:o.s<a.s))) return ohno;
            else return {b.f,o.s>op.s?b.s:a.s};
        }
        else {
            // pdd rr=lin(a,b);
            // op(rr.f)ope(rr.s)
            // ope(val(rr,o.f))
            return {o.f,val(lin(a,b),o.f)};
        }
    }
    else {
        if(fuck(a,b)) {
            // ope("owo")
            return {a.f,val(lin(o,op),a.f)};
        }
        else {
            // ope("RRR")
            pdd ret=lin_inter_p(lin(o,op),lin(a,b));
            // cout<<lin(o,op).f<<' '<<lin(o,op).s<<'\n';
            // cout<<lin(a,b).f<<' '<<lin(a,b).s<<'\n';
            if(ret==ohyes) {
                if(o.f>op.f&&o.f<a.f) return ohno;
                if(o.f<op.f&&o.f>b.f) return ohno;
                // if(o.f==op.f)assert(0);
                // ope("oko")
                owo=1;
                return o.f>op.f?b:a;
            }
            return ret;
        }
    }
}
pii O={0,0};
ld dis(pdd a,pdd b) { return (ld)sqrtf((ld)SQ(a.f-b.f)+SQ(a.s-b.s)); }
void solve() {
    owo=0;
    pii o,v,a,b;
    auto inp=[&](pii&x) {
        cin>>x.f>>x.s;
    };
    inp(o),inp(v),inp(a),inp(b);
    pii op=add(o,mul(v,25));
    if(a.f>b.f) swap(a,b);
    else if(a.f==b.f&&a.s>b.s) swap(a,b); 
    // op(a.f)ope(a.s)
    if(!inter(o,op,a,b)) cout<<"-1\n";
    else {
        // cout<<"owo\n";
        pdd r=inter_p(o,op,a,b);
        // cout<<fixed<<setprecision(10)<<r.f<<' '<<r.s<<'\n';
        if(r==ohno) cout<<"-1\n";
        else {
            // ld t1=dis(r,o),t2=dis(O,v);
            // cout<<fixed<<setprecision(10)<<t1<<' '<<t2<<'\n'; 
            ld an=dis(r,o)/dis(O,v);
            if(owo) {
                chmin(an,dis(o,a)/dis(O,v));
                chmin(an,dis(o,b)/dis(O,v));
                // assert(0);
            }
            cout<<fixed<<setprecision(20)<<an<<'\n'; 
        }
    }
    // entr 
}
signed main() {
    IOS();
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}
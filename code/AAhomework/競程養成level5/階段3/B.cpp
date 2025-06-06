#include<bits/stdc++.h>
using namespace std;
// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,sse4,bmi2,popcnt")
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
#define Vpii vector<pii>
#ifdef LOCAL
#define op(x) cout<<(#x)<<"="<<(x)<<", ";
#define ope(x) cout<<(#x)<<"="<<(x)<<endl;
#define oparr(x) {cout<<(#x)<<":";for(auto allen:(x)) cout<<allen<<" ";cout<<" size="<<(x).size()<<endl;}
#define entr cout<<endl;
#else
#define op(x) ;
#define ope(x) ;
#define oparr(x) ;
#define entr ;
#endif
template<typename T1,typename T2>
ostream& operator<<(ostream& os,pair<T1,T2> p) { return os<<'{'<<p.f<<','<<p.s<<'}'; }
template<typename T1,typename T2>
istream& operator>>(istream& os,pair<T1,T2> &p) { return os>>p.f>>p.s; }
template<typename S>
ostream& operator<<(ostream& os,vector<S> p) { for(auto allen:p) os<<allen<<' ';return os<<'\n'; }
template<typename S>
istream& operator>>(istream& os,vector<S> &p) { for(auto &allen:p) os>>allen;return os; }
const int mod=998244353;
const int maxn=5;
const int maxv=200;
const int inf=1e9;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
const ld eps=1e-12;
struct po{
    ld x,y;
    po(){}
    po(pdd p) { x=p.f,y=p.s; }
    po(ld f,ld s) { x=f,y=s; }
    po operator-(po b) { return {x-b.x,y-b.y}; }
    po operator+(po b) { return {x+b.x,y+b.y}; }
    po operator*(ld r) { return {x*r,y*r}; }
    po operator/(ld r) { return {x/r,y/r}; }
    bool operator==(po b) { return fabs(x-b.x)<eps&&fabs(y-b.y)<eps; }
    bool operator!=(po b) { return !(b==*this); }
};
const po infin={inf,inf};
const po noin={-inf,-inf};
istream& operator>>(istream& os,po &p) { return os>>p.x>>p.y; }
ostream& operator<<(ostream& os,po p) { return os<<"{"<<p.x<<","<<p.y<<"}"; }
po to(po a,po b) { return b-a; }
ld sig(ld x) { if(x<0) return -1;if(x>0) return 1; return 0; }
ld dot(po a,po b) { return a.x*b.x+a.y*b.y; }
ld cro(po a,po b) { return a.x*b.y-a.y*b.x; }
po inter_po(po a,po b,po c,po d) {
    ld x=cro(c-a,d-a),y=cro(d-b,c-b);
    if(fabs(x)<eps&&fabs(y)<eps) return infin;
    if(fabs(x+y)<eps) return noin;
    return (a*y+b*x)/(x+y);
}

signed main() {
    IOS();
    po a[3],b[3];
    REP(i,3) cin>>a[i];
    REP(i,3) cin>>b[i];
    auto diff=[&](po v) {
        REP(i,3) if(v==a[i]) return 0; 
        REP(i,3) if(v==b[i]) return 0; 
        return 1;
    };
    // if(cro(a[1]-a[0],a[2]-a[0])==0||cro(b[1]-b[0],b[2]-b[0])==0) {
    //     cout<<"0\n";
    //     return 0;
    // }
    vector<po> an;
    REP(i,3) {
        REP(j,3) {
            po p1=a[i],v1=a[(i+2)%3]-a[(i+1)%3];
            po p2=b[j],v2=b[(j+2)%3]-b[(j+1)%3];
            po ret=inter_po(p1-v1*maxv,p1+v1*maxv,p2-v2*maxv,p2+v2*maxv);
            if(ret==infin) {
                cout<<"infinite\n";
                return 0;
            }
            if(ret!=noin&&diff(ret)) an.pb(ret);
        }
    }
    sort(ALL(an),[&](po a,po b){
        return fabs(a.x-b.x)<eps?a.y<b.y:a.x<b.x;
    });
    vector<po> ans;
    REP(i,an.size()) {
        if(i&&an[i]==an[i-1]) continue;
        ans.pb(an[i]);
    }
    cout<<fixed<<setprecision(15);
    cout<<ans.size()<<'\n';
    for(auto v:ans) cout<<v.x<<' '<<v.y<<'\n';
    return 0;
}
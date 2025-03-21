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
#define SZ(x) ((int)((x).size()))
#define SQ(x) ((x)*(x))
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
template<typename T1,typename T2>
pair<T1,T2> operator+(pair<T1,T2> p1,pair<T1,T2> p2) { return pair<T1,T2>(p1.f+p2.f,p1.s+p2.s); }
const int mod=998244353;
const int maxn=2e5+5;
const int maxv=2e5+5;
const int inf=1ll<<60;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
#ifdef LOCAL
int mn,mx;
int qur(Vi a,Vi b) {
    int s1=0,s2=0;
    auto cost=[&](int id) { return id==mn?1:(id==mx?3:2); };
    for(int x:a) s1+=cost(x);
    for(int x:b) s2+=cost(x);
    if(s1>s2) return 1;
    else if(s1<s2) return -1;
    else return 0;
}
void ans(int a,int b) {
    if(a==mn&&b==mx) cout<<"AC"<<endl;
    else cout<<"WA"<<endl;
    exit(0);
}
#else 
int qur(Vi a,Vi b) {
    oparr(a)oparr(b)entr
    cout<<"Q "<<SZ(a)<<' '<<SZ(b)<<' ';
    for(int x:a) cout<<x<<' ';
    for(int x:b) cout<<x<<' ';
    cout<<'\n'<<flush;
    int ret;
    cin>>ret;
    return ret;
}
void ans(int a,int b) {
    cout<<"A "<<a<<' '<<b<<'\n'<<flush;
    exit(0);
}
#endif
int sol(Vi a,bool big) {
    // oparr(a)
    if(SZ(a)==1) return a[0]; 
    // if(SZ(a)==2) {
    //     return qur({a[0]},{a[1]})==big?a[1]:a[0]; 
    // }
    Vi v0,v1,v2;
    int n=a.size();
    int nn=(n+1)/3;
    REP(i,n) {
        if(i<nn) v0.pb(a[i]);
        else if(i<nn*2) v1.pb(a[i]);
        else v2.pb(a[i]); 
    }
    int ret=qur(v0,v1);
    if(ret==0) return sol(v2,big);
    else if(big?ret==-1:ret==1) return sol(v1,big);
    else return sol(v0,big);
}
void solve() {
    int n;
    #ifdef LOCAL
    n=rd(10,100);
    mn=rd(1,n);
    while((mx=rd(1,n))==mn);
    op(mn)ope(mx)
    #else
    cin>>n;
    #endif
    if(n&1) {
        int r1=qur({1},{2});
        if(r1!=0) {
            int r2=qur({1},{3});
            if(r1==-1&&r2==1) {
                ans(3,2);
            }else if(r1==1&&r2==-1) {
                ans(2,3);
            }else if(r1==1&&r2==1) {
                Vi id;
                REP1(i,n) if(i!=1) id.pb(i);
                ans(sol(id,0),1);
            }else if(r1==-1&&r2==-1) {
                Vi id;
                REP1(i,n) if(i!=1) id.pb(i);
                ans(1,sol(id,1));
            }
            // else {
            //     int r3=qur({2},{3});
            //     if(r1==-1&&r3==-1) {
            //         ans(1,3);
            //     }else if(r1==1&&r2==1) {
            //         ans(3,1);
            //     }else if(r1==-1&&r2==1) {
            //         Vi id;
            //         REP1(i,n) if(i!=2) id.pb(i);
            //         ans(solve(id,0),2);
            //     }else if(r1==1&&r2==-1) {
            //         Vi id;
            //         REP1(i,n) if(i!=2) id.pb(i);
            //         ans(1,solve(id,2));
            //     }
            // }
        }
    }
    Vi id;
    for(int i=(n&1)+1;i<=n;i++) id.pb(i);
    int cnt=0;
    while(1) {
        shuffle(ALL(id),rng);
        int nn=n/2;
        Vi v1,v2;
        REP(i,n) {
            if(i<nn) v1.pb(id[i]);
            else v2.pb(id[i]);
        }
        int ret=qur(v1,v2);
        cnt++;
        if(cnt>11) {

        }
        assert(cnt<=11);
        if(ret==0) continue;
        if(ret==-1) ans(sol(v1,0),sol(v2,1));
        if(ret==1) ans(sol(v2,0),sol(v1,1));
    }
}
signed main() {
    IOS();
    int T=10;
    // cin>>T;
    while(T--)solve();
    return 0;
}

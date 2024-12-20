#include<bits/stdc++.h>
// #include "checker.cpp"
using namespace std;
// #pragma GCC optimize("O3,unroll-loops,fast-math")
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
#define oparr(x) cout<<(#x)<<":";for(auto allen:(x)) cout<<allen<<" ";cout<<" size="<<(x).size()<<endl;
#define entr cout<<endl;
#else
#define op(x) ;
#define ope(x) ;
#define oparr(x) ;
#define entr ;
#endif
template<typename T1,typename T2>
ostream& operator<<(ostream& os,pair<T1,T2> p) { return os<<'{'<<p.f<<','<<p.s<<'}'; }
const int mod=1e9+7;
const int maxn=5;
const int maxb=20;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}

    int n,m;
vector<Vi> a;
int query(int x,int y) {
    return a[x-1][y-1];
}
void answer(int x,int y) {
    x--,y--;
    if((x==0||a[x-1][y]>a[x][y])&&(x==n-1||a[x+1][y]>a[x][y])&&(y==0||a[x][y-1]>a[x][y])&&(y==m-1||a[x][y+1]>a[x][y])) cout<<"AC"<<endl;
    else cout<<"WA\n";
}
signed main() {
    IOS();
    cin>>n>>m;
    Vi arr(n*m);
    REP(i,n) arr[i]=i+1;
    shuffle(ALL(arr),rng);
    a=vector<Vi> (n,Vi(m));
    REP(i,n) REP(j,m) a[i][j]=arr[i*m+j];
    run(n,m);
    return 0;
}

int qur(int a,int b) {
    return query(a,b);
    // cout<<"? "<<a<<' '<<b<<'\n'<<flush;
    // int res;
    // cin>>res;
    // return res;
}
void ans(int a1,int a2) {
    answer(a1,a2);
    // cout<<"! "<<a1<<' '<<a2<<'\n'<<flush;
}
void f(int l1,int r1,int l2,int r2) {
    if(l1==r1&&l2==r2) {
        ans(l1,l2);
        exit(0);
    }
    int m1=l1+r1>>1;
    int mn1=inf,id1=0;
    for(int i=l2;i<=r2;i++) {
        int ret=qur(m1,i);
        if(ret<mn1) {
            mn1=ret;
            id1=i;
        }
    }
    int rr;
    if(m1!=l1&&(rr=qur(m1-1,id1))<mn1) {
        int m2=l2+r2>>1;
        int mn2=inf,id2=0;
        for(int i=l1;i<=m1-1;i++) {
            int ret=qur(i,m2);
            if(ret<mn2) {
                mn2=ret;
                id2=i;
            }
        }
        if(mn2<rr) {
            if(m2!=l2&&qur(id2,m2-1)<mn2) {
                f(l1,m1-1,l2,m2-1);
            }else if(m2!=r2&&qur(id2,m2+1)<mn2) {
                f(l1,m1-1,m2+1,r2);
            }else {
                ans(id2,m2);
                exit(0);
            }
        }else {
            if(id1<m2) {
                f(l1,m1-1,l2,m2-1);
            }else {
                f(l1,m1-1,m2+1,r2);
            }
        }
    }else if(m1!=r1&&(rr=qur(m1+1,id1))<mn1){
        int m2=l2+r2>>1;
        int mn2=inf,id2=0;
        for(int i=m1+1;i<=r1;i++) {
            int ret=qur(i,m2);
            if(ret<mn2) {
                mn2=ret;
                id2=i;
            }
        }
        if(mn2<rr) {
            if(m2!=l2&&qur(id2,m2-1)<mn2) {
                f(m1+1,r1,l2,m2-1);
            }else if(m2!=r2&&qur(id2,m2+1)<mn2) {
                f(m1+1,r1,m2+1,r2);
            }else {
                ans(id2,m2);
                exit(0);
            }
        }else {
            if(id1<m2) {
                f(m1+1,r1,l2,m2-1);
            }else {
                f(m1+1,r1,m2+1,r2);
            }
        }
    }else {
        ans(m1,id1);
        exit(0);
    }
}
void run(int n,int m) {
    f(1,n,1,m);
}
// signed main() {
//     IOS();
//     int n,m;
//     cin>>n>>m;
//     f(1,n,1,m);
//     return 0;
// }
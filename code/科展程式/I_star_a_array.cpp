#include<bits/stdc++.h>
using namespace std;
//#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC optimize("O3,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("avx2,popcnt")
#define int long long
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
#define RREP(i,n) for(int i=(n)-1;i>=0;i--)
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
#define op(x) cout<<(#x)<<"="<<x<<", ";
#define ope(x) cout<<(#x)<<"="<<x<<endl;
#define oparr(x) cout<<(#x)<<":";REP(i,x.size()) cout<<x[i]<<" ";cout<<" size="<<x.size()<<endl;
#define entr cout<<endl;
#define ld long double
const int inf=(1ll<<62);
const int maxn=1e5+5;
const int mod=1e9+7;
int f(int n) {
//    int k=sqrt(n*2);
//    if(n<=k*(k+1)/2) return 2+n+k-1;
//    else return 2+n+k;
    int r=n+(sqrt((ld)(n*2))+(ld)0.5)+1;
//    op(n)ope(r)
    return r;
}
vector<int> solve(int l) {
    // ope(l)
    vector<int> a;
    int aid=1;
    int rest=0;
    int n=0;
    for(int i=1;i<=l+1;i++) {
        if(i*(i+1)/2<=l) {
            a.pb(i);
        }
        else {
            rest=i*(i+1)/2-l;
            n=i;
            break;
        }
    }
//    ope(aid)
    while(1) {
        n++;
        int nrest=f(rest);
        if(nrest-rest>=l) {
            a.pb(inf);
            break;
        }
        else rest=nrest-l;
        if(rest<=0) {
            rest+=n*(n+1)/2;
            a.pb(n);
        }
    }
    // REP1(i,a.size()-1) {
    //     if(a[i]==inf) cout<<"a["<<i<<"] = inf"<<endl;
    //     else cout<<"a["<<i<<"] = "<<a[i]<<"\n";
    // }
    // entr
    return a;
}
signed main() {
    IOS();
    freopen("I_star_a_array_output.txt","w",stdout);
//    REP1(i,20) {
//        op(i) ope(f(i))
//    }
    int l=1;
    vector<vector<int>> g;
//    while(cin>>l) {
    REP1(l,10000){
        g.pb(solve(l));
    }
    REP(i,g.size()) {
        cout<<setfill(' ')<<setw(5)<<i+1<<": ";
        REP(j,g[i].size()) {
            if(g[i][j]==inf) cout<<setw(5)<<"x"<<"\n";
            else cout<<setw(5)<<g[i][j]<<' ';
        }
    }
    return 0;
}

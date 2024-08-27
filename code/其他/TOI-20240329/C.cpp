#include<bits/stdc++.h>
using namespace std;
//#pragma GCC optimize("O3,unroll-loops,fast-math")
//#pragma GCC target("avx2,popcnt")
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
#define MD(x,M) (((x)%(M)+(M))%(M))
#define ld long double
#define pdd pair<ld,ld>
#ifdef LOCAL
#define op(x) cout<<(#x)<<"="<<(x)<<", ";
#define ope(x) cout<<(#x)<<"="<<(x)<<endl;
#define oparr(x) cout<<(#x)<<":";REP(allen,(x).size()) cout<<x[allen]<<" ";cout<<" size="<<(x).size()<<endl;
#define entr cout<<endl;
#else
#define op(x) ;
#define ope(x) ;
#define oparr(x) ;
#define entr ;
#endif
const int mod=1e9+7;
const int maxn=255;
const int maxv=1e3+5;
const int maxs=1e6;
const int inf=(1ll<<60);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
void solve(int cnt) {
    string st;
    getline(cin,st);
    getline(cin,st);
    stringstream ss;
    ss<<st;
    int n,h;
    ss>>n;ss>>h;
    vector<vector<int>> m(n+1,vector<int>(h+1));
    REP(i,n) {
        string s;
        getline(cin,s);
        stringstream ss;
        ss<<s;
        int k,u;
        bool fir=1;
        while(ss>>k) {
            if(fir) {
                u=k;
                fir=0;
            }
            else {
                m[u][k]=-1;
            }
        }
    }
    m[1][1]=1;
    REP1(i,n) {
        REP1(j,h) {
            if(m[i][j]!=-1) {
                if(m[i][j-1]!=-1) m[i][j]+=m[i][j-1];
                if(m[i-1][j]!=-1) m[i][j]+=m[i-1][j];
            }
        }
    }
    cout<<m[n][h]<<(cnt>0?"\n\n":"\n");
}
signed main() {
    IOS();
    int T;
    string st;
    getline(cin,st);
    T=stoi(st);
    while(T--) solve(T);
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops")
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
#define oparr(x) cout<<(#x)<<":";REP(i,(x).size()) cout<<x[i]<<" ";cout<<" size="<<(x).size()<<endl;
#define entr cout<<endl;
#else
#define op(x) ;
#define ope(x) ;
#define oparr(x) ;
#define entr ;
#endif
const int mod=1e9+7;
const int maxn=2e5+5;
const int maxv=1e5+5;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
int n,d;
int stoll(string &s) {
    int r=0;
    REP(i,s.size()) {
        r=r*10+s[i]+'0';
    }
    return r;
}
string lltos(int k) {
    string s="";
    while(k>0) {
        s+='0'+k%10;
        k/=10;
    }
    while(s.size()<d) s+='0';
    reverse(ALL(s));
    return s;
}
int chan(int k) {
    string s=lltos(k);
    string sm=s,bi;
    sort(ALL(sm));
    bi=sm;
    reverse(ALL(bi));
    return stoll(bi)-stoll(sm);
}
void solve() {
    int k;
    cin>>k;
    map<int,bool> mp;
    while(1) {
        if(mp[k]) {
            cout<<k<<'\n';
            return ;
        }
        mp[k]=1;
        k=chan(k);
    }
}
signed main() {
    IOS();
    cin>>n>>d;
    while(n--) solve();
    return 0;
}

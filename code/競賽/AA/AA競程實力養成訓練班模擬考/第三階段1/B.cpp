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
const int maxn=2000+5;
const int maxb=20;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
string operator^(string a,string b) {
    REP(i,b.size()) if(b[i]=='1') a[i]^=1;
    return a;
}
string x000;
#define Vs vector<string>
int n,l,q;
int nn;
int cnt[maxn];
int ch[maxn][2];
// int swp[maxn];
// vector<string> swp;
string swp;
int node_id=2;
void ins(string s,int v) {
    int u=1;
    REP(i,l) {
        int c=(s[i]-'0')^(swp[i]^'0');
        if(!ch[u][c]) ch[u][c]=node_id++;
        u=ch[u][c];
        cnt[u]+=v;
    }
}
void rev(string s) {
    // swp[1]=swp[1]^s;
    swp=swp^s;
}
string med() {
    int u=1;
    int k=nn;
    string an;
    REP(i,l) {
        int c0=swp[i]^'0';
        op(i)op(an)op(c0)op(cnt[ch[u][c0]])ope(k)
        if(cnt[ch[u][c0]]>=k) {
            u=ch[u][c0];
            an+='0';
        }
        else {
            k-=cnt[ch[u][c0]];
            u=ch[u][c0^1];
            an+='1';
        }
    }
    return an;
}
signed main() {
    IOS(); 
    cin>>n>>l>>q;
    nn=(n>>1)+1;
    REP(i,l) x000+='0';
    swp=x000;
    // swp=Vs(n,x000);
    Vs a(n);
    REP(i,n) cin>>a[i];
    REP(i,n) ins(a[i],1);
    cout<<med()<<'\n';
    while(q--) {
        int u;
        cin>>u,u--;
        string s=a[u];
        rev(s);
        ins(s,1);
        ins(x000,-1);
        cout<<med()<<'\n';
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops,fast-math")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
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
#define Graphw vector<vector<pii>>
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
const int maxn=2e5+5;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
int tran(char c) {
    if(isdigit(c)) return c-'0';
    if(islower(c)) return c-'a'+10;
    return c-'A'+36;
}
char revt(int x) {
    if(x<10) return '0'+x;
    if(x<36) return 'a'+x-10;
    return x-36+'A';
}
int preid(string s) {
    return tran(s[0])*62+tran(s[1]);
}
int sufid(string s) {
    return tran(s[1])*62+tran(s[2]);
}
vector<int> cur(4000);
bitset<maxn> vis;
Graphw g(4000);
vector<int> an;
void dfs(int u) {
    for(;cur[u]<g[u].size();cur[u]++) {
        auto [v,id]=g[u][cur[u]];
        if(vis[id]) continue;
        vis[id]=1;
        dfs(v);
    }
    an.pb(u);
}
signed main() {
    IOS();
    int n;
    cin>>n;
    int last=0;
    vector<int> ind(4000),oud(4000);
    REP(i,n) {
        string s;
        cin>>s;
        int u=preid(s),v=sufid(s);
        g[u].pb({v,i});
        last=u;
        ind[v]++,oud[u]++;
    }
    int st=-1,en=-1;
    REP(i,4000) {
        if(ind[i]>oud[i]+1||oud[i]>ind[i]+1) {
            cout<<"NO\n";
            return 0;
        }
        if(ind[i]==oud[i]+1) {
            if(en!=-1) {
                cout<<"NO\n";return 0;
            }
            en=i;
        }
        if(ind[i]+1==oud[i]) {
            if(st!=-1) {
                cout<<"NO\n";return 0;
            }
            st=i;
        }
    }
    if(st==-1) st=last;
    dfs(st);
    if(an.size()<=n) {
        cout<<"NO\n";
        return 0;
    }
    reverse(ALL(an));
    cout<<"YES\n";
    cout<<revt(an[0]/62);
    for(int x:an) cout<<revt(x%62);
    cout<<'\n';
    return 0;
}
/*
2
aba
aba
*/
#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops,fast-math")
// #pragma GCC target("avx2,bmi,popcnt")
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
#ifdef LOCAL_
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
vector<int> pw26(10);
// struct chash {
//     chash(string s) {
//         int ret=0;
//         REP(i,s.size()) ret+=pw26[i]*(s[i]-'a');
//         return ret;
//     }
// };
Graphw g;
bitset<maxn> vis;
vector<int> cur(maxn);
vector<int> an;
void dfs(int u) {
    ope(u)
    for(;cur[u]<g[u].size();cur[u]++) {
        auto [v,id]=g[u][cur[u]];
        if(vis[id]) continue;
        vis[id]=1;
        dfs(v);
    }
        an.pb(u);
}
    vector<string> gst={""};
    bool so(pii a,pii b) {
        return gst[a.f]<gst[b.f];
    }
signed main() {
    IOS();
    pw26[0]=1;REP1(i,9) pw26[i]=pw26[i-1]*26;
    int node_id=1,edge_id=0;
    int n,k;
    cin>>n>>k;n-=k-1;
    if(k==1) {
        string s="";
        REP(i,n) {
            char c;
            cin>>c;
            s+=c;
        }
        sort(ALL(s));
        cout<<s<<'\n';
        return 0;
    }
    vector<string> s(n);
    REP(i,n) cin>>s[i];
    string mns;
    REP(i,k) mns+=('z'+1);
    unordered_map<string,int> mp;
    REP(i,n) {
        string s1=s[i].substr(1,k-1),s2=s[i];s2.pop_back();
        mns=min({mns,s1,s2});
        if(mp[s1]==0) gst.pb(s1),mp[s1]=node_id++;
        if(mp[s2]==0) gst.pb(s2),mp[s2]=node_id++;
    } 
    ope("OK")
    g=Graphw(node_id);
    REP(i,n) {
        string s1=s[i].substr(1,k-1),s2=s[i];s2.pop_back();
        g[mp[s2]].pb({mp[s1],edge_id++});
    } 
    REP(i,node_id) sort(ALL(g[i]),so);
    vector<int> ind(node_id);
    REP(i,node_id) for(auto [v,id]:g[i]) ind[v]++;
    int st=0;
    oparr(ind)
    // REP(i,node_id) {
    //     op(i)
    //     for(auto [x,id]:g[i]) cout<<x<<' ';entr
    // }
    oparr(gst)
    entr
    REP(i,node_id) {
        if(ind[i]==g[i].size()-1) st=i;
    }
    if(st==0) st=mp[mns];
    dfs(st);
    reverse(ALL(an));
    // string ans="";
    // REP(i,n) ans+=gst[an[i]][0];
    // ans+=gst[an[n]];
    REP(i,n) cout<<gst[an[i]][0];
    cout<<gst[an[n]]<<'\n';;
    // reverse(ALL(ans));
    // cout<<ans<<'\n';
    return 0;
}

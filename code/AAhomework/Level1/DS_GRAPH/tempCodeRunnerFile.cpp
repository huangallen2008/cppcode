#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops,fast-math")
#pragma GCC target("avx2,bmi,popcnt")
// #define int long long
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
#define IOS() ios::sync_with_stdio(0),cin.tie(0)
#define md(x) (((x)%(mod)+(mod))%(mod))
#define MD(x,M) (((x)%(M)+(M))%(M))
#define ld long double
#define pdd pair<ld,ld>
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)
#define addmod(x,y) x=((x+(y))%mod)
#define end eend
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
const int mod=998244353;
const int maxn=1.5e5+5;
const int maxq=5e5+5;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
#define GU _getchar_nolock()
int in() {
    int x=0;
    char ch=GU;
    if(ch==EOF) exit(0);
    while(ch==' '||ch=='\n') ch=GU;
    while(ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=GU;
    return x;
}
void read(int &x){ char ch = getchar();x = 0; for (; ch < '0' || ch > '9'; ch = getchar()); for (; ch >='0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0'; }
int fir[maxn],end[maxn],nxt[maxq],las[maxq],v[maxq];
bool inv[maxq];
int cnt_id=0;
int& next(int &id) {
    return inv[id]?las[id]:nxt[id];
}
int& prev(int &id) {
    return inv[id]?nxt[id]:las[id];
}
void move_nxt(int &x) {
    inv[next(x)]=inv[x];
    if(inv[x]?las[las[x]]==x:nxt[nxt[x]]==x) inv[next(x)]^=1;
    x=next(x);
}
void move_pre(int &x) {
    inv[prev(x)]=inv[x];
    if(inv[x]?nxt[nxt[x]]==x:las[las[x]]==x) inv[prev(x)]^=1;
    x=prev(x);
}
void pushb(int u,int val) {
    if(fir[u]==-1) {
        fir[u]=cnt_id;
        end[u]=cnt_id;
        next(cnt_id)=cnt_id;
        prev(cnt_id)=cnt_id;
    }
    else {
        next(end[u])=cnt_id;
        prev(cnt_id)=end[u];
        move_nxt(end[u]);
    }
    v[cnt_id++]=val;
}
void pushf(int u,int val) {
    if(fir[u]==-1) {
        fir[u]=cnt_id;
        end[u]=cnt_id;
        next(cnt_id)=cnt_id;
        prev(cnt_id)=cnt_id;
    }
    else {
        prev(fir[u])=cnt_id;
        next(cnt_id)=fir[u];
        move_pre(fir[u]);
    }
    v[cnt_id++]=val;
}
void popb(int u) {
    if(end[u]==-1) {
        cout<<"-1"<<'\n';
        return;
    }
    cout<<v[end[u]]<<'\n';
    if(fir[u]==end[u]) {
        fir[u]=end[u]=-1;
        return;
    }
    move_pre(end[u]);
    next(end[u])=u;
}
void popf(int u) {
    if(fir[u]==-1) {
        cout<<"-1"<<'\n';
        return;
    }
    cout<<v[fir[u]]<<'\n';
    if(fir[u]==end[u]) {
        fir[u]=end[u]=-1;
        return;
    }
    move_nxt(fir[u]);
    prev(fir[u])=u;
}
void dreverse(int u) {
    swap(inv[fir[u]],inv[end[u]]);
    swap(fir[u],end[u]);
    inv[fir[u]]^=1,inv[end[u]]^=1;
}
void move_to(int u,int v) {
    if(fir[v]==-1) return;
    if(fir[u]==-1) {
        swap(fir[u],fir[v]),swap(end[u],end[v]);
        return;
    }
    next(end[u])=fir[v];
    prev(fir[v])=end[u];
    end[u]=end[v];
    fir[v]=end[v]=-1;
}
void output(int u) {
    op(u)
    if(fir[u]==-1) {
        cout<<"-1\n";
        return ;
    }
    int now=fir[u];
    while(now!=end[u]) {
        cout<<v[now]<<' ';
        now=next(now);
    }
    cout<<v[end[u]]<<endl;
}
signed main() {
    IOS();
    int n,q;
    while(1) {
        n=in(),q=in();
        cnt_id=0;
        REP(i,n+1) fir[i]=end[i]=-1;
        REP(i,q+1) nxt[i]=i,las[i]=i,inv[i]=0;
        while(q--) {
            int opt=in();
            if(opt==1) {
                // int u,w,val;
                int u=in(),w=in(),val=in();
                if(w) pushb(u,val);
                else pushf(u,val);
            }
            if(opt==2) {
                // int u,w;
                int u=in(),w=in();
                if(w) popb(u);
                else popf(u);
            }
            if(opt==3) {
                // int u,v,w;
                int u=in(),v=in(),w=in();
                if(w) dreverse(v);
                move_to(u,v);
            }
        }
    }
    return 0;
}

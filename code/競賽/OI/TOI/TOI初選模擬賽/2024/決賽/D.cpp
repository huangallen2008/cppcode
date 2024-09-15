#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
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
const int maxn=1e5+5;
const int maxv=(1ll<<30);
const int high_bit=30;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
//shuffle(a,a+n,rng)
int n;
vector<int> a,p;
int nxt[maxn<<5][2];
int cnt[maxn<<5];
int node_id=1;
bool get_bit(int v,int x) {
    return (v>>x)&1;
}
void ins(int v) {
    int w=0;
    RREP(i,high_bit) {
        bool b=get_bit(v,i);
        if(!nxt[w][b]) nxt[w][b]=node_id++;
        w=nxt[w][b];
        cnt[w]++;
    }
}
ll get_rnk(int v) {
    ll an=0;
    REP(i,n+1) {
        int w=0;
        RREP(j,high_bit) {
            bool b=get_bit(v,j);
            bool t=get_bit(p[i],j);
            if(!b) {
                if(nxt[w][t^1]) an+=cnt[nxt[w][t^1]];
            }
            if(!nxt[w][t^b]) {
//                op(i)op(j)ope(w)
                break;
            }
            w=nxt[w][t^b];
        }
    }
//    op(v)ope(an)
    return an>>1;
}
int bs(ll k) {//first ret<=k-1
    int l=0,r=maxv,mid;
    while(l<r) {
        mid=l+((r-l)>>1);
        ll ret=get_rnk(mid);
//        op(k)op(l)op(r)op(mid)ope(ret)
        if(ret<=k-1) r=mid;
        else l=mid+1;
    }
    return l;
}
signed main() {
    IOS();
    memset(nxt,0,sizeof(nxt));
    memset(cnt,0,sizeof(cnt));
    cin>>n;
    a=vector<int>(n+1);
    p=vector<int>(n+1);
    REP1(i,n) cin>>a[i];
    REP1(i,n) p[i]=p[i-1]^a[i];
    REP(i,n+1) {
        ins(p[i]);
    }
//    REP(i,8) cout<<i<<":"<<get_rnk(i)<<endl;
    int q;
    cin>>q;
    REP(i,q) {
        ll k;
        cin>>k;
        int an=bs(k);
        cout<<an<<'\n';
    }
    return 0;
}

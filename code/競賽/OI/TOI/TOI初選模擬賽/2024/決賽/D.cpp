#include<bits/stdc++.h>
using namespace std;
// #pragma GCC optimize("Ofast,unroll-loops,fast-math")
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
#define ALL1(x) (x).begin()+1,(x).end()
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
const int mod=30011;
const int maxn=1e6+5;
const int maxc=26;
const int maxb=30;
const int inf=(1ll<<62); 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
int cnt[maxn];
int ch[maxn][2];
int node_id=2;
void ins(int x) {
    int u=0;
    RREP(i,maxb) {
        int c=x>>i&1;
        if(!ch[u][c]) ch[u][c]=node_id++;
        u=ch[u][c];
        cnt[u]++;
    }
}
signed main() {
    IOS();
    int n;
    cin>>n;
    Vi a(n);
    REP(i,n) cin>>a[i];
    int q;
    cin>>q;
    while(q--) {
        int k;
        cin>>k;
        int an=0;
        Vi id(n);
        RREP(i,maxb) {
            int lval=0;
            REP(j,n) {
                int c=a[j]>>i&1;
                lval+=cnt[ch[id[j]][c]];
            }
            if(lval>=k) {
                REP(j,n) {
                    int c=a[j]>>i&1;
                    id[j]=ch[id[j]][c];
                }
            }
            else {
                k-=lval;
                REP(j,n) {
                    int c=a[j]>>i&1;
                    id[j]=ch[id[j]][c^1];
                }
                an^=1<<i;
            }
        }
        cout<<an<<'\n';
    }
    return 0;
}
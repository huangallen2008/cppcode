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
#define op(x) cout<<#x<<"="<<x<<", ";
#define ope(x) cout<<#x<<"="<<x<<endl;
#define oparr(x) cout<<#x<<":";REP(i,x.size()) cout<<x[i]<<" ";cout<<" size="<<x.size()<<endl;
#define entr cout<<endl;
#else
#define op(x) ;
#define ope(x) ;
#define oparr(x) ;
#define entr ;
#endif
const int mod=1e9+7;
const int maxn=1e5+5;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
//shuffle(a,a+n,rng)
    vector<vector<bool>> v(4);
    bool isok() {
        return v[1].size()==1&&v[2].size()==1&&v[3].size()==0;
    }
    int outo(int x,int y) {
        op(x)ope(y)
        if(x!=1&&y!=1) return 1;
        if(x!=2&&y!=2) return 2;
        return 3;
    }
void solve() {
     v=vector<vector<bool>>(4);
    int ccnt=0;
    int n,P;
    cin>>n>>P;
    vector<bool> s1(n),s2(n);
    REP(i,n) {
        char c;
        cin>>c;
        s1[i]=(c=='2');
    }
    REP(i,n) {
        char c;
        cin>>c;
        s2[i]=(c=='2');
    }
    vector<int> a={s1[0]},b={s2[0]},c;
    v[1].pb(s1[0]),v[2].pb(s2[0]);
    REP(i,n-1) if(s1[i]^s1[i+1]) a.pb(s1[i+1]);
    REP(i,n-1) if(s2[i]^s2[i+1]) b.pb(s2[i+1]);
    REP(i,n-1) if(s1[i]^s1[i+1]) v[1].pb(s1[i+1]);
    REP(i,n-1) if(s2[i]^s2[i+1]) v[2].pb(s2[i+1]);
    vector<pii> an;
    while(!isok()) {
        int af=-1,bf=-1,cf=-1;
        vector<vector<int>> cnt(3);
        REP1(id,3) {
            if(v[id].size()) {
                cnt[v[id].back()].pb(id);
            }
        }
//        if(a.size()) {
//            af=a[0];
//            cnt[af].pb(1);
//        }
//        if(b.size()) {
//            bf=b[0];
//        cnt[bf].pb(2);
//        }
//        if(c.size()) {
//            cf=c[0];
//        cnt[cf].pb(3);
//        }
bool szg2=0;
        REP(co,2) {
            if(cnt[co].size()>=2) {
                int x=cnt[co][0],y=cnt[co][1];
                if(v[x].size()>v[y].size()) swap(x,y);
                if(v[x].size()==v[y].size()) {
                        int xmn=min(x,y),xmx=max(x,y);
                        op(xmn)ope(xmx)
                    if((((SZ(v[x])+SZ(v[outo(x,y)]))&1))^(xmx==3)) {
                        an.pb({xmx,xmn});
                        v[xmx].pop_back();
                    }
                    else {
                        an.pb({xmn,xmx});
                        v[xmn].pop_back();

                    }
                }
                else {
                an.pb({y,x});
                v[y].pop_back();
                }
                szg2=1;
            }
        }
        if(!szg2) {
            int p1=-1,p2=-1,p3=-1;
            REP1(p,3) {
                if(v[p].size()==0) {
                    p3=p;
                }
                else {
                    if(p1==-1) p1=p;
                    else p2=p;
                }
            }
            int x=p1,y=p2;
            if(v[x].size()>v[y].size()) swap(x,y);
            an.pb({y,p3});
            v[p3].pb(v[y].back());
            v[y].pop_back();
        }
        oparr(v[1])oparr(v[2])oparr(v[3])entr entr
        if(ccnt++>20) break;
    }

    cout<<an.size()<<'\n';
    if(P>1) for(auto &[x,y]:an) cout<<x<<' '<<y<<'\n';
//    entr
}
signed main() {
    IOS();
    int T;
    cin>>T;
    while(T--) {
        solve();
    }
    return 0;
}

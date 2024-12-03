#include<bits/stdc++.h>
using namespace std;
#define int long long
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
#define f first
#define s second
#define pii pair<int,int>
#define pb push_back
#define ALL(x) (x).begin(),(x).end()
#define SZ(x) (int)((x).size())
#define Vi vector<int>
#define IOS() ios::sync_with_stdio(0),cin.tie(0)
#ifdef LOCAL
#define op(x) cout<<(#x)<<"="<<x<<", "<<flush;
#define ope(x) cout<<(#x)<<"="<<x<<endl;
#define oparr(x) cout<<(#x)<<": ";for(auto allen:(x)) cout<<allen<<' ';cout<<"sz="<<SZ(x)<<endl;
#define entr cout<<endl;
#endif // LOCAL
const int inf=(1ll<<62);
signed main () {
    IOS();
    int n,m;
    cin>>n>>m;
    Vi w(n);
    REP(i,n) cin>>w[i];
    vector<Vi> p(m);
    Vi k(m);
    REP(i,m) {
        cin>>k[i];
        p[i]=Vi(k[i]);
        REP(j,k[i]) cin>>p[i][j],p[i][j]--;
    }
    vector<multiset<pii>> a(m);
    Vi sum(m);
    REP(i,m) {
        for(int x:p[i]) a[i].insert({w[x],x}),sum[i]+=w[x];
    }
//    oparr(sum)
    auto mnit=min_element(ALL(sum));
    int mns=*mnit,mnid=0;
    REP(i,m) if(sum[i]==mns) {
        mnid=i;
        break;
    }
    Vi an;
    REP(rr,n) {
        int nm=-inf,nmid=-1,fid=-1;
        REP(i,m) {
            if(i>mnid) {
                auto it=a[i].upper_bound({sum[i]-mns,inf});
                if(it==a[i].end()) continue;
                int val=sum[i]-it->f;
                if(val>=nm) {
                    nm=val;
                    nmid=i;
                    fid=it->s;
                }
            }else {
                auto it=a[i].lower_bound({sum[i]-mns,-inf});
                if(it==a[i].end()) continue;
                int val=sum[i]-it->f;
                if(val>=nm) {
                    nm=val;
                    nmid=i;
                    fid=it->s;
                }
                //lower
            }
        }
        if(nmid==-1) {
            cout<<"-1\n";
            return 0;
        }
//        oparr(sum)
//        op(nm)op(nmid)op(fid)op(mns)ope(mnid)
        a[nmid].erase({sum[nmid]-nm,fid});
        sum[nmid]=nm;
        an.pb(fid);
        mnid=nmid;
        mns=nm;
    }
    reverse(ALL(an));
    for(int x:an) cout<<x+1<<' ';cout<<'\n';
    return 0;
}

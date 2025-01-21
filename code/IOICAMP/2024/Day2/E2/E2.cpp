#include<bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3")
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,n) FOR(i,0,n)
#define REP1(i,n) FOR(i,1,(n)+1)
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
#define op(x) cout<<#x<<"="<<x<<", ";
#define ope(x) cout<<#x<<"="<<x<<endl;
#define oparr(x) cout<<#x<<":";REP(i,x.size()) cout<<x[i]<<" ";cout<<" size="<<x.size()<<endl;
#define entr cout<<endl;
signed main() {
    IOS();
    int n,q;
    cin>>n>>q;
    vector<int> v(n,-1),sc(n);
    REP(i,q) {
        int opt;
        cin>>opt;
        if(opt==1) {
            int l,r,x;
            cin>>l>>r>>x;
            l--,r--;
            for(int j=l;j<=r;j++) {
                if(v[j]!=-1) sc[j]+=v[j]^x;
                v[j]=x;
            }
        }
        else {
            int p;
            cin>>p;
            p--;
            cout<<sc[p]<<'\n';
        }
    }
    return 0;
}

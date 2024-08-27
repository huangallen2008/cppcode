#include<bits/stdc++.h>
using namespace std;
#define int long long
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,n) FOR(i,0,n)
#define REP1(i,n) FOR(i,1,(n)+1)
#define RREP(i,n) for(int i=(n)-1;i>=0;i--)
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
#define md(x) (x%mod+mod)%mod
#define op(x) cout<<#x<<"="<<x<<", ";
#define ope(x) cout<<#x<<"="<<x<<endl;
#define oparr(x) cout<<#x<<":";REP(i,x.size()) cout<<x[i]<<" ";cout<<" size="<<x.size()<<endl;
#define entr cout<<endl;
const int inf=(1ll<<62);
const int maxn=2e3+5;
const int mod=1e9+7;
signed main() {
    IOS();
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    int cl=0,cr=0;
    REP(i,n) {
        if(s[i]=='(') cl++;
        else cr++;
    }
    int d=abs(cl-cr);
    if(d&1) {
        cout<<"-1\n";
        return 0;
    }
    if(k*2<d) {
        cout<<"-1\n";
        return 0;
    }
    if((k-d/2)&1) {
        cout<<"-1\n";
        return 0;
    }
    //rr-ll=d/2 rr+ll=k  rr=(k+d/2)/2 ll=(k-d/2)/2
    int ll=(k+(cl-cr)/2)/2,rr=(k-(cl-cr)/2)/2;
//    op(ll)op(rr)
    int cntl=0,cntr=0;
    string ns=s;
    REP(i,n) {
        if(s[i]==')') {
            cntr++;
            if(cntr>rr) break;
            ns[i]='(';
//            op(i)
//            ope(s[i])
        }
    }
    RREP(i,n) {
        if(s[i]=='(') {
            cntl++;
            if(cntl>ll) break;
            ns[i]=')';
//            op()
        }
    }
    int p=0;
    REP(i,n) {
        if(ns[i]=='(') p++;
        else p--;
        if(p<0) {
            cout<<"-1\n";
            return 0;
        }
    }
    cout<<ns<<"\n";
    return 0;
}

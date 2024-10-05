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
const int maxn=1e5+5;
const int mod=1e9+7;
bool so(pii a,pii b) {
    return a.f>b.f;
}
signed main() {
    IOS();
    int n;
    cin>>n;
    vector<int> a(n),b(n);
    REP(i,n) cin>>a[i];
    REP(i,n) cin>>b[i];
//    REP(i,n) a[i].s=i;
//    REP(i,n) b[i].s=i;

    vector<int> dp(1<<n,inf);
    dp[0]=0;
    REP(i,1<<n) {
        if(i==0) continue;
        int yi=-1;
        REP(k,n) {
            if((i>>k)&1){
                yi=k;
                break;
            }
        }
        REP(k,n) {
            if((i>>k)&1) {
                if(k==yi) continue;
                dp[i]=min(dp[i],max(dp[i&~((1<<yi)|(1<<k))],max(a[yi],a[k])+max(b[yi],b[k])));
            }
        }
    }
    cout<<dp[(1<<n)-1]<<'\n';
//    sort(ALL(a),so);
//    sort(ALL(b),so);
//    int ai=0,bi=n-1;
//    vector<int> aid(n),bid(n);
//    REP(i,n) aid[a[i].s]=i;
//    REP(i,n) bid[b[i].s]=i;
//    vector<bool> aok(n+1),bok(n+1);
//    int an=0;
//    REP(rd,n/2) {
//        while(aok[ai]) ai++;
//        while(bok[bi]) bi--;
//        an=max(an,a[ai].f+b[bi].f);
//        aok[ai]=1,bok[bi]=1;
//        aok[aid[b[bi].s]]=1,bok[bid[a[ai].s]]=1;
//    }
//    cout<<an<<"\n";
//    cout<<"a:";REP(i,n) cout<<a[i].f<<" ";cout<<endl;
//    cout<<"b:";REP(i,n) cout<<b[i].f<<" ";cout<<endl;
    return 0;
}

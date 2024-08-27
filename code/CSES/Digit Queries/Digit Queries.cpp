#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
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
#define Graph vector<vector<int>>
#define IOS() cin.sync_with_stdio(0),cin.tie(0),cout.tie(0)
const ll inf=(1ll<<63)-1;
const int maxn=2e5+5;
const ll mod=1e9+7;
int pw(int x,int p) {
    int r=1;
    while(p>0) {
        if(p&1) r*=x;
        x*=x;
        p>>=1;
    }
    return r;
}
void solve() {
    int q;
    cin>>q;
    REP(i,q) {
        int n;
        cin>>n;
        for(int i=0;i<20;i++) {
            int r=(i+1)*9*pw(10,i);
            if(n>r) n-=r;
            else {
                int t=pw(10,i)+((n-1)/(i+1)),p=(n-1)%(i+1);
                int an=(int)(t/pw(10,i-p))%10;
                cout<<an<<"\n";
                break;
            }
        }
    }
}
signed main() {
    IOS();
    solve();
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define FOR(i,a,b) for (int i = (a); i<(b); i++)
#define REP(i,n) FOR(i,0,n)
#define REP1(i,n) FOR(i,1,n+1)
#define RREP(i,n) for (int i=(n)-1; i>=0; i--)
#define f first
#define s second
#define pb push_back
#define ALL(x) x.begin(),x.end()
const int maxn=1e5+5;
int n,r=1,r2=1;
main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin>>n;
    for(int i=2;i*i<=n;i++) {
        if(n%i==0) {
            r+=i+n/i;
            if(i*i==n) r-=i;
        }
    }
    for(int i=2;i*i<=r;i++) {
        if(r%i==0) {
            r2+=i+r/i;
            if(i*i==r) r2-=i;
        }
    }
    if(n!=r2 || n==r) cout<<"Not found\n";
    else cout<<r<<"\n";
    return 0;
}

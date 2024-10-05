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
int n,a,b;
main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin>>n>>a>>b;
    if(a>b) swap(a,b);
    if((b-a)%2==0) cout<<(b-a)/2<<"\n";
    else cout<<(min(a-1,n-b)*2+b-a+1)/2<<"\n";
    return 0;
}

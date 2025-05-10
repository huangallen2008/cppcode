#include<bits/stdc++.h>
#define int long long
#define Vi vector<int> 
#define REP(i.n) for(int i=0;i<n;i++)
signed main() {
    int n;
    cin>>n;
    Vi a(n+1); 
    REP1(i,n) cin>>a[i];
    int q;
    cin>>q;
    Vi ps(n+1);
    REP1(i,n) ps[i]=ps[i-1]+a[i];
    REP(i,q) {
        int l,r;
        cin>>l>>r;
        int v=(ps[r]-ps[l-1]+1>>1);
        
    }
    return 0;
}

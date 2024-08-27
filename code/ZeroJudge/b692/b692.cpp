#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[1000001],an=0;
bool t(int a,int b) { return a>b; }
main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n,t);
    an=a[0];
    for(int i=1;i<n;i++) {
        if(i<=(n-1)/2) an+=abs(a[i]);
        else an-=a[i];
    }
    cout<<an<<"\n";
    return 0;
}

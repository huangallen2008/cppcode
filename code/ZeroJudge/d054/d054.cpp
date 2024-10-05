#include <bits/stdc++.h>
using namespace std;
int n,x;
long long a[41];
main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    a[1]=1; a[2]=5; a[3]=11;
    for(int i=4;i<=40;i++) a[i]=a[i-1]+4*a[i-2]+2*a[i-3];
    cin>>n;
    while(n--) {
        cin>>x;
        cout<<a[x]<<"\n";
    }
    return 0;
}

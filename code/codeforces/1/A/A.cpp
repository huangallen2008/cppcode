#include<bits/stdc++.h>
using namespace std;
main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    int T,n,i;
    cin>>T;
    while(T--) {
        i=1;
        cin>>n;
        while((n&i)<=0 || (n^i)<=0) { i++; }
        cout<<i<<"\n";
    }
    return 0;
}

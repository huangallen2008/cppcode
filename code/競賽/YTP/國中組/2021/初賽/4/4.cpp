#include<bits/stdc++.h>
using namespace std;
int T,n,k;
long long m[43]={1,2,5,13,34,89,233,610,1597,4181,10946,28657,75025,196418,514229,1346269,3524578,9227465,24157817,63245986,165580141,433494437,1134903170,2971215073,7778742049,20365011074,53316291173,139583862445,365435296162,956722026041,2504730781961,6557470319842,17167680177565,44945570212853,117669030460994,308061521170129,806515533049393,2111485077978050,5527939700884757,14472334024676221,37889062373143906,98765432123456789};
main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin>>T;
    while(T--) {
        cin>>n>>k;
        if(n>56) cout<<98765432123456789<<"\n";
        else {
            if(n<k) cout<<m[min(n,41)]<<"\n";
            else {
                long long a=1,p=1;
                for(int i=1;i<=n;i++) {
                    a+=p;
                    p+=a-max(0,i-k+1);
                    if(a>98765432123456789) break;
                }
                if(a>98765432123456789) cout<<98765432123456789<<"\n";
                else cout<<a<<"\n";
            }
        }
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int T,n,a[101],b,c=0;
string s;
main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin>>T;
    while(T--) {
        cin>>n;
        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=0;i<n;i++) {
            c=0;
            cin>>b>>s;
            for(int j=0;j<b;j++) {
                if(s[j]=='D') c++;
                else c--;
            }
            cout<<(a[i]+10+c)%10<<" ";
        }
        cout<<"\n";
    }
    return 0;
}

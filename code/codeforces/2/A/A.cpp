#include<bits/stdc++.h>
using namespace std;
int n;
string s;
main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>s;
        if(tolower(s[0])!='y' || tolower(s[1])!='e' || tolower(s[2])!='s')
            cout<<"NO\n";
        else cout<<"YES\n";
    }
    return 0;
}

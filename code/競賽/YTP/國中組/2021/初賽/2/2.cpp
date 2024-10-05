#include<bits/stdc++.h>
using namespace std;
string s,t;
stringstream ss;
int n;
void f(char c) {
    if(c=='P') cout<<"Speed";
    else if(c=='S') cout<<"Technical";
    else cout<<"Power";
}
main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>t;
        f(t[0]);
        cout<<(i<n-1?' ':'\n');
    }
    return 0;
}

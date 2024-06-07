#include<bits/stdc++.h>
using namespace std;
main() {
    int n;
    cin>>n;
    while(n!=0) {
        int a[n],c=1;
        cin>>a[0];
        while(a[0]!=0) {
            c=1;
            stack<int> s;
            bool ok=true;
            for(int i=1;i<n;i++) cin>>a[i];
            for(int i=0;i<n;i++) {
                if(s.size() && s.top()==a[i]) { s.pop(); }
                else {
                    while(c<=n && c!=a[i]) { s.push(c); c++; }
                    if(c>n) {
                        cout<<"No\n";
                        ok=false;
                        break;
                    }
                    c++;
                }
            }
            if(ok) cout<<"Yes\n";
            cin>>a[0];
        }
        cout<<"\n";
        cin>>n;
    }
    return 0;
}

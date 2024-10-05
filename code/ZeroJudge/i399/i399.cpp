#include <bits/stdc++.h>
using namespace std;
int a,b,c;
main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin>>a>>b>>c;
    if(a<b) swap(a,b);
    if(b<c) swap(b,c);
    if(a<b) swap(a,b);
    if(a==b && b==c) cout<<3<<" "<<a;
    else if((a==b && b!=c) || (a!=b && b==c)) cout<<2<<" "<<a<<" "<<c;
    else  cout<<1<<" "<<a<<" "<<b<<" "<<c;
    return 0;
}

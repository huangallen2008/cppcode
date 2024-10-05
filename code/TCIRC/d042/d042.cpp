#include<bits/stdc++.h>
using namespace std;
int n,a,an;
void f(int c) {
    an+=a/c;
    a%=c;
}
main()
{
    cin>>n;
    for(int i=0;i<n;i++) {
        an=0;
        cin>>a;
        f(50); f(10); f(5); an+=a;
        cout<<an<<"\n";
    }
    return 0;
}

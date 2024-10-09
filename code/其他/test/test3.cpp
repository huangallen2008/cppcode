#include<bits/stdc++.h>
using namespace std;
template<int T> int c=(T==0?1:0)+c<max(T-1,0)>+c<max(T-2,0)>);
main() {
    cout<<c<3>;
}